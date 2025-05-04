// File: tetris.h
// Mục đích: Định nghĩa các hàm và biến để quản lý lưới Tetris và logic game (va chạm, khóa khối, xóa hàng).
// Vai trò: Thuộc mục 4 - Quản lý logic Tetris trong vòng lặp chính.

#ifndef TETRIS_H
#define TETRIS_H

#include <SDL.h>
#include "begingame.h"

// Kích thước ô trong lưới (40x40 pixel)
#define BLOCK_SIZE 40
// Vị trí lưới trên màn hình (căn giữa trong 1920x1080)
#define GRID_OFFSET_X 760 // (1920 - 400) / 2
#define GRID_OFFSET_Y 140 // (1080 - 800) / 2
// Kích thước lưới (10 cột x 20 hàng)
#define COT 10
#define HANG 20
// Kích thước ma trận của khối (4x4)
#define MATRIX_SIZE 4

// Cấu trúc Color lưu màu sắc của khối (RGB)
struct Color{
    Uint8 r , g , b; // Thành phần màu: đỏ (r), xanh lá (g), xanh dương (b)
};

// Cấu trúc Block lưu thông tin của một khối Tetris
struct Block{
    int x , y;                          // Tọa độ của khối trên màn hình (pixel)
    bool matrix[MATRIX_SIZE][MATRIX_SIZE]; // Ma trận 4x4 biểu diễn hình dạng khối
    struct Color color;                // Màu sắc của khối
    SDL_Rect collin;                   // Hình chữ nhật bao quanh khối (dùng để kiểm tra va chạm)
};

// Khai báo lưới Tetris (mảng 2D lưu màu sắc của các ô đã khóa)
extern Color grid[HANG][COT];

// Hàm kiểm tra va chạm giữa khối và lưới (truyền vào khối)
bool Check_collision(struct Block block);
// Hàm kiểm tra va chạm (truyền vào con trỏ khối)
bool Check_collision(struct Block* block);
// Hàm khóa khối vào lưới (gán màu sắc vào lưới)
void Lock_block(struct Block block);
// Hàm xóa các hàng đầy và trả về số hàng đã xóa
int Clear_full_lines();

#endif