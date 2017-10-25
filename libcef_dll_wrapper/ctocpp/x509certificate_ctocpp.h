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
// $hash=7f9dc4c67e92b5f5aeb4409aa103b2d4d097e9b3$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_X509CERTIFICATE_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_X509CERTIFICATE_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_x509_certificate_capi.h"
#include "include/cef_x509_certificate.h"
#include "ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefX509CertificateCToCpp
    : public CefCToCppRefCounted<CefX509CertificateCToCpp,
                                 CefX509Certificate,
                                 cef_x509certificate_t> {
 public:
  CefX509CertificateCToCpp();

  // CefX509Certificate methods.
  CefRefPtr<CefX509CertPrincipal> GetSubject() OVERRIDE;
  CefRefPtr<CefX509CertPrincipal> GetIssuer() OVERRIDE;
  CefRefPtr<CefBinaryValue> GetSerialNumber() OVERRIDE;
  CefTime GetValidStart() OVERRIDE;
  CefTime GetValidExpiry() OVERRIDE;
  CefRefPtr<CefBinaryValue> GetDEREncoded() OVERRIDE;
  CefRefPtr<CefBinaryValue> GetPEMEncoded() OVERRIDE;
  size_t GetIssuerChainSize() OVERRIDE;
  void GetDEREncodedIssuerChain(IssuerChainBinaryList& chain) OVERRIDE;
  void GetPEMEncodedIssuerChain(IssuerChainBinaryList& chain) OVERRIDE;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_X509CERTIFICATE_CTOCPP_H_
