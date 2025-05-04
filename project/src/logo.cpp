// File: logo.cpp
// Mục đích: Triển khai các hàm để quản lý và hiển thị logo.
// Vai trò: Hiển thị logo trên màn hình.

#include "logo.h"
#include <iostream>

// Biến toàn cục lưu texture của logo
SDL_Texture* logo_texture = NULL;

// Hàm khởi tạo logo
void Init_logo(){
    // Tải file hình ảnh logo.png vào một surface
    SDL_Surface* surface = IMG_Load("res/Pictures/logo.png");
    // Kiểm tra nếu không tải được hình ảnh thì ghi log lỗi
    if (!surface){
        SDL_Log("Failed to load logo: %s" , IMG_GetError());
        return;
    }
    // Chuyển surface thành texture để renderer có thể sử dụng
    logo_texture = SDL_CreateTextureFromSurface(renderer , surface);
    // Giải phóng surface vì không cần nữa
    SDL_FreeSurface(surface);
}

// Hàm vẽ logo lên màn hình
void Render_logo(){
    // Tạo một hình chữ nhật với kích thước 1920x1080 (toàn màn hình)
    SDL_Rect dest = { 0, 0, 1920, 1080 };
    // Vẽ texture logo lên toàn bộ màn hình, nằm trên hình nền
    SDL_RenderCopy(renderer , logo_texture , NULL , &dest);
}

// Hàm hủy tài nguyên logo
void Destroy_logo(){
    // Kiểm tra nếu texture logo tồn tại thì hủy nó
    if (logo_texture){
        SDL_DestroyTexture(logo_texture);
        logo_texture = NULL;
    }
}