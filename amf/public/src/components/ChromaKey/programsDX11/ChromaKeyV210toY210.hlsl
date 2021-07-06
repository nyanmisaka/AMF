// 
// Notice Regarding Standards.  AMD does not provide a license or sublicense to
// any Intellectual Property Rights relating to any standards, including but not
// limited to any audio and/or video codec technologies such as MPEG-2, MPEG-4;
// AVC/H.264; HEVC/H.265; AAC decode/FFMPEG; AAC encode/FFMPEG; VC-1; and MP3
// (collectively, the "Media Technologies"). For clarity, you will pay any
// royalties due for such third party technologies, which may include the Media
// Technologies that are owed as a result of AMD providing the Software to you.
// 
// MIT license 
// 
// Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
Texture2D<uint4> planeIn           : register(t0);
RWTexture2D<unorm float4> planeOut : register(u0);

#include "ChromaKeyProcessCSC.hlsl"

cbuffer Params : register(b0)
{
    uint width;
    uint height;
};

[numthreads(8, 8, 1)]
void CSV210toY210(uint3 coord : SV_DispatchThreadID)
{
    int3 pos = int3(coord.x, coord.y, 0);

    int2 dimensions;
    planeOut.GetDimensions(dimensions.x, dimensions.y);
    if ((pos.x >= dimensions.x) || (pos.y >= dimensions.y)) return;

    pos.x *= 4;
    uint4 dataIn0 = (uint4)planeIn.Load(pos);
    pos.x++;
    uint4 dataIn1 = (uint4)planeIn.Load(pos);
    pos.x++;
    uint4 dataIn2 = (uint4)planeIn.Load(pos);
    pos.x++;
    uint4 dataIn3 = (uint4)planeIn.Load(pos);
    float4 dataOut;
    dataOut.x = dataIn0.x / 1024.0f;
    dataOut.y = dataIn0.y / 1024.0f;
    dataOut.z = dataIn0.z / 1024.0f;
    dataOut.w = dataIn1.x / 1024.0f;

    pos.x = coord.x * 3;
    planeOut[pos.xy] = dataOut;

    dataOut.x = dataIn1.y / 1024.0f;
    dataOut.y = dataIn1.z / 1024.0f;
    dataOut.z = dataIn2.x / 1024.0f;
    dataOut.w = dataIn2.y / 1024.0f;
    pos.x++;
    planeOut[pos.xy] = dataOut;

    dataOut.x = dataIn2.z / 1024.0f;
    dataOut.y = dataIn3.x / 1024.0f;
    dataOut.z = dataIn3.y / 1024.0f;
    dataOut.w = dataIn3.z / 1024.0f;
    pos.x++;
    planeOut[pos.xy] = dataOut;
}

