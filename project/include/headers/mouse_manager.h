// File: mouse_manager.h
// Mục đích: Định nghĩa các hàm và biến để quản lý hiển thị và tương tác của con chuột.
// Vai trò: Quản lý giao diện chuột.

#ifndef MOUSE_MANAGER_H
#define MOUSE_MANAGER_H

#include <SDL.h>

// Biến toàn cục lưu vị trí chuột
extern int mouseX;
extern int mouseY;

// Hàm khởi tạo quản lý chuột
void Init_mouse_manager();

// Hàm xử lý sự kiện chuột
void Handle_mouse_events(SDL_Event* event);

// Hàm hủy tài nguyên quản lý chuột
void Destroy_mouse_manager();

#endif