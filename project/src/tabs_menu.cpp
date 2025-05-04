// File: tabs_menu.cpp
// Mục đích: Triển khai các hàm để quản lý và hiển thị tabs menu.
// Vai trò: Hiển thị tabs menu trên màn hình.

#include "tabs_menu.h"
#include <iostream>

// Biến toàn cục lưu texture của tabs menu
SDL_Texture* tabs_menu_texture = NULL;

// Hàm khởi tạo tabs menu
void Init_tabs_menu(){
    // Tải file hình ảnh tabs_menu.png vào một surface
    SDL_Surface* surface = IMG_Load("res/Pictures/tabs_menu.png");
    // Kiểm tra nếu không tải được hình ảnh thì ghi log lỗi
    if (!surface){
        SDL_Log("Failed to load tabs menu: %s" , IMG_GetError());
        return;
    }
    // Chuyển surface thành texture để renderer có thể sử dụng
    tabs_menu_texture = SDL_CreateTextureFromSurface(renderer , surface);
    // Giải phóng surface vì không cần nữa
    SDL_FreeSurface(surface);
}

// Hàm vẽ tabs menu lên màn hình
void Render_tabs_menu(){
    // Tạo một hình chữ nhật với kích thước 1920x1080 (toàn màn hình)
    SDL_Rect dest = { 0, 0, 1920, 1080 };
    // Vẽ texture tabs menu lên toàn bộ màn hình, nằm trên logo
    SDL_RenderCopy(renderer , tabs_menu_texture , NULL , &dest);
}

// Hàm hủy tài nguyên tabs menu
void Destroy_tabs_menu(){
    // Kiểm tra nếu texture tabs menu tồn tại thì hủy nó
    if (tabs_menu_texture){
        SDL_DestroyTexture(tabs_menu_texture);
        tabs_menu_texture = NULL;
    }
}