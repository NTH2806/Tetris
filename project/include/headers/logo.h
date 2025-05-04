// File: logo.h
// Mục đích: Định nghĩa các hàm để quản lý và hiển thị logo.
// Vai trò: Hiển thị logo trên màn hình.

#ifndef LOGO_H
#define LOGO_H

#include "init.h"
#include <SDL.h>
#include <SDL_image.h>

// Biến toàn cục lưu texture của logo
extern SDL_Texture* logo_texture;

// Hàm khởi tạo logo
void Init_logo();

// Hàm vẽ logo lên màn hình
void Render_logo();

// Hàm hủy tài nguyên logo
void Destroy_logo();

#endif