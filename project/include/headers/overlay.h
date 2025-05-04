// File: overlay.h
// Mục đích: Định nghĩa các hàm để quản lý layout của game (GridFrame.png).
// Vai trò: Thuộc mục 1 - Quản lý hình nền và layout.

#ifndef OVERLAY_H
#define OVERLAY_H

#include <SDL.h>
#include <SDL_image.h>
#include "init.h"

// Hàm khởi tạo layout (tải GridFrame.png)
void Init_overlay();
// Hàm vẽ layout lên màn hình
void Render_overlay();
// Hàm hủy tài nguyên layout
void Destroy_overlay();

#endif