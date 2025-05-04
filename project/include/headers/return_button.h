// File: return_button.h
// Mục đích: Định nghĩa các hàm để quản lý và hiển thị nút return.
// Vai trò: Hiển thị nút return trên màn hình.

#ifndef RETURN_BUTTON_H
#define RETURN_BUTTON_H

#include "init.h"
#include <SDL.h>
#include <SDL_image.h>

// Biến toàn cục lưu texture của nút return
extern SDL_Texture* return_button_texture;
// Biến lưu texture khi hover
extern SDL_Texture* return_button_hover_texture;

// Hàm khởi tạo nút return
void Init_return_button();

// Hàm vẽ nút return lên màn hình (thêm tham số hover)
void Render_return_button(int mouseX , int mouseY);

// Hàm hủy tài nguyên nút return
void Destroy_return_button();

#endif