// File: game_over.h
// Mục đích: Định nghĩa các hàm để quản lý texture game over trong giao diện game.
// Vai trò: Thuộc mục giao diện game.

#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <SDL.h>
#include <SDL_image.h>
#include "init.h"

extern SDL_Texture* game_over_texture;

// Hàm khởi tạo texture cho game over
void Init_game_over();

// Hàm vẽ texture game over lên màn hình
void Render_game_over();

// Hàm hủy texture game over
void Destroy_game_over();

#endif