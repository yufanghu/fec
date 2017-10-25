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
// $hash=f06ecbd1e962a29bb0191b05a5545cbc0e190742$
//

#include "cpptoc/delete_cookies_callback_cpptoc.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK
delete_cookies_callback_on_complete(struct _cef_delete_cookies_callback_t* self,
                                    int num_deleted) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefDeleteCookiesCallbackCppToC::Get(self)->OnComplete(num_deleted);
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefDeleteCookiesCallbackCppToC::CefDeleteCookiesCallbackCppToC() {
  GetStruct()->on_complete = delete_cookies_callback_on_complete;
}

template <>
CefRefPtr<CefDeleteCookiesCallback> CefCppToCRefCounted<
    CefDeleteCookiesCallbackCppToC,
    CefDeleteCookiesCallback,
    cef_delete_cookies_callback_t>::UnwrapDerived(CefWrapperType type,
                                                  cef_delete_cookies_callback_t*
                                                      s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount CefCppToCRefCounted<
    CefDeleteCookiesCallbackCppToC,
    CefDeleteCookiesCallback,
    cef_delete_cookies_callback_t>::DebugObjCt ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType
    CefCppToCRefCounted<CefDeleteCookiesCallbackCppToC,
                        CefDeleteCookiesCallback,
                        cef_delete_cookies_callback_t>::kWrapperType =
        WT_DELETE_COOKIES_CALLBACK;
