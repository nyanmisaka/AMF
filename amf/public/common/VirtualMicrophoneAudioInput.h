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
// Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved.
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

#if defined(_WIN32)
#include <tchar.h>
#else
#endif
#include <conio.h>

#include <memory>

#include "public/include/core/Debug.h"
#include "public/common/TraceAdapter.h"
#include "public/common/AMFFactory.h"
#include "public/common/AMFMath.h"
#include "public/common/Thread.h"
#include "protected/include/components/VirtualAudio.h"
#include "public/common/ByteArray.h"

using namespace amf;

class VirtualMicrophoneAudioInput
{
public:
	VirtualMicrophoneAudioInput();
	~VirtualMicrophoneAudioInput();

	AMF_RESULT Init();
	AMF_RESULT Terminate();

	AMF_RESULT EnableInput();
	AMF_RESULT CheckStatus();
	AMF_RESULT CheckFormat();
	AMF_RESULT ChangeInputParameters(amf_int64 sampleRate, 
		amf_int64   channelCount, 
		amf_int64   audioFormat);
	AMF_RESULT ChangeInputParameters(amf::AMFVirtualAudioFormat* format);
	AMF_RESULT VerifyInputParameters(amf::AMFVirtualAudioFormat* format);
	AMF_RESULT DisableInput();
	AMF_RESULT SubmitInput(amf::AMFAudioBufferPtr pAudioBuffer);
	AMF_RESULT SubmitData(const void* data, amf_size sizeInBytes);

protected:
	amf::AMFVirtualAudioManagerPtr				m_pAudioManager;
	amf::AMFVirtualAudioInputPtr				m_pVirtualAudioInput;

	AMF_RESULT CreateVirtualAudioInput();
	AMF_RESULT DestroyVirtualAudioInput();

#ifdef WIN32
    bool m_bCoInitializeSucceeded;
#endif
};

typedef std::shared_ptr<VirtualMicrophoneAudioInput> VirtualMicrophoneAudioInputPtr;