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
// $hash=3d9a6d1eac11b56ccf6282e552f4d668de89e161$
//

#include "ctocpp/views/layout_ctocpp.h"
#include "ctocpp/views/box_layout_ctocpp.h"
#include "ctocpp/views/fill_layout_ctocpp.h"

// VIRTUAL METHODS - Body may be edited by hand.

CefRefPtr<CefBoxLayout> CefLayoutCToCpp::AsBoxLayout() {
  cef_layout_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, as_box_layout))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_box_layout_t* _retval = _struct->as_box_layout(_struct);

  // Return type: refptr_same
  return CefBoxLayoutCToCpp::Wrap(_retval);
}

CefRefPtr<CefFillLayout> CefLayoutCToCpp::AsFillLayout() {
  cef_layout_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, as_fill_layout))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_fill_layout_t* _retval = _struct->as_fill_layout(_struct);

  // Return type: refptr_same
  return CefFillLayoutCToCpp::Wrap(_retval);
}

bool CefLayoutCToCpp::IsValid() {
  cef_layout_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_valid))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_valid(_struct);

  // Return type: bool
  return _retval ? true : false;
}

// CONSTRUCTOR - Do not edit by hand.

CefLayoutCToCpp::CefLayoutCToCpp() {}

template <>
cef_layout_t*
CefCToCppRefCounted<CefLayoutCToCpp, CefLayout, cef_layout_t>::UnwrapDerived(
    CefWrapperType type,
    CefLayout* c) {
  if (type == WT_BOX_LAYOUT) {
    return reinterpret_cast<cef_layout_t*>(
        CefBoxLayoutCToCpp::Unwrap(reinterpret_cast<CefBoxLayout*>(c)));
  }
  if (type == WT_FILL_LAYOUT) {
    return reinterpret_cast<cef_layout_t*>(
        CefFillLayoutCToCpp::Unwrap(reinterpret_cast<CefFillLayout*>(c)));
  }
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount
    CefCToCppRefCounted<CefLayoutCToCpp, CefLayout, cef_layout_t>::DebugObjCt
        ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType CefCToCppRefCounted<CefLayoutCToCpp, CefLayout, cef_layout_t>::
    kWrapperType = WT_LAYOUT;
