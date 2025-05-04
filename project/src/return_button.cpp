// File: return_button.cpp
// Mục đích: Triển khai các hàm để quản lý và hiển thị nút return.
// Vai trò: Hiển thị nút return trên màn hình.

#include "return_button.h"
#include <iostream>

// Biến toàn cục lưu texture của nút return
SDL_Texture* return_button_texture = NULL;
// Biến lưu texture khi hover (return_button1.png)
SDL_Texture* return_button_hover_texture = NULL;

// Hàm khởi tạo nút return
void Init_return_button(){
    // Tải file return_button.png làm texture mặc định
    SDL_Surface* return_surface = IMG_Load("res/Pictures/return_button.png");
    if (!return_surface){
        SDL_Log("Failed to load return_button: %s" , IMG_GetError());
        return;
    }
    return_button_texture = SDL_CreateTextureFromSurface(renderer , return_surface);
    SDL_FreeSurface(return_surface);

    // Tải file return_button1.png làm texture hover
    SDL_Surface* hover_surface = IMG_Load("res/Pictures/return_button1.png");
    if (!hover_surface){
        SDL_Log("Failed to load return_button1: %s" , IMG_GetError());
        return;
    }
    return_button_hover_texture = SDL_CreateTextureFromSurface(renderer , hover_surface);
    SDL_FreeSurface(hover_surface);
}

// Hàm vẽ nút return lên màn hình (thêm logic thay đổi khi hover)
void Render_return_button(int mouseX , int mouseY){
    // Kiểm tra nếu chuột nằm trong vùng của nút return (123, 81, 96x94)
    bool isHover = (mouseX >= 123 && mouseX <= 123 + 96 && mouseY >= 81 && mouseY <= 81 + 94);
    SDL_Texture* current_texture = isHover ? return_button_hover_texture : return_button_texture;

    // Tạo một hình chữ nhật với kích thước 96x94, vị trí (123, 81)
    SDL_Rect dest = { 123, 81, 96, 94 };
    // Vẽ texture hiện tại lên màn hình
    SDL_RenderCopy(renderer , current_texture , NULL , &dest);
}

// Hàm hủy tài nguyên nút return
void Destroy_return_button(){
    // Hủy cả hai texture
    if (return_button_texture){
        SDL_DestroyTexture(return_button_texture);
        return_button_texture = NULL;
    }
    if (return_button_hover_texture){
        SDL_DestroyTexture(return_button_hover_texture);
        return_button_hover_texture = NULL;
    }
}