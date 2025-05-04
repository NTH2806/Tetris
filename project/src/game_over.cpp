// File: game_over.cpp
// Mục đích: Triển khai các hàm để quản lý texture game over trong giao diện game.
// Vai trò: Thuộc mục giao diện game.

#include "game_over.h"
#include <SDL_image.h>

SDL_Texture* game_over_texture = NULL;

void Init_game_over(){
    SDL_Surface* surface = IMG_Load("res/Pictures/game_over.png");
    if (!surface){
        SDL_Log("Failed to load game_over: %s" , IMG_GetError());
        return;
    }
    game_over_texture = SDL_CreateTextureFromSurface(renderer , surface);
    SDL_FreeSurface(surface);
}

void Render_game_over(){
    SDL_Rect dest = { 0, 0, 1920, 1080 };
    SDL_RenderCopy(renderer , game_over_texture , NULL , &dest);
}

void Destroy_game_over(){
    if (game_over_texture){
        SDL_DestroyTexture(game_over_texture);
        game_over_texture = NULL;
    }
}