// File: help.cpp
// Mục đích: Triển khai các hàm để quản lý và hiển thị hình ảnh help.
// Vai trò: Hiển thị help trên màn hình.

#include "help.h"
#include <iostream>

// Biến toàn cục lưu texture của help
SDL_Texture* help_texture = NULL;
// Biến mới để lưu texture khi hover (help2.png)
SDL_Texture* help_hover_texture = NULL;

// Hàm khởi tạo help
void Init_help(){
    // Tải file help1.png làm texture mặc định
    SDL_Surface* help_surface = IMG_Load("res/Pictures/help1.png");
    if (!help_surface){
        SDL_Log("Failed to load help1: %s" , IMG_GetError());
        return;
    }
    help_texture = SDL_CreateTextureFromSurface(renderer , help_surface);
    SDL_FreeSurface(help_surface);

    // Tải file help2.png làm texture hover
    SDL_Surface* hover_surface = IMG_Load("res/Pictures/help2.png");
    if (!hover_surface){
        SDL_Log("Failed to load help2: %s" , IMG_GetError());
        return;
    }
    help_hover_texture = SDL_CreateTextureFromSurface(renderer , hover_surface);
    SDL_FreeSurface(hover_surface);
}

// Hàm vẽ help lên màn hình (thêm logic thay đổi khi hover)
void Render_help(int mouseX , int mouseY){
    // Kiểm tra nếu chuột nằm trong vùng của help (774, 686, 335x121)
    bool isHover = (mouseX >= 774 && mouseX <= 774 + 335 && mouseY >= 686 && mouseY <= 686 + 121);
    SDL_Texture* current_texture = isHover ? help_hover_texture : help_texture;

    // Tạo một hình chữ nhật với kích thước 335x121, vị trí (774, 686)
    SDL_Rect dest = { 774, 686, 335, 121 };
    // Vẽ texture hiện tại lên màn hình
    SDL_RenderCopy(renderer , current_texture , NULL , &dest);
}

// Hàm hủy tài nguyên help
void Destroy_help(){
    // Hủy cả hai texture
    if (help_texture){
        SDL_DestroyTexture(help_texture);
        help_texture = NULL;
    }
    if (help_hover_texture){
        SDL_DestroyTexture(help_hover_texture);
        help_hover_texture = NULL;
    }
}