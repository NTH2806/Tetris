// File: help_credit.h
// Mục đích: Định nghĩa các hàm để quản lý và hiển thị help credit.
// Vai trò: Hiển thị help credit trên màn hình.

#ifndef HELP_CREDIT_H
#define HELP_CREDIT_H

#include "init.h"
#include <SDL.h>
#include <SDL_image.h>

// Biến toàn cục lưu texture của help credit
extern SDL_Texture* help_credit_texture;

// Hàm khởi tạo help credit
void Init_help_credit();

// Hàm vẽ help credit lên màn hình
void Render_help_credit();

// Hàm hủy tài nguyên help credit
void Destroy_help_credit();

#endif