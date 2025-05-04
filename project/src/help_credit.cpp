// File: help_credit.cpp
// Mục đích: Triển khai các hàm để quản lý và hiển thị help credit.
// Vai trò: Hiển thị help credit trên màn hình.

#include "help_credit.h"
#include <iostream>

// Biến toàn cục lưu texture của help credit
SDL_Texture* help_credit_texture = NULL;

// Hàm khởi tạo help credit
void Init_help_credit(){
    // Tải file hình ảnh help_credit.png vào một surface
    SDL_Surface* surface = IMG_Load("res/Pictures/help_credit.png");
    // Kiểm tra nếu không tải được hình ảnh thì ghi log lỗi
    if (!surface){
        SDL_Log("Failed to load help credit: %s" , IMG_GetError());
        return;
    }
    // Chuyển surface thành texture để renderer có thể sử dụng
    help_credit_texture = SDL_CreateTextureFromSurface(renderer , surface);
    // Giải phóng surface vì không cần nữa
    SDL_FreeSurface(surface);
}

// Hàm vẽ help credit lên màn hình
void Render_help_credit(){
    // Tạo một hình chữ nhật với kích thước 1920x1080 (toàn màn hình)
    SDL_Rect dest = { 0, 0, 1920, 1080 };
    // Vẽ texture help credit lên toàn bộ màn hình
    SDL_RenderCopy(renderer , help_credit_texture , NULL , &dest);
}

// Hàm hủy tài nguyên help credit
void Destroy_help_credit(){
    // Kiểm tra nếu texture help credit tồn tại thì hủy nó
    if (help_credit_texture){
        SDL_DestroyTexture(help_credit_texture);
        help_credit_texture = NULL;
    }
}