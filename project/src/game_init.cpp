// File: game_init.cpp
// Mục đích: Triển khai hàm khởi tạo trạng thái ban đầu của game.
// Vai trò: Thuộc mục 2 - Khởi tạo game ban đầu.

#include "game_init.h"
#include <game_over.h>

// Hàm khởi tạo trạng thái game ban đầu
void Initialize_game(){
    // Đặt điểm số ban đầu về 0
    score = 0;
    lines = 0;
    finalscore = 0;
    // Đặt trạng thái game over thành false (game chưa kết thúc)
    game_over = false;
    // Tạo một khối mới để bắt đầu game
    Current_block = Create_new_block();
    // Nếu texture điểm số đã tồn tại, hủy nó để tránh rò rỉ bộ nhớ
    if (score_texture != NULL){
        SDL_DestroyTexture(score_texture);
        score_texture = NULL;
    }
    if (line_texture != NULL){
        SDL_DestroyTexture(line_texture);
        line_texture = NULL;
    }
    if (finalscore_texture != NULL){
        SDL_DestroyTexture(finalscore_texture);
        finalscore_texture = NULL;
    }
    // Đặt giá trị last_score về -1 để buộc vẽ lại điểm số ở lần đầu
    last_score = -1;
    last_lines = -1;
    last_finalscore = -1;

}

void Reset_grid(){
    for (int y = 0; y < HANG; y++){
        for (int x = 0; x < COT; x++){
            grid[y][x] = { 0, 0, 0 };
        }
    }
}