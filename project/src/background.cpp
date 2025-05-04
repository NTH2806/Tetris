// File: background.cpp
// Mục đích: Triển khai các hàm để quản lý hình nền của game.
// Vai trò: Thuộc mục 1 - Quản lý hình nền và layout.

#include "background.h"


// Biến toàn cục lưu texture của hình nền
SDL_Texture* background_texture = NULL;

// Hàm khởi tạo hình nền
void Init_background(){
    // Tải file hình ảnh cyber_background.png vào một surface
    SDL_Surface* surface = IMG_Load("res/Pictures/cyber_background.png");
    // Kiểm tra nếu không tải được hình ảnh thì ghi log lỗi
    if (!surface){
        SDL_Log("Failed to load background: %s" , IMG_GetError());
        return;
    }
    // Chuyển surface thành texture để renderer có thể sử dụng
    background_texture = SDL_CreateTextureFromSurface(renderer , surface);
    // Giải phóng surface vì không cần nữa
    SDL_FreeSurface(surface);
}

// Hàm vẽ hình nền lên màn hình
void Render_background(){
    // Tạo một hình chữ nhật với kích thước 1920x1080 (toàn màn hình)
    SDL_Rect dest = { 0, 0, 1920, 1080 };
    // Vẽ texture hình nền lên toàn bộ màn hình
    SDL_RenderCopy(renderer , background_texture , NULL , &dest);
}

// Hàm hủy tài nguyên hình nền
void Destroy_background(){
    // Kiểm tra nếu texture hình nền tồn tại thì hủy nó
    if (background_texture){
        SDL_DestroyTexture(background_texture);
        background_texture = NULL;
    }
}