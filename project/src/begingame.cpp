// File: begingame.cpp
// Mục đích: Triển khai hàm tạo khối mới cho game.
// Vai trò: Thuộc mục 2 - Khởi tạo game ban đầu.

#include "begingame.h"
#include <cstdlib>

int lastTypes[5] = { -1, -1, -1, -1, -1 }; // Lưu 5 loại khối trước (-1 là chưa dùng)
int getRandomType(){
    int type;
    do{
        type = rand() % 7;
    } while ((type == lastTypes[0] && lastTypes[0] != -1) ||
        (type == lastTypes[1] && lastTypes[1] != -1) ||
        (type == lastTypes[2] && lastTypes[2] != -1) ||
        (type == lastTypes[3] && lastTypes[3] != -1) ||
        (type == lastTypes[4] && lastTypes[4] != -1));
    // Cập nhật mảng lastTypes
    for (int i = 4; i > 0; i--){
        lastTypes[i] = lastTypes[i - 1];
    }
    lastTypes[0] = type;
    return type;
}

// Hàm tạo một khối mới
struct Block Create_new_block(){
    // Tạo một khối mới
    struct Block block;
    // Đặt vị trí ban đầu của khối (căn giữa lưới Tetris)
    block.x = GRID_OFFSET_X + 3 * BLOCK_SIZE; // Vị trí x (giữa lưới)
    block.y = GRID_OFFSET_Y - 2 * BLOCK_SIZE; // Vị trí y (phía trên lưới)

    // Random một kiểu khối (từ 0 đến 6, tương ứng với 7 loại khối Tetris: I, O, T, S, Z, J, L)
    int type = getRandomType();
    // Khởi tạo ma trận 4x4 của khối, tất cả ban đầu là false (ô trống)
    for (int i = 0; i < MATRIX_SIZE; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            block.matrix[i][j] = false;
        }
    }

    // Dựa vào kiểu khối để gán hình dạng và màu sắc
    switch (type){
    case 0: // Khối I (dài thẳng đứng)
        block.matrix[2][0] = true;
        block.matrix[2][1] = true;
        block.matrix[2][2] = true;
        block.matrix[2][3] = true;
        block.color = { 0, 255, 255 }; // Màu Cyan
        break;
    case 1: // Khối O (hình vuông)
        block.matrix[1][1] = true;
        block.matrix[1][2] = true;
        block.matrix[2][1] = true;
        block.matrix[2][2] = true;
        block.color = { 255, 255, 0 }; // Màu Vàng
        break;
    case 2: // Khối T (hình chữ T)
        block.matrix[1][1] = true;
        block.matrix[2][0] = true;
        block.matrix[2][1] = true;
        block.matrix[2][2] = true;
        block.color = { 128, 0, 128 }; // Màu Tím
        break;
    case 3: // Khối S (hình zích zắc)
        block.matrix[1][1] = true;
        block.matrix[1][2] = true;
        block.matrix[2][0] = true;
        block.matrix[2][1] = true;
        block.color = { 0, 255, 0 }; // Màu Xanh lá
        break;
    case 4: // Khối Z (hình zích zắc ngược)
        block.matrix[1][0] = true;
        block.matrix[1][1] = true;
        block.matrix[2][1] = true;
        block.matrix[2][2] = true;
        block.color = { 255, 0, 0 }; // Màu Đỏ
        break;
    case 5: // Khối J (hình chữ J)
        block.matrix[1][0] = true;
        block.matrix[2][0] = true;
        block.matrix[2][1] = true;
        block.matrix[2][2] = true;
        block.color = { 0, 0, 255 }; // Màu Xanh dương
        break;
    case 6: // Khối L (hình chữ L)
        block.matrix[1][2] = true;
        block.matrix[2][0] = true;
        block.matrix[2][1] = true;
        block.matrix[2][2] = true;
        block.color = { 255, 165, 0 }; // Màu Cam
        break;
    }
    // Trả về khối đã tạo
    return block;
}