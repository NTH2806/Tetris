// File: left_press.h
// Mục đích: Định nghĩa các hàm để quản lý và hiển thị hình ảnh nút điều khiển trái.
// Vai trò: Hiển thị nút trái trên màn hình trong trạng thái GAME.

#ifndef LEFT_PRESS_H
#define LEFT_PRESS_H

#include "tetris.h"
#include <SDL.h>
#include <SDL_image.h>
#include "init.h"

// Biến toàn cục lưu texture của nút trái
extern SDL_Texture* left_press_texture;
extern SDL_Texture* left_press_hover_texture;

// Hàm khởi tạo nút trái
void Init_left_press();

// Hàm vẽ nút trái lên màn hình (thêm tham số hover)
void Render_left_press(int mouseX , int mouseY);

// Hàm hủy tài nguyên nút trái
void Destroy_left_press();

#endif