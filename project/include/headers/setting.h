// File: setting.h
// Mục đích: Định nghĩa các hàm để quản lý và hiển thị hình ảnh setting.
// Vai trò: Hiển thị setting trên màn hình.

#ifndef SETTING_H
#define SETTING_H

#include "init.h"
#include <SDL.h>
#include <SDL_image.h>

// Biến toàn cục lưu texture của setting
extern SDL_Texture* setting_texture;

// Hàm khởi tạo setting
void Init_setting();

// Hàm vẽ setting lên màn hình (thêm tham số hover)
void Render_setting(int mouseX , int mouseY);

// Hàm hủy tài nguyên setting
void Destroy_setting();

#endif