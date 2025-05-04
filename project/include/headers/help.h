// File: help.h
// Mục đích: Định nghĩa các hàm để quản lý và hiển thị hình ảnh help.
// Vai trò: Hiển thị help trên màn hình.

#ifndef HELP_H
#define HELP_H

#include "init.h"
#include <SDL.h>
#include <SDL_image.h>

// Biến toàn cục lưu texture của help
extern SDL_Texture* help_texture;

// Hàm khởi tạo help
void Init_help();

// Hàm vẽ help lên màn hình (thêm tham số hover)
void Render_help(int mouseX , int mouseY);

// Hàm hủy tài nguyên help
void Destroy_help();

#endif