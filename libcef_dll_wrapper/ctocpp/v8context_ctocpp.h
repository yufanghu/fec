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
// $hash=aa93485d557e0532ef47252661885fc1e7945789$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_V8CONTEXT_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_V8CONTEXT_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_v8_capi.h"
#include "include/cef_v8.h"
#include "ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefV8ContextCToCpp : public CefCToCppRefCounted<CefV8ContextCToCpp,
                                                      CefV8Context,
                                                      cef_v8context_t> {
 public:
  CefV8ContextCToCpp();

  // CefV8Context methods.
  CefRefPtr<CefTaskRunner> GetTaskRunner() OVERRIDE;
  bool IsValid() OVERRIDE;
  CefRefPtr<CefBrowser> GetBrowser() OVERRIDE;
  CefRefPtr<CefFrame> GetFrame() OVERRIDE;
  CefRefPtr<CefV8Value> GetGlobal() OVERRIDE;
  bool Enter() OVERRIDE;
  bool Exit() OVERRIDE;
  bool IsSame(CefRefPtr<CefV8Context> that) OVERRIDE;
  bool Eval(const CefString& code,
            const CefString& script_url,
            int start_line,
            CefRefPtr<CefV8Value>& retval,
            CefRefPtr<CefV8Exception>& exception) OVERRIDE;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_V8CONTEXT_CTOCPP_H_
