// File: help_tex.cpp
// Mục đích: Triển khai các hàm để quản lý texture help trong giao diện help.
// Vai trò: Thuộc mục giao diện help.

#include "help_tex.h"
#include <SDL_image.h>

SDL_Texture* help_tex_texture = NULL;

void Init_help_tex(){
    SDL_Surface* surface = IMG_Load("res/Pictures/help_tex.png");
    if (!surface){
        SDL_Log("Failed to load help_tex: %s" , IMG_GetError());
        return;
    }
    help_tex_texture = SDL_CreateTextureFromSurface(renderer , surface);
    SDL_FreeSurface(surface);
}

void Render_help_tex(){
    SDL_Rect dest = { 0, 0, 1920, 1080 };
    SDL_RenderCopy(renderer , help_tex_texture , NULL , &dest);
}

void Destroy_help_tex(){
    if (help_tex_texture){
        SDL_DestroyTexture(help_tex_texture);
        help_tex_texture = NULL;
    }
}