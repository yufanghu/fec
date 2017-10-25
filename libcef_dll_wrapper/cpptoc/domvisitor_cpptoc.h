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
// $hash=9bb7487a5f6db84031a7b3fbb62a1954f54cafee$
//

#ifndef CEF_LIBCEF_DLL_CPPTOC_DOMVISITOR_CPPTOC_H_
#define CEF_LIBCEF_DLL_CPPTOC_DOMVISITOR_CPPTOC_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_dom_capi.h"
#include "include/cef_dom.h"
#include "cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed wrapper-side only.
class CefDOMVisitorCppToC : public CefCppToCRefCounted<CefDOMVisitorCppToC,
                                                       CefDOMVisitor,
                                                       cef_domvisitor_t> {
 public:
  CefDOMVisitorCppToC();
};

#endif  // CEF_LIBCEF_DLL_CPPTOC_DOMVISITOR_CPPTOC_H_
