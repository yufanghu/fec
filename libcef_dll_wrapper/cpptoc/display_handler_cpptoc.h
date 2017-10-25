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
// $hash=25d9fba9bd05e09d69e853e2ab02b3a187166b7f$
//

#ifndef CEF_LIBCEF_DLL_CPPTOC_DISPLAY_HANDLER_CPPTOC_H_
#define CEF_LIBCEF_DLL_CPPTOC_DISPLAY_HANDLER_CPPTOC_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_display_handler_capi.h"
#include "include/cef_display_handler.h"
#include "cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed wrapper-side only.
class CefDisplayHandlerCppToC
    : public CefCppToCRefCounted<CefDisplayHandlerCppToC,
                                 CefDisplayHandler,
                                 cef_display_handler_t> {
 public:
  CefDisplayHandlerCppToC();
};

#endif  // CEF_LIBCEF_DLL_CPPTOC_DISPLAY_HANDLER_CPPTOC_H_
