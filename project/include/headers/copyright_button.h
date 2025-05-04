// File: copyright_button.h
// Mục đích: Định nghĩa các hàm để quản lý nút copyright trong giao diện menu.
// Vai trò: Thuộc mục giao diện menu.

#ifndef COPYRIGHT_BUTTON_H
#define COPYRIGHT_BUTTON_H

#include <SDL.h>
#include <SDL_image.h>
#include "init.h"

// Hàm khởi tạo texture cho nút copyright
void Init_copyright_button();

// Hàm vẽ nút copyright, thay đổi texture khi chuột hover
void Render_copyright_button(int mouseX , int mouseY);

// Hàm hủy texture nút copyright
void Destroy_copyright_button();

#endif