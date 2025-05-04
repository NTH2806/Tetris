// File: help_tex.h
// Mục đích: Định nghĩa các hàm để quản lý texture help trong giao diện help.
// Vai trò: Thuộc mục giao diện help.

#ifndef HELP_TEX_H
#define HELP_TEX_H

#include <SDL.h>
#include <SDL_image.h>
#include "init.h"

extern SDL_Texture* help_tex_texture;

// Hàm khởi tạo texture cho help
void Init_help_tex();

// Hàm vẽ texture help lên màn hình
void Render_help_tex();

// Hàm hủy texture help
void Destroy_help_tex();

#endif