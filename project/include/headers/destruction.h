// File: destruction.h
// Mục đích: Định nghĩa hàm dọn dẹp tài nguyên khi kết thúc game.
// Vai trò: Thuộc mục 5 - Hủy bỏ kết thúc chương trình.

#ifndef DESTRUCTION_H
#define DESTRUCTION_H

#include "init.h"
#include "game_state.h"

// Hàm dọn dẹp tài nguyên (texture, SDL, v.v.) khi kết thúc game
void Clean_up_game();

#endif