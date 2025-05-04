// File: begingame.h
// Mục đích: Định nghĩa hàm và biến để tạo khối mới cho game.
// Vai trò: Thuộc mục 2 - Khởi tạo game ban đầu.

#ifndef BEGINGAME_H
#define BEGINGAME_H

#include <SDL.h>
#include "tetris.h"

// Hàm tạo một khối mới (random kiểu khối và màu sắc)
struct Block Create_new_block();
int getRandomType();

#endif