// File: help_button.h
// Mục đích: Định nghĩa các hàm để quản lý nút help trong giao diện menu.
// Vai trò: Thuộc mục giao diện menu.

#ifndef HELP_BUTTON_H
#define HELP_BUTTON_H

#include <SDL.h>
#include <SDL_image.h>
#include <init.h>
extern SDL_Texture* help_texture2;
extern SDL_Texture* help_hover_texture2;

// Hàm khởi tạo texture cho nút help
void Init_help_button();

// Hàm vẽ nút help, thay đổi texture khi chuột hover
void Render_help_button(int mouseX , int mouseY);

// Hàm hủy texture nút help
void Destroy_help_button();

#endif