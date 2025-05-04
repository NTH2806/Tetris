// File: tabs_menu.h
// Mục đích: Định nghĩa các hàm để quản lý và hiển thị tabs menu.
// Vai trò: Hiển thị tabs menu trên màn hình.

#ifndef TABS_MENU_H
#define TABS_MENU_H

#include "init.h"
#include <SDL.h>
#include <SDL_image.h>

// Biến toàn cục lưu texture của tabs menu
extern SDL_Texture* tabs_menu_texture;

// Hàm khởi tạo tabs menu
void Init_tabs_menu();

// Hàm vẽ tabs menu lên màn hình
void Render_tabs_menu();

// Hàm hủy tài nguyên tabs menu
void Destroy_tabs_menu();

#endif