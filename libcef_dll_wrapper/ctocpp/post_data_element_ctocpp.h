// Copyright (c) 2017 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=13866ee027fb1146fd9a76cae4a92357634a9739$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_POST_DATA_ELEMENT_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_POST_DATA_ELEMENT_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_request_capi.h"
#include "include/cef_request.h"
#include "ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefPostDataElementCToCpp
    : public CefCToCppRefCounted<CefPostDataElementCToCpp,
                                 CefPostDataElement,
                                 cef_post_data_element_t> {
 public:
  CefPostDataElementCToCpp();

  // CefPostDataElement methods.
  bool IsReadOnly() OVERRIDE;
  void SetToEmpty() OVERRIDE;
  void SetToFile(const CefString& fileName) OVERRIDE;
  void SetToBytes(size_t size, const void* bytes) OVERRIDE;
  Type GetType() OVERRIDE;
  CefString GetFile() OVERRIDE;
  size_t GetBytesCount() OVERRIDE;
  size_t GetBytes(size_t size, void* bytes) OVERRIDE;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_POST_DATA_ELEMENT_CTOCPP_H_
