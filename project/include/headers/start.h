// File: start.h
// Mục đích: Định nghĩa các hàm để quản lý và hiển thị hình ảnh start.
// Vai trò: Hiển thị start trên màn hình.

#ifndef START_H
#define START_H

#include "init.h"
#include <SDL.h>
#include <SDL_image.h>

// Biến toàn cục lưu texture của start
extern SDL_Texture* start_texture;

// Hàm khởi tạo start
void Init_start();

// Hàm vẽ start lên màn hình (thêm tham số hover)
void Render_start(int mouseX , int mouseY);

// Hàm hủy tài nguyên start
void Destroy_start();

#endif