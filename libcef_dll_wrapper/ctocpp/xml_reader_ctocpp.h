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
// $hash=f7c6ec7a65338563a20155417177b38ee3565c1f$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_XML_READER_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_XML_READER_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_xml_reader_capi.h"
#include "include/cef_xml_reader.h"
#include "ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefXmlReaderCToCpp : public CefCToCppRefCounted<CefXmlReaderCToCpp,
                                                      CefXmlReader,
                                                      cef_xml_reader_t> {
 public:
  CefXmlReaderCToCpp();

  // CefXmlReader methods.
  bool MoveToNextNode() OVERRIDE;
  bool Close() OVERRIDE;
  bool HasError() OVERRIDE;
  CefString GetError() OVERRIDE;
  NodeType GetType() OVERRIDE;
  int GetDepth() OVERRIDE;
  CefString GetLocalName() OVERRIDE;
  CefString GetPrefix() OVERRIDE;
  CefString GetQualifiedName() OVERRIDE;
  CefString GetNamespaceURI() OVERRIDE;
  CefString GetBaseURI() OVERRIDE;
  CefString GetXmlLang() OVERRIDE;
  bool IsEmptyElement() OVERRIDE;
  bool HasValue() OVERRIDE;
  CefString GetValue() OVERRIDE;
  bool HasAttributes() OVERRIDE;
  size_t GetAttributeCount() OVERRIDE;
  CefString GetAttribute(int index) OVERRIDE;
  CefString GetAttribute(const CefString& qualifiedName) OVERRIDE;
  CefString GetAttribute(const CefString& localName,
                         const CefString& namespaceURI) OVERRIDE;
  CefString GetInnerXml() OVERRIDE;
  CefString GetOuterXml() OVERRIDE;
  int GetLineNumber() OVERRIDE;
  bool MoveToAttribute(int index) OVERRIDE;
  bool MoveToAttribute(const CefString& qualifiedName) OVERRIDE;
  bool MoveToAttribute(const CefString& localName,
                       const CefString& namespaceURI) OVERRIDE;
  bool MoveToFirstAttribute() OVERRIDE;
  bool MoveToNextAttribute() OVERRIDE;
  bool MoveToCarryingElement() OVERRIDE;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_XML_READER_CTOCPP_H_
