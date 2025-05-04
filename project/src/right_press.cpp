// File: right_press.cpp
// Mục đích: Triển khai các hàm để quản lý và hiển thị hình ảnh nút điều khiển phải.
// Vai trò: Hiển thị nút phải trên màn hình trong trạng thái GAME.

#include "right_press.h"
#include <iostream>

// Biến toàn cục lưu texture của nút phải
SDL_Texture* right_press_texture = NULL;
SDL_Texture* right_press_hover_texture = NULL;

// Hàm khởi tạo nút phải
void Init_right_press(){
    // Tải file rightPress1.png làm texture mặc định
    SDL_Surface* surface = IMG_Load("res/Pictures/rightPress1.png");
    if (!surface){
        SDL_Log("Failed to load rightPress1: %s" , IMG_GetError());
        return;
    }
    right_press_texture = SDL_CreateTextureFromSurface(renderer , surface);
    SDL_FreeSurface(surface);

    // Tải file rightPress.png làm texture hover
    SDL_Surface* hover_surface = IMG_Load("res/Pictures/rightPress.png");
    if (!hover_surface){
        SDL_Log("Failed to load rightPress: %s" , IMG_GetError());
        return;
    }
    right_press_hover_texture = SDL_CreateTextureFromSurface(renderer , hover_surface);
    SDL_FreeSurface(hover_surface);
}

// Hàm vẽ nút phải lên màn hình
void Render_right_press(int mouseX , int mouseY){
    // Kiểm tra nếu chuột nằm trong vùng của nút phải (1293, 472, 14x21)
    bool isHover = (mouseX >= 1293 && mouseX <= 1293 + 14 && mouseY >= 472 && mouseY <= 472 + 21);
    SDL_Texture* current_texture = isHover ? right_press_hover_texture : right_press_texture;

    // Tạo một hình chữ nhật với kích thước 14x21, vị trí (1293, 472)
    SDL_Rect dest = { 1293, 472, 14, 21 };
    // Vẽ texture hiện tại lên màn hình
    SDL_RenderCopy(renderer , current_texture , NULL , &dest);
}

// Hàm hủy tài nguyên nút phải
void Destroy_right_press(){
    // Hủy cả hai texture
    if (right_press_texture){
        SDL_DestroyTexture(right_press_texture);
        right_press_texture = NULL;
    }
    if (right_press_hover_texture){
        SDL_DestroyTexture(right_press_hover_texture);
        right_press_hover_texture = NULL;
    }
}