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
// $hash=782642e65456b32ab0fab59db2b9442783b7f574$
//

#include "cpptoc/views/menu_button_delegate_cpptoc.h"
#include "ctocpp/views/button_ctocpp.h"
#include "ctocpp/views/menu_button_ctocpp.h"
#include "ctocpp/views/view_ctocpp.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK menu_button_delegate_on_menu_button_pressed(
    struct _cef_menu_button_delegate_t* self,
    cef_menu_button_t* menu_button,
    const cef_point_t* screen_point) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: menu_button; type: refptr_diff
  DCHECK(menu_button);
  if (!menu_button)
    return;
  // Verify param: screen_point; type: simple_byref_const
  DCHECK(screen_point);
  if (!screen_point)
    return;

  // Translate param: screen_point; type: simple_byref_const
  CefPoint screen_pointVal = screen_point ? *screen_point : CefPoint();

  // Execute
  CefMenuButtonDelegateCppToC::Get(self)->OnMenuButtonPressed(
      CefMenuButtonCToCpp::Wrap(menu_button), screen_pointVal);
}

void CEF_CALLBACK
menu_button_delegate_on_button_pressed(struct _cef_button_delegate_t* self,
                                       cef_button_t* button) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: button; type: refptr_diff
  DCHECK(button);
  if (!button)
    return;

  // Execute
  CefMenuButtonDelegateCppToC::Get(
      reinterpret_cast<cef_menu_button_delegate_t*>(self))
      ->OnButtonPressed(CefButtonCToCpp::Wrap(button));
}

void CEF_CALLBACK menu_button_delegate_on_button_state_changed(
    struct _cef_button_delegate_t* self,
    cef_button_t* button) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: button; type: refptr_diff
  DCHECK(button);
  if (!button)
    return;

  // Execute
  CefMenuButtonDelegateCppToC::Get(
      reinterpret_cast<cef_menu_button_delegate_t*>(self))
      ->OnButtonStateChanged(CefButtonCToCpp::Wrap(button));
}

cef_size_t CEF_CALLBACK
menu_button_delegate_get_preferred_size(struct _cef_view_delegate_t* self,
                                        cef_view_t* view) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefSize();
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view)
    return CefSize();

  // Execute
  cef_size_t _retval = CefMenuButtonDelegateCppToC::Get(
                           reinterpret_cast<cef_menu_button_delegate_t*>(self))
                           ->GetPreferredSize(CefViewCToCpp::Wrap(view));

  // Return type: simple
  return _retval;
}

cef_size_t CEF_CALLBACK
menu_button_delegate_get_minimum_size(struct _cef_view_delegate_t* self,
                                      cef_view_t* view) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefSize();
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view)
    return CefSize();

  // Execute
  cef_size_t _retval = CefMenuButtonDelegateCppToC::Get(
                           reinterpret_cast<cef_menu_button_delegate_t*>(self))
                           ->GetMinimumSize(CefViewCToCpp::Wrap(view));

  // Return type: simple
  return _retval;
}

cef_size_t CEF_CALLBACK
menu_button_delegate_get_maximum_size(struct _cef_view_delegate_t* self,
                                      cef_view_t* view) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefSize();
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view)
    return CefSize();

  // Execute
  cef_size_t _retval = CefMenuButtonDelegateCppToC::Get(
                           reinterpret_cast<cef_menu_button_delegate_t*>(self))
                           ->GetMaximumSize(CefViewCToCpp::Wrap(view));

  // Return type: simple
  return _retval;
}

int CEF_CALLBACK
menu_button_delegate_get_height_for_width(struct _cef_view_delegate_t* self,
                                          cef_view_t* view,
                                          int width) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view)
    return 0;

  // Execute
  int _retval = CefMenuButtonDelegateCppToC::Get(
                    reinterpret_cast<cef_menu_button_delegate_t*>(self))
                    ->GetHeightForWidth(CefViewCToCpp::Wrap(view), width);

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK
menu_button_delegate_on_parent_view_changed(struct _cef_view_delegate_t* self,
                                            cef_view_t* view,
                                            int added,
                                            cef_view_t* parent) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view)
    return;
  // Verify param: parent; type: refptr_diff
  DCHECK(parent);
  if (!parent)
    return;

  // Execute
  CefMenuButtonDelegateCppToC::Get(
      reinterpret_cast<cef_menu_button_delegate_t*>(self))
      ->OnParentViewChanged(CefViewCToCpp::Wrap(view), added ? true : false,
                            CefViewCToCpp::Wrap(parent));
}

void CEF_CALLBACK
menu_button_delegate_on_child_view_changed(struct _cef_view_delegate_t* self,
                                           cef_view_t* view,
                                           int added,
                                           cef_view_t* child) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view)
    return;
  // Verify param: child; type: refptr_diff
  DCHECK(child);
  if (!child)
    return;

  // Execute
  CefMenuButtonDelegateCppToC::Get(
      reinterpret_cast<cef_menu_button_delegate_t*>(self))
      ->OnChildViewChanged(CefViewCToCpp::Wrap(view), added ? true : false,
                           CefViewCToCpp::Wrap(child));
}

void CEF_CALLBACK
menu_button_delegate_on_focus(struct _cef_view_delegate_t* self,
                              cef_view_t* view) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view)
    return;

  // Execute
  CefMenuButtonDelegateCppToC::Get(
      reinterpret_cast<cef_menu_button_delegate_t*>(self))
      ->OnFocus(CefViewCToCpp::Wrap(view));
}

void CEF_CALLBACK
menu_button_delegate_on_blur(struct _cef_view_delegate_t* self,
                             cef_view_t* view) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: view; type: refptr_diff
  DCHECK(view);
  if (!view)
    return;

  // Execute
  CefMenuButtonDelegateCppToC::Get(
      reinterpret_cast<cef_menu_button_delegate_t*>(self))
      ->OnBlur(CefViewCToCpp::Wrap(view));
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefMenuButtonDelegateCppToC::CefMenuButtonDelegateCppToC() {
  GetStruct()->on_menu_button_pressed =
      menu_button_delegate_on_menu_button_pressed;
  GetStruct()->base.on_button_pressed = menu_button_delegate_on_button_pressed;
  GetStruct()->base.on_button_state_changed =
      menu_button_delegate_on_button_state_changed;
  GetStruct()->base.base.get_preferred_size =
      menu_button_delegate_get_preferred_size;
  GetStruct()->base.base.get_minimum_size =
      menu_button_delegate_get_minimum_size;
  GetStruct()->base.base.get_maximum_size =
      menu_button_delegate_get_maximum_size;
  GetStruct()->base.base.get_height_for_width =
      menu_button_delegate_get_height_for_width;
  GetStruct()->base.base.on_parent_view_changed =
      menu_button_delegate_on_parent_view_changed;
  GetStruct()->base.base.on_child_view_changed =
      menu_button_delegate_on_child_view_changed;
  GetStruct()->base.base.on_focus = menu_button_delegate_on_focus;
  GetStruct()->base.base.on_blur = menu_button_delegate_on_blur;
}

template <>
CefRefPtr<CefMenuButtonDelegate> CefCppToCRefCounted<
    CefMenuButtonDelegateCppToC,
    CefMenuButtonDelegate,
    cef_menu_button_delegate_t>::UnwrapDerived(CefWrapperType type,
                                               cef_menu_button_delegate_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount CefCppToCRefCounted<CefMenuButtonDelegateCppToC,
                                         CefMenuButtonDelegate,
                                         cef_menu_button_delegate_t>::DebugObjCt
    ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType CefCppToCRefCounted<CefMenuButtonDelegateCppToC,
                                   CefMenuButtonDelegate,
                                   cef_menu_button_delegate_t>::kWrapperType =
    WT_MENU_BUTTON_DELEGATE;
