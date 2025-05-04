// File: music_label.cpp
// Mục đích: Triển khai các hàm để hiển thị nhãn "MUSIC" màu xanh.
// Vai trò: Hiển thị nhãn trong trạng thái GAME.

#include "music_label.h"
#include <iostream>

// Biến toàn cục lưu texture và font của nhãn MUSIC
SDL_Texture* music_label_texture = NULL;

// Hàm khởi tạo nhãn MUSIC
void Init_music_label(){
    // Tạo surface cho văn bản "MUSIC" màu xanh (0, 255, 255)
    SDL_Surface* surface = TTF_RenderText_Solid(font2 , "MUSIC" , { 0, 255, 255 });
    if (!surface){
        SDL_Log("Failed to create MUSIC surface: %s" , TTF_GetError());
        return;
    }

    // Tạo texture từ surface
    music_label_texture = SDL_CreateTextureFromSurface(renderer , surface);
    SDL_FreeSurface(surface);
}

// Hàm vẽ nhãn MUSIC lên màn hình
void Render_music_label(){
    if (!music_label_texture){
        return;
    }

    // Tạo hình chữ nhật tại (752, 472) với kích thước tự động
    SDL_Rect dest = { 752, 472, 0, 0 };
    SDL_QueryTexture(music_label_texture , NULL , NULL , &dest.w , &dest.h);

    // Vẽ texture lên màn hình
    SDL_RenderCopy(renderer , music_label_texture , NULL , &dest);
}

// Hàm hủy tài nguyên nhãn MUSIC
void Destroy_music_label(){
    if (music_label_texture){
        SDL_DestroyTexture(music_label_texture);
        music_label_texture = NULL;
    }
}