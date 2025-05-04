// File: copyright_tex.h
// Mục đích: Định nghĩa các hàm để quản lý texture copyright trong giao diện help.
// Vai trò: Thuộc mục giao diện help.

#ifndef COPYRIGHT_TEX_H
#define COPYRIGHT_TEX_H

#include <SDL.h>
#include <SDL_image.h>
#include "init.h"

extern SDL_Texture* copyright_tex_texture;

// Hàm khởi tạo texture cho copyright
void Init_copyright_tex();

// Hàm vẽ texture copyright lên màn hình
void Render_copyright_tex();

// Hàm hủy texture copyright
void Destroy_copyright_tex();

#endif