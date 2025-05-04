// File: tabs_setting.h
// Mục đích: Định nghĩa các hàm để quản lý và hiển thị tabs setting.
// Vai trò: Hiển thị tabs setting trên màn hình.

#ifndef TABS_SETTING_H
#define TABS_SETTING_H

#include "init.h"
#include <SDL.h>
#include <SDL_image.h>

// Biến toàn cục lưu texture của tabs setting
extern SDL_Texture* tabs_setting_texture;

// Hàm khởi tạo tabs setting
void Init_tabs_setting();

// Hàm vẽ tabs setting lên màn hình
void Render_tabs_setting();

// Hàm hủy tài nguyên tabs setting
void Destroy_tabs_setting();

#endif