// Copyright 2014 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef OZONE_PLATFORM_OZONE_WAYLAND_WINDOW_H_
#define OZONE_PLATFORM_OZONE_WAYLAND_WINDOW_H_

#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/platform_window/platform_window.h"

namespace views {
class WindowTreeHostDelegateWayland;
}

namespace ui {

class PlatformWindowDelegate;

class OzoneWaylandWindow : public PlatformWindow {
 public:
  OzoneWaylandWindow(PlatformWindowDelegate* delegate,
                     const gfx::Rect& bounds);
  virtual ~OzoneWaylandWindow();

  unsigned GetHandle() const { return handle_; }
  PlatformWindowDelegate* GetDelegate() const { return delegate_; }

  // PlatformWindow:
  void InitPlatformWindow(PlatformWindowType type,
                          gfx::AcceleratedWidget parent_window) override;
  gfx::Rect GetBounds() override;
  void SetBounds(const gfx::Rect& bounds) override;
  void Show() override;
  void Hide() override;
  void Close() override;
  void SetCapture() override;
  void ReleaseCapture() override;
  void ToggleFullscreen() override;
  void Maximize() override;
  void Minimize() override;
  void Restore() override;
  void SetCursor(PlatformCursor cursor) override;
  void MoveCursorTo(const gfx::Point& location) override;

 private:
  PlatformWindowDelegate* delegate_;
  gfx::Rect bounds_;
  unsigned handle_;

  static views::WindowTreeHostDelegateWayland* g_delegate_ozone_wayland_;
  DISALLOW_COPY_AND_ASSIGN(OzoneWaylandWindow);
};

}  // namespace ui

#endif  // OZONE_PLATFORM_OZONE_WAYLAND_WINDOW_H_
