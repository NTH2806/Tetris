// File: destruction.cpp
// Mục đích: Triển khai hàm dọn dẹp tài nguyên khi kết thúc game.
// Vai trò: Thuộc mục 5 - Hủy bỏ kết thúc chương trình.

#include "destruction.h"


// Hàm dọn dẹp tài nguyên khi kết thúc game
void Clean_up_game(){
    // Hủy texture điểm số nếu tồn tại
    if (score_texture){
        SDL_DestroyTexture(score_texture);
        score_texture = NULL;
    }
    // Gọi hàm Destroy để hủy các tài nguyên SDL (cửa sổ, renderer, font)
    Destroy();
}