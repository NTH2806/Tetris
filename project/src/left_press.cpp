// File: left_press.cpp
// Mục đích: Triển khai các hàm để quản lý và hiển thị hình ảnh nút điều khiển trái.
// Vai trò: Hiển thị nút trái trên màn hình trong trạng thái GAME.

#include "left_press.h"
#include <iostream>


// Biến toàn cục lưu texture của nút trái
SDL_Texture* left_press_texture = NULL;
SDL_Texture* left_press_hover_texture = NULL;

// Hàm khởi tạo nút trái
void Init_left_press(){
    // Tải file leftPress1.png làm texture mặc định
    SDL_Surface* surface = IMG_Load("res/Pictures/leftPress1.png");
    if (!surface){
        SDL_Log("Failed to load leftPress1: %s" , IMG_GetError());
        return;
    }
    left_press_texture = SDL_CreateTextureFromSurface(renderer , surface);
    SDL_FreeSurface(surface);

    // Tải file leftPress.png làm texture hover
    SDL_Surface* hover_surface = IMG_Load("res/Pictures/leftPress.png");
    if (!hover_surface){
        SDL_Log("Failed to load leftPress: %s" , IMG_GetError());
        return;
    }
    left_press_hover_texture = SDL_CreateTextureFromSurface(renderer , hover_surface);
    SDL_FreeSurface(hover_surface);
}

// Hàm vẽ nút trái lên màn hình
void Render_left_press(int mouseX , int mouseY){
    // Kiểm tra nếu chuột nằm trong vùng của nút trái (1067, 472, 14x21)
    bool isHover = (mouseX >= 1067 && mouseX <= 1067 + 14 && mouseY >= 472 && mouseY <= 472 + 21);
    SDL_Texture* current_texture = isHover ? left_press_hover_texture : left_press_texture;

    // Tạo một hình chữ nhật với kích thước 14x21, vị trí (1067, 472)
    SDL_Rect dest = { 1067, 472, 14, 21 };
    // Vẽ texture hiện tại lên màn hình
    SDL_RenderCopy(renderer , current_texture , NULL , &dest);
}

// Hàm hủy tài nguyên nút trái
void Destroy_left_press(){
    // Hủy cả hai texture
    if (left_press_texture){
        SDL_DestroyTexture(left_press_texture);
        left_press_texture = NULL;
    }
    if (left_press_hover_texture){
        SDL_DestroyTexture(left_press_hover_texture);
        left_press_hover_texture = NULL;
    }
}