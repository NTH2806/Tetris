// File: overlay.cpp
// Mục đích: Triển khai các hàm để quản lý layout của game.
// Vai trò: Thuộc mục 1 - Quản lý hình nền và layout.

#include "overlay.h"

// Biến toàn cục lưu texture của layout
SDL_Texture* overlay_texture = NULL;

// Hàm khởi tạo layout
void Init_overlay(){
    // Tải file hình ảnh GridFrame.png vào một surface
    SDL_Surface* surface = IMG_Load("res/Pictures/GridFrame.png");
    // Kiểm tra nếu không tải được hình ảnh thì ghi log lỗi
    if (!surface){
        SDL_Log("Failed to load overlay: %s" , IMG_GetError());
        return;
    }
    // Chuyển surface thành texture để renderer có thể sử dụng
    overlay_texture = SDL_CreateTextureFromSurface(renderer , surface);
    // Giải phóng surface vì không cần nữa
    SDL_FreeSurface(surface);
}

// Hàm vẽ layout lên màn hình
void Render_overlay(){
    // Tạo một hình chữ nhật với kích thước 1920x1080 (toàn màn hình)
    SDL_Rect dest = { 0, 0, 1920, 1080 };
    // Vẽ texture layout lên toàn bộ màn hình, nằm trên hình nền
    SDL_RenderCopy(renderer , overlay_texture , NULL , &dest);
}

// Hàm hủy tài nguyên layout
void Destroy_overlay(){
    // Kiểm tra nếu texture layout tồn tại thì hủy nó
    if (overlay_texture){
        SDL_DestroyTexture(overlay_texture);
        overlay_texture = NULL;
    }
}