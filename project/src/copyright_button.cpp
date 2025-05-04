// File: copyright_button.cpp
// Mục đích: Triển khai các hàm để quản lý nút copyright trong giao diện menu.
// Vai trò: Thuộc mục giao diện menu.

#include "copyright_button.h"
#include <SDL_image.h>

SDL_Texture* copyright_texture = NULL;
SDL_Texture* copyright_hover_texture = NULL;

void Init_copyright_button(){
    SDL_Surface* surface = IMG_Load("res/Pictures/copyright_button.png");
    if (!surface){
        SDL_Log("Failed to load copyright_button: %s" , IMG_GetError());
        return;
    }
    copyright_texture = SDL_CreateTextureFromSurface(renderer , surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/Pictures/copyright_button1.png");
    if (!surface){
        SDL_Log("Failed to load copyright_button1: %s" , IMG_GetError());
        return;
    }
    copyright_hover_texture = SDL_CreateTextureFromSurface(renderer , surface);
    SDL_FreeSurface(surface);
}

void Render_copyright_button(int mouseX , int mouseY){
    bool isHover = (mouseX >= 411 && mouseX <= 411 + 339 && mouseY >= 557 && mouseY <= 557 + 75);
    SDL_Texture* current_texture = isHover ? copyright_hover_texture : copyright_texture;

    SDL_Rect dest = { 411, 557, 339, 75 };
    SDL_RenderCopy(renderer , current_texture , NULL , &dest);
}

void Destroy_copyright_button(){
    if (copyright_texture){
        SDL_DestroyTexture(copyright_texture);
        copyright_texture = NULL;
    }
    if (copyright_hover_texture){
        SDL_DestroyTexture(copyright_hover_texture);
        copyright_hover_texture = NULL;
    }
}