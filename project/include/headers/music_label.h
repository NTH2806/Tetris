// File: music_label.h
// Mục đích: Định nghĩa các hàm để hiển thị nhãn "MUSIC" màu xanh.
// Vai trò: Hiển thị nhãn trong trạng thái GAME.

#ifndef MUSIC_LABEL_H
#define MUSIC_LABEL_H

#include "tetris.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "init.h"

// Biến toàn cục lưu texture và font của nhãn MUSIC
extern SDL_Texture* music_label_texture;

// Hàm khởi tạo nhãn MUSIC
void Init_music_label();

// Hàm vẽ nhãn MUSIC lên màn hình
void Render_music_label();

// Hàm hủy tài nguyên nhãn MUSIC
void Destroy_music_label();

#endif