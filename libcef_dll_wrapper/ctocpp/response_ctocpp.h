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
// $hash=e47f062a6fd7366b38f2f02b71415ced089445d1$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_RESPONSE_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_RESPONSE_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_response_capi.h"
#include "include/cef_response.h"
#include "ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefResponseCToCpp : public CefCToCppRefCounted<CefResponseCToCpp,
                                                     CefResponse,
                                                     cef_response_t> {
 public:
  CefResponseCToCpp();

  // CefResponse methods.
  bool IsReadOnly() OVERRIDE;
  cef_errorcode_t GetError() OVERRIDE;
  void SetError(cef_errorcode_t error) OVERRIDE;
  int GetStatus() OVERRIDE;
  void SetStatus(int status) OVERRIDE;
  CefString GetStatusText() OVERRIDE;
  void SetStatusText(const CefString& statusText) OVERRIDE;
  CefString GetMimeType() OVERRIDE;
  void SetMimeType(const CefString& mimeType) OVERRIDE;
  CefString GetHeader(const CefString& name) OVERRIDE;
  void GetHeaderMap(HeaderMap& headerMap) OVERRIDE;
  void SetHeaderMap(const HeaderMap& headerMap) OVERRIDE;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_RESPONSE_CTOCPP_H_
