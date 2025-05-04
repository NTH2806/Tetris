// File: start.cpp
// Mục đích: Triển khai các hàm để quản lý và hiển thị hình ảnh start.
// Vai trò: Hiển thị start trên màn hình.

#include "start.h"
#include <iostream>

// Biến toàn cục lưu texture của start
SDL_Texture* start_texture = NULL;
// Biến mới để lưu texture khi hover (start2.png)
SDL_Texture* start_hover_texture = NULL;

// Hàm khởi tạo start
void Init_start(){
    // Tải file start1.png làm texture mặc định
    SDL_Surface* start_surface = IMG_Load("res/Pictures/start1.png");
    if (!start_surface){
        SDL_Log("Failed to load start1: %s" , IMG_GetError());
        return;
    }
    start_texture = SDL_CreateTextureFromSurface(renderer , start_surface);
    SDL_FreeSurface(start_surface);

    // Tải file start2.png làm texture hover
    SDL_Surface* hover_surface = IMG_Load("res/Pictures/start2.png");
    if (!hover_surface){
        SDL_Log("Failed to load start2: %s" , IMG_GetError());
        return;
    }
    start_hover_texture = SDL_CreateTextureFromSurface(renderer , hover_surface);
    SDL_FreeSurface(hover_surface);
}

// Hàm vẽ start lên màn hình (thêm logic thay đổi khi hover)
void Render_start(int mouseX , int mouseY){
    // Kiểm tra nếu chuột nằm trong vùng của start (521, 499, 335x121)
    bool isHover = (mouseX >= 521 && mouseX <= 521 + 335 && mouseY >= 499 && mouseY <= 499 + 121);
    SDL_Texture* current_texture = isHover ? start_hover_texture : start_texture;

    // Tạo một hình chữ nhật với kích thước 335x121, vị trí (521, 499)
    SDL_Rect dest = { 521, 499, 335, 121 };
    // Vẽ texture hiện tại lên màn hình
    SDL_RenderCopy(renderer , current_texture , NULL , &dest);
}

// Hàm hủy tài nguyên start
void Destroy_start(){
    // Hủy cả hai texture
    if (start_texture){
        SDL_DestroyTexture(start_texture);
        start_texture = NULL;
    }
    if (start_hover_texture){
        SDL_DestroyTexture(start_hover_texture);
        start_hover_texture = NULL;
    }
}