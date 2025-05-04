// File: tabs_setting.cpp
// Mục đích: Triển khai các hàm để quản lý và hiển thị tabs setting.
// Vai trò: Hiển thị tabs setting trên màn hình.

#include "tabs_setting.h"
#include <iostream>

// Biến toàn cục lưu texture của tabs setting
SDL_Texture* tabs_setting_texture = NULL;

// Hàm khởi tạo tabs setting
void Init_tabs_setting(){
    // Tải file hình ảnh tabs_setting.png vào một surface
    SDL_Surface* surface = IMG_Load("res/Pictures/tabs_setting.png");
    // Kiểm tra nếu không tải được hình ảnh thì ghi log lỗi
    if (!surface){
        SDL_Log("Failed to load tabs setting: %s" , IMG_GetError());
        return;
    }
    // Chuyển surface thành texture để renderer có thể sử dụng
    tabs_setting_texture = SDL_CreateTextureFromSurface(renderer , surface);
    // Giải phóng surface vì không cần nữa
    SDL_FreeSurface(surface);
}

// Hàm vẽ tabs setting lên màn hình
void Render_tabs_setting(){
    // Tạo một hình chữ nhật với kích thước 1920x1080 (toàn màn hình)
    SDL_Rect dest = { 0, 0, 1920, 1080 };
    // Vẽ texture tabs setting lên toàn bộ màn hình
    SDL_RenderCopy(renderer , tabs_setting_texture , NULL , &dest);
}

// Hàm hủy tài nguyên tabs setting
void Destroy_tabs_setting(){
    // Kiểm tra nếu texture tabs setting tồn tại thì hủy nó
    if (tabs_setting_texture){
        SDL_DestroyTexture(tabs_setting_texture);
        tabs_setting_texture = NULL;
    }
}