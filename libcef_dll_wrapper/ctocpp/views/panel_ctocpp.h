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
// $hash=9d99661767ab4fdc94ea011361addc51ccc1fde3$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_VIEWS_PANEL_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_VIEWS_PANEL_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/views/cef_box_layout_capi.h"
#include "include/capi/views/cef_fill_layout_capi.h"
#include "include/capi/views/cef_layout_capi.h"
#include "include/capi/views/cef_panel_capi.h"
#include "include/capi/views/cef_window_capi.h"
#include "include/views/cef_box_layout.h"
#include "include/views/cef_fill_layout.h"
#include "include/views/cef_layout.h"
#include "include/views/cef_panel.h"
#include "include/views/cef_window.h"
#include "ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefPanelCToCpp
    : public CefCToCppRefCounted<CefPanelCToCpp, CefPanel, cef_panel_t> {
 public:
  CefPanelCToCpp();

  // CefPanel methods.
  CefRefPtr<CefWindow> AsWindow() OVERRIDE;
  CefRefPtr<CefFillLayout> SetToFillLayout() OVERRIDE;
  CefRefPtr<CefBoxLayout> SetToBoxLayout(
      const CefBoxLayoutSettings& settings) OVERRIDE;
  CefRefPtr<CefLayout> GetLayout() OVERRIDE;
  void Layout() OVERRIDE;
  void AddChildView(CefRefPtr<CefView> view) OVERRIDE;
  void AddChildViewAt(CefRefPtr<CefView> view, int index) OVERRIDE;
  void ReorderChildView(CefRefPtr<CefView> view, int index) OVERRIDE;
  void RemoveChildView(CefRefPtr<CefView> view) OVERRIDE;
  void RemoveAllChildViews() OVERRIDE;
  size_t GetChildViewCount() OVERRIDE;
  CefRefPtr<CefView> GetChildViewAt(int index) OVERRIDE;

  // CefView methods.
  CefRefPtr<CefBrowserView> AsBrowserView() OVERRIDE;
  CefRefPtr<CefButton> AsButton() OVERRIDE;
  CefRefPtr<CefPanel> AsPanel() OVERRIDE;
  CefRefPtr<CefScrollView> AsScrollView() OVERRIDE;
  CefRefPtr<CefTextfield> AsTextfield() OVERRIDE;
  CefString GetTypeString() OVERRIDE;
  CefString ToString(bool include_children) OVERRIDE;
  bool IsValid() OVERRIDE;
  bool IsAttached() OVERRIDE;
  bool IsSame(CefRefPtr<CefView> that) OVERRIDE;
  CefRefPtr<CefViewDelegate> GetDelegate() OVERRIDE;
  CefRefPtr<CefWindow> GetWindow() OVERRIDE;
  int GetID() OVERRIDE;
  void SetID(int id) OVERRIDE;
  int GetGroupID() OVERRIDE;
  void SetGroupID(int group_id) OVERRIDE;
  CefRefPtr<CefView> GetParentView() OVERRIDE;
  CefRefPtr<CefView> GetViewForID(int id) OVERRIDE;
  void SetBounds(const CefRect& bounds) OVERRIDE;
  CefRect GetBounds() OVERRIDE;
  CefRect GetBoundsInScreen() OVERRIDE;
  void SetSize(const CefSize& size) OVERRIDE;
  CefSize GetSize() OVERRIDE;
  void SetPosition(const CefPoint& position) OVERRIDE;
  CefPoint GetPosition() OVERRIDE;
  CefSize GetPreferredSize() OVERRIDE;
  void SizeToPreferredSize() OVERRIDE;
  CefSize GetMinimumSize() OVERRIDE;
  CefSize GetMaximumSize() OVERRIDE;
  int GetHeightForWidth(int width) OVERRIDE;
  void InvalidateLayout() OVERRIDE;
  void SetVisible(bool visible) OVERRIDE;
  bool IsVisible() OVERRIDE;
  bool IsDrawn() OVERRIDE;
  void SetEnabled(bool enabled) OVERRIDE;
  bool IsEnabled() OVERRIDE;
  void SetFocusable(bool focusable) OVERRIDE;
  bool IsFocusable() OVERRIDE;
  bool IsAccessibilityFocusable() OVERRIDE;
  void RequestFocus() OVERRIDE;
  void SetBackgroundColor(cef_color_t color) OVERRIDE;
  cef_color_t GetBackgroundColor() OVERRIDE;
  bool ConvertPointToScreen(CefPoint& point) OVERRIDE;
  bool ConvertPointFromScreen(CefPoint& point) OVERRIDE;
  bool ConvertPointToWindow(CefPoint& point) OVERRIDE;
  bool ConvertPointFromWindow(CefPoint& point) OVERRIDE;
  bool ConvertPointToView(CefRefPtr<CefView> view, CefPoint& point) OVERRIDE;
  bool ConvertPointFromView(CefRefPtr<CefView> view, CefPoint& point) OVERRIDE;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_VIEWS_PANEL_CTOCPP_H_
