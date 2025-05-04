// File: right_press.h
// Mục đích: Định nghĩa các hàm để quản lý và hiển thị hình ảnh nút điều khiển phải.
// Vai trò: Hiển thị nút phải trên màn hình trong trạng thái GAME.

#ifndef RIGHT_PRESS_H
#define RIGHT_PRESS_H

#include "tetris.h"
#include <SDL.h>
#include <SDL_image.h>
#include "init.h"

// Biến toàn cục lưu texture của nút phải
extern SDL_Texture* right_press_texture;
extern SDL_Texture* right_press_hover_texture;

// Hàm khởi tạo nút phải
void Init_right_press();

// Hàm vẽ nút phải lên màn hình (thêm tham số hover)
void Render_right_press(int mouseX , int mouseY);

// Hàm hủy tài nguyên nút phải
void Destroy_right_press();

#endif