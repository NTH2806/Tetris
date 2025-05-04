// File: game_loop.h
// Mục đích: Định nghĩa các hàm xử lý vòng lặp chính của game (xử lý sự kiện, cập nhật, vẽ).
// Vai trò: Thuộc mục 4 - Vòng lặp chính của game.

#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "game_state.h"
#include "return_button.h"
#include "tetris.h"
#include "background.h"
#include "overlay.h"
#include "init.h"
#include "overlay.h"
#include "logo.h"
#include "tabs_menu.h"
#include "background.h"
#include "start.h"
#include "setting.h"
#include "help.h"
#include "begingame.h"
#include "mouse_manager.h" // Vẫn cần để xử lý sự kiện chuột

// Hàm xoay ma trận 4x4 của khối (90 độ theo chiều kim đồng hồ)
void transPos(bool matrix[MATRIX_SIZE][MATRIX_SIZE]);
// Hàm xử lý chồng chéo khối sau khi xoay
void fixTheSuperimposed(struct Block* block);
// Hàm xử lý các sự kiện (nhấn phím, thoát game)
void Handle_events();
// Hàm cập nhật trạng thái game (di chuyển khối, kiểm tra va chạm, game over)
void Update_game();
// Hàm vẽ game lên màn hình (hình nền, layout, lưới, khối, điểm số)
void Render_game();

#endif