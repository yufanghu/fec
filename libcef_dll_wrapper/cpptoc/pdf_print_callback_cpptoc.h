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
// $hash=3102a69251d6de737ac43443955c3fb8ae73067c$
//

#ifndef CEF_LIBCEF_DLL_CPPTOC_PDF_PRINT_CALLBACK_CPPTOC_H_
#define CEF_LIBCEF_DLL_CPPTOC_PDF_PRINT_CALLBACK_CPPTOC_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_browser_capi.h"
#include "include/capi/cef_client_capi.h"
#include "include/cef_browser.h"
#include "include/cef_client.h"
#include "cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed wrapper-side only.
class CefPdfPrintCallbackCppToC
    : public CefCppToCRefCounted<CefPdfPrintCallbackCppToC,
                                 CefPdfPrintCallback,
                                 cef_pdf_print_callback_t> {
 public:
  CefPdfPrintCallbackCppToC();
};

#endif  // CEF_LIBCEF_DLL_CPPTOC_PDF_PRINT_CALLBACK_CPPTOC_H_
