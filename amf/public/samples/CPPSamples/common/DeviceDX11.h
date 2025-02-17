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
// Copyright (c) 2018 Advanced Micro Devices, Inc. All rights reserved.
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

#pragma once
#include <SDKDDKVer.h>
#include <string>
#include <atlbase.h>
#include <d3d11.h>
#include "public/include/core/Result.h"




class DeviceDX11
{
public:
    DeviceDX11();
    virtual ~DeviceDX11();

    AMF_RESULT Init(amf_uint32 adapterID, bool onlyWithOutputs = false);
    AMF_RESULT Terminate();

    ATL::CComPtr<ID3D11Device>      GetDevice();
    std::wstring GetDisplayDeviceName() { return m_displayDeviceName; }
    LUID        GetLuid() { return m_LUID; }
private:
    void EnumerateAdapters(bool onlyWithOutputs);

    ATL::CComPtr<ID3D11Device>          m_pD3DDevice;

    static const amf_uint32             MAXADAPTERS = 128;
    amf_uint32                          m_adaptersCount;
    amf_uint32                          m_adaptersIndexes[MAXADAPTERS];
    std::wstring                        m_displayDeviceName;
    LUID                                m_LUID;

};
