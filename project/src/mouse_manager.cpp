// File: mouse_manager.cpp
// Mục đích: Triển khai các hàm để quản lý hiển thị và tương tác của con chuột trong game.
// Vai trò: Quản lý giao diện chuột.

#include "mouse_manager.h"
#include <iostream>

// Biến toàn cục lưu vị trí chuột
int mouseX = 0 , mouseY = 0;

void Init_mouse_manager(){
    // Không cần khởi tạo gì thêm vì không có nút bấm
    mouseX = 0;
    mouseY = 0;
}

void Handle_mouse_events(SDL_Event* event){
    if (event->type == SDL_MOUSEMOTION){
        // Cập nhật vị trí chuột
        mouseX = event->motion.x;
        mouseY = event->motion.y;
    }
    else if (event->type == SDL_MOUSEBUTTONDOWN){
        if (event->button.button == SDL_BUTTON_LEFT){
            // Hiện tại không có nút, chỉ ghi nhận sự kiện nhấn chuột
            std::cout << "Mouse clicked at (" << mouseX << ", " << mouseY << ")" << std::endl;
        }
    }
    else if (event->type == SDL_MOUSEBUTTONUP){
        if (event->button.button == SDL_BUTTON_LEFT){
            // Ghi nhận sự kiện thả chuột
            std::cout << "Mouse released at (" << mouseX << ", " << mouseY << ")" << std::endl;
        }
    }
}

void Destroy_mouse_manager(){
    // Hiện tại không có tài nguyên nào cần hủy
}