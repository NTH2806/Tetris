// File: copyright_tex.cpp
// Mục đích: Triển khai các hàm để quản lý texture copyright trong giao diện help.
// Vai trò: Thuộc mục giao diện help.

#include "copyright_tex.h"
#include <SDL_image.h>

SDL_Texture* copyright_tex_texture = NULL;

void Init_copyright_tex(){
    SDL_Surface* surface = IMG_Load("res/Pictures/copyright_tex.png");
    if (!surface){
        SDL_Log("Failed to load copyright_tex: %s", IMG_GetError());
        return;
    }
    copyright_tex_texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

void Render_copyright_tex(){
    SDL_Rect dest = {0, 0, 1920, 1080};
    SDL_RenderCopy(renderer, copyright_tex_texture, NULL, &dest);
}

void Destroy_copyright_tex(){
    if (copyright_tex_texture){
        SDL_DestroyTexture(copyright_tex_texture);
        copyright_tex_texture = NULL;
    }
}