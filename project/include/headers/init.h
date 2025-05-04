// File: init.h
// Mục đích: Định nghĩa các hàm và biến toàn cục để khởi tạo và hủy tài nguyên SDL (cửa sổ, renderer, font).
// Vai trò: Thuộc mục 1 - Khởi tạo cửa sổ và renderer.

#ifndef INIT_H
#define INIT_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "background.h"
#include "overlay.h"
#include "sound_manager.h" // Thêm include mới

// Khai báo biến toàn cục (sử dụng extern để các file khác có thể truy cập)
extern SDL_Window* window;    // Con trỏ tới cửa sổ game (kích thước 1920x1080)
extern SDL_Renderer* renderer; // Con trỏ tới renderer dùng để vẽ lên cửa sổ
extern TTF_Font* font;        // Con trỏ tới font chữ (arial.ttf) dùng để hiển thị điểm số và thông báo
extern TTF_Font* font2;        // Con trỏ tới font chữ (arial.ttf) dùng để hiển thị điểm số và thông báo


// Hàm khởi tạo SDL, cửa sổ, renderer, font
void Initialize();
// Hàm hủy tài nguyên SDL khi kết thúc chương trình
void Destroy();

#endif