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
// $hash=73a2a5ef7d9e086e40fb19488f9906d79918ba66$
//

#include "ctocpp/frame_ctocpp.h"
#include "cpptoc/domvisitor_cpptoc.h"
#include "cpptoc/string_visitor_cpptoc.h"
#include "ctocpp/browser_ctocpp.h"
#include "ctocpp/request_ctocpp.h"
#include "ctocpp/v8context_ctocpp.h"

// VIRTUAL METHODS - Body may be edited by hand.

bool CefFrameCToCpp::IsValid() {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_valid))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_valid(_struct);

  // Return type: bool
  return _retval ? true : false;
}

void CefFrameCToCpp::Undo() {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, undo))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->undo(_struct);
}

void CefFrameCToCpp::Redo() {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, redo))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->redo(_struct);
}

void CefFrameCToCpp::Cut() {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, cut))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->cut(_struct);
}

void CefFrameCToCpp::Copy() {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, copy))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->copy(_struct);
}

void CefFrameCToCpp::Paste() {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, paste))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->paste(_struct);
}

void CefFrameCToCpp::Delete() {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, del))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->del(_struct);
}

void CefFrameCToCpp::SelectAll() {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, select_all))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->select_all(_struct);
}

void CefFrameCToCpp::ViewSource() {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, view_source))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->view_source(_struct);
}

void CefFrameCToCpp::GetSource(CefRefPtr<CefStringVisitor> visitor) {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_source))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: visitor; type: refptr_diff
  DCHECK(visitor.get());
  if (!visitor.get())
    return;

  // Execute
  _struct->get_source(_struct, CefStringVisitorCppToC::Wrap(visitor));
}

void CefFrameCToCpp::GetText(CefRefPtr<CefStringVisitor> visitor) {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_text))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: visitor; type: refptr_diff
  DCHECK(visitor.get());
  if (!visitor.get())
    return;

  // Execute
  _struct->get_text(_struct, CefStringVisitorCppToC::Wrap(visitor));
}

void CefFrameCToCpp::LoadRequest(CefRefPtr<CefRequest> request) {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, load_request))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: request; type: refptr_same
  DCHECK(request.get());
  if (!request.get())
    return;

  // Execute
  _struct->load_request(_struct, CefRequestCToCpp::Unwrap(request));
}

void CefFrameCToCpp::LoadURL(const CefString& url) {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, load_url))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: url; type: string_byref_const
  DCHECK(!url.empty());
  if (url.empty())
    return;

  // Execute
  _struct->load_url(_struct, url.GetStruct());
}

void CefFrameCToCpp::LoadString(const CefString& string_val,
                                const CefString& url) {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, load_string))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: string_val; type: string_byref_const
  DCHECK(!string_val.empty());
  if (string_val.empty())
    return;
  // Verify param: url; type: string_byref_const
  DCHECK(!url.empty());
  if (url.empty())
    return;

  // Execute
  _struct->load_string(_struct, string_val.GetStruct(), url.GetStruct());
}

void CefFrameCToCpp::ExecuteJavaScript(const CefString& code,
                                       const CefString& script_url,
                                       int start_line) {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, execute_java_script))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: code; type: string_byref_const
  DCHECK(!code.empty());
  if (code.empty())
    return;
  // Unverified params: script_url

  // Execute
  _struct->execute_java_script(_struct, code.GetStruct(),
                               script_url.GetStruct(), start_line);
}

bool CefFrameCToCpp::IsMain() {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_main))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_main(_struct);

  // Return type: bool
  return _retval ? true : false;
}

bool CefFrameCToCpp::IsFocused() {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_focused))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_focused(_struct);

  // Return type: bool
  return _retval ? true : false;
}

CefString CefFrameCToCpp::GetName() {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_name))
    return CefString();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_name(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

int64 CefFrameCToCpp::GetIdentifier() {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_identifier))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int64 _retval = _struct->get_identifier(_struct);

  // Return type: simple
  return _retval;
}

CefRefPtr<CefFrame> CefFrameCToCpp::GetParent() {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_parent))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_frame_t* _retval = _struct->get_parent(_struct);

  // Return type: refptr_same
  return CefFrameCToCpp::Wrap(_retval);
}

CefString CefFrameCToCpp::GetURL() {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_url))
    return CefString();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_url(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

CefRefPtr<CefBrowser> CefFrameCToCpp::GetBrowser() {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_browser))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_browser_t* _retval = _struct->get_browser(_struct);

  // Return type: refptr_same
  return CefBrowserCToCpp::Wrap(_retval);
}

CefRefPtr<CefV8Context> CefFrameCToCpp::GetV8Context() {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_v8context))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_v8context_t* _retval = _struct->get_v8context(_struct);

  // Return type: refptr_same
  return CefV8ContextCToCpp::Wrap(_retval);
}

void CefFrameCToCpp::VisitDOM(CefRefPtr<CefDOMVisitor> visitor) {
  cef_frame_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, visit_dom))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: visitor; type: refptr_diff
  DCHECK(visitor.get());
  if (!visitor.get())
    return;

  // Execute
  _struct->visit_dom(_struct, CefDOMVisitorCppToC::Wrap(visitor));
}

// CONSTRUCTOR - Do not edit by hand.

CefFrameCToCpp::CefFrameCToCpp() {}

template <>
cef_frame_t*
CefCToCppRefCounted<CefFrameCToCpp, CefFrame, cef_frame_t>::UnwrapDerived(
    CefWrapperType type,
    CefFrame* c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount
    CefCToCppRefCounted<CefFrameCToCpp, CefFrame, cef_frame_t>::DebugObjCt
        ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType
    CefCToCppRefCounted<CefFrameCToCpp, CefFrame, cef_frame_t>::kWrapperType =
        WT_FRAME;
