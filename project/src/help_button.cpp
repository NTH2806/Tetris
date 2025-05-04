// File: help_button.cpp
// Mục đích: Triển khai các hàm để quản lý nút help trong giao diện menu.
// Vai trò: Thuộc mục giao diện menu.

#include "help_button.h"
#include <SDL_image.h>

SDL_Texture* help_texture2 = NULL;
SDL_Texture* help_hover_texture2 = NULL;

void Init_help_button(){
    SDL_Surface* surface = IMG_Load("res/Pictures/help_button.png");
    if (!surface){
        SDL_Log("Failed to load help_button: %s" , IMG_GetError());
        return;
    }
    help_texture2 = SDL_CreateTextureFromSurface(renderer , surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/Pictures/help_button2.png");
    if (!surface){
        SDL_Log("Failed to load help_button2: %s" , IMG_GetError());
        return;
    }
    help_hover_texture2 = SDL_CreateTextureFromSurface(renderer , surface);
    SDL_FreeSurface(surface);
}

void Render_help_button(int mouseX , int mouseY){
    bool isHover = (mouseX >= 411 && mouseX <= 411 + 339 && mouseY >= 473 && mouseY <= 473 + 75);
    SDL_Texture* current_texture = isHover ? help_hover_texture2 : help_texture2;

    SDL_Rect dest = { 411, 473, 339, 75 };
    SDL_RenderCopy(renderer , current_texture , NULL , &dest);
}

void Destroy_help_button(){
    if (help_texture2){
        SDL_DestroyTexture(help_texture2);
        help_texture2 = NULL;
    }
    if (help_hover_texture2){
        SDL_DestroyTexture(help_hover_texture2);
        help_hover_texture2 = NULL;
    }
}