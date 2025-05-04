// File: setting.cpp
// Mục đích: Triển khai các hàm để quản lý và hiển thị hình ảnh setting.
// Vai trò: Hiển thị setting trên màn hình.

#include "setting.h"
#include <iostream>

// Biến toàn cục lưu texture của setting
SDL_Texture* setting_texture = NULL;
// Biến mới để lưu texture khi hover (setting2.png)
SDL_Texture* setting_hover_texture = NULL;

// Hàm khởi tạo setting
void Init_setting(){
    // Tải file setting1.png làm texture mặc định
    SDL_Surface* setting_surface = IMG_Load("res/Pictures/setting1.png");
    if (!setting_surface){
        SDL_Log("Failed to load setting1: %s" , IMG_GetError());
        return;
    }
    setting_texture = SDL_CreateTextureFromSurface(renderer , setting_surface);
    SDL_FreeSurface(setting_surface);

    // Tải file setting2.png làm texture hover
    SDL_Surface* hover_surface = IMG_Load("res/Pictures/setting2.png");
    if (!hover_surface){
        SDL_Log("Failed to load setting2: %s" , IMG_GetError());
        return;
    }
    setting_hover_texture = SDL_CreateTextureFromSurface(renderer , hover_surface);
    SDL_FreeSurface(hover_surface);
}

// Hàm vẽ setting lên màn hình (thêm logic thay đổi khi hover)
void Render_setting(int mouseX , int mouseY){
    // Kiểm tra nếu chuột nằm trong vùng của setting (1026, 499, 335x121)
    bool isHover = (mouseX >= 1026 && mouseX <= 1026 + 335 && mouseY >= 499 && mouseY <= 499 + 121);
    SDL_Texture* current_texture = isHover ? setting_hover_texture : setting_texture;

    // Tạo một hình chữ nhật với kích thước 335x121, vị trí (1026, 499)
    SDL_Rect dest = { 1026, 499, 335, 121 };
    // Vẽ texture hiện tại lên màn hình
    SDL_RenderCopy(renderer , current_texture , NULL , &dest);
}

// Hàm hủy tài nguyên setting
void Destroy_setting(){
    // Hủy cả hai texture
    if (setting_texture){
        SDL_DestroyTexture(setting_texture);
        setting_texture = NULL;
    }
    if (setting_hover_texture){
        SDL_DestroyTexture(setting_hover_texture);
        setting_hover_texture = NULL;
    }
}