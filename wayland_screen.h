// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef OZONE_WAYLAND_SCREEN_H_
#define OZONE_WAYLAND_SCREEN_H_

#include <stdint.h>

#include <list>

#include "base/basictypes.h"
#include "ui/gfx/point.h"
#include "ui/gfx/rect.h"

struct wl_output;

namespace ui {

class WaylandDisplay;

// WaylandScreen objects keep track of the current outputs (screens/monitors)
// that are available to the application.
class WaylandScreen {
 public:
  WaylandScreen(WaylandDisplay* display, uint32_t id);
  ~WaylandScreen();

  // Returns the active allocation of the screen.
  gfx::Rect Geometry() const;

 private:
  // Callback functions that allows the display to initialize the screen's
  // position and available modes.
  static void OutputHandleGeometry(void* data,
      wl_output* output, int32_t x, int32_t y,
      int32_t physical_width, int32_t physical_height,
      int32_t subpixel, const char* make,
      const char* model, int32_t output_transform);

  static void OutputHandleMode(void* data,
      wl_output* wl_output, uint32_t flags,
      int32_t width, int32_t height,
      int32_t refresh);

  // The Wayland output this object wraps
  wl_output* output_;
  // The position of the screen. This is important in multi monitor display
  // since it provides the position of the screen in the virtual screen.
  gfx::Point position_;

  // Rect and Refresh rate of active mode.
  gfx::Rect rect_;
  int32_t refresh_;

  DISALLOW_COPY_AND_ASSIGN(WaylandScreen);
};

}  // namespace ui

#endif  // OZONE_WAYLAND_SCREEN_H_
