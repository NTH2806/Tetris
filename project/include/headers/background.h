// File: background.h
// Mục đích: Định nghĩa các hàm để quản lý hình nền của game (cyber_background.png).
// Vai trò: Thuộc mục 1 - Quản lý hình nền và layout.

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL.h>
#include <SDL_image.h>
#include "init.h"

// Hàm khởi tạo hình nền (tải cyber_background.png)
void Init_background();
// Hàm vẽ hình nền lên màn hình
void Render_background();
// Hàm hủy tài nguyên hình nền
void Destroy_background();

#endif