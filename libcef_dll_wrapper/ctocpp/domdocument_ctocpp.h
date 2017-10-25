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
// $hash=e7de3098bdeed346bb0f4616b998eda5b2a341e9$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_DOMDOCUMENT_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_DOMDOCUMENT_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_dom_capi.h"
#include "include/cef_dom.h"
#include "ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefDOMDocumentCToCpp : public CefCToCppRefCounted<CefDOMDocumentCToCpp,
                                                        CefDOMDocument,
                                                        cef_domdocument_t> {
 public:
  CefDOMDocumentCToCpp();

  // CefDOMDocument methods.
  Type GetType() OVERRIDE;
  CefRefPtr<CefDOMNode> GetDocument() OVERRIDE;
  CefRefPtr<CefDOMNode> GetBody() OVERRIDE;
  CefRefPtr<CefDOMNode> GetHead() OVERRIDE;
  CefString GetTitle() OVERRIDE;
  CefRefPtr<CefDOMNode> GetElementById(const CefString& id) OVERRIDE;
  CefRefPtr<CefDOMNode> GetFocusedNode() OVERRIDE;
  bool HasSelection() OVERRIDE;
  int GetSelectionStartOffset() OVERRIDE;
  int GetSelectionEndOffset() OVERRIDE;
  CefString GetSelectionAsMarkup() OVERRIDE;
  CefString GetSelectionAsText() OVERRIDE;
  CefString GetBaseURL() OVERRIDE;
  CefString GetCompleteURL(const CefString& partialURL) OVERRIDE;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_DOMDOCUMENT_CTOCPP_H_
