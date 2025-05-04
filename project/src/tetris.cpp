// File: tetris.cpp
// Mục đích: Triển khai các hàm quản lý lưới Tetris và logic game.
// Vai trò: Thuộc mục 4 - Quản lý logic Tetris trong vòng lặp chính.

#include "tetris.h"

// Định nghĩa lưới Tetris (khởi tạo tất cả các ô với màu đen - không có khối)
Color grid[HANG][COT] = { 0 };

// Hàm kiểm tra va chạm giữa khối và lưới
bool Check_collision(struct Block block){
    // Duyệt qua ma trận 4x4 của khối
    for (int i = 0; i < MATRIX_SIZE; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            if (block.matrix[i][j]){ // Nếu ô trong ma trận là true (có khối)
                // Tính vị trí ô trên lưới Tetris
                int gridX = (block.x + j * BLOCK_SIZE - GRID_OFFSET_X) / BLOCK_SIZE;
                int gridY = (block.y + i * BLOCK_SIZE - GRID_OFFSET_Y) / BLOCK_SIZE;

                // Kiểm tra nếu ô nằm ngoài lưới (trái, phải, dưới)
                if (gridX < 0 || gridX >= COT || gridY >= HANG){
                    return true; // Có va chạm
                }

                // Kiểm tra nếu ô trên lưới đã có khối (đã khóa)
                if (gridY >= 0 && (grid[gridY][gridX].r != 0 || grid[gridY][gridX].g != 0 || grid[gridY][gridX].b != 0)){
                    return true; // Có va chạm
                }
            }
        }
    }
    return false; // Không va chạm
}

// Hàm kiểm tra va chạm (phiên bản truyền con trỏ khối)
bool Check_collision(struct Block* block){
    // Gọi phiên bản truyền tham trị
    return Check_collision(*block);
}

// Hàm khóa khối vào lưới
void Lock_block(struct Block block){
    // Duyệt qua ma trận 4x4 của khối
    for (int i = 0; i < MATRIX_SIZE; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            if (block.matrix[i][j]){ // Nếu ô trong ma trận là true
                // Tính vị trí ô trên lưới
                int gridX = (block.x + j * BLOCK_SIZE - GRID_OFFSET_X) / BLOCK_SIZE;
                int gridY = (block.y + i * BLOCK_SIZE - GRID_OFFSET_Y) / BLOCK_SIZE;
                // Nếu ô nằm trong lưới, gán màu sắc của khối vào ô đó
                if (gridY >= 0 && gridY < HANG && gridX >= 0 && gridX < COT){
                    grid[gridY][gridX] = block.color;
                }
            }
        }
    }
}

// Hàm xóa các hàng đầy và trả về số hàng đã xóa
int Clear_full_lines(){
    int linesCleared = 0; // Số hàng đã xóa
    // Duyệt qua từng hàng từ dưới lên
    for (int y = HANG - 1; y >= 0; y--){
        bool full = true; // Giả sử hàng đầy
        // Kiểm tra xem hàng có đầy không
        for (int x = 0; x < COT; x++){
            if (grid[y][x].r == 0 && grid[y][x].g == 0 && grid[y][x].b == 0){
                full = false; // Nếu có ô trống, hàng không đầy
                break;
            }
        }
        if (full){ // Nếu hàng đầy
            linesCleared++; // Tăng số hàng đã xóa
            // Di chuyển các hàng phía trên xuống dưới
            for (int yy = y; yy > 0; yy--){
                for (int x = 0; x < COT; x++){
                    grid[yy][x] = grid[yy - 1][x];
                }
            }
            // Đặt hàng trên cùng thành trống
            for (int x = 0; x < COT; x++){
                grid[0][x] = { 0, 0, 0 };
            }
            y++; // Kiểm tra lại hàng vừa được di chuyển xuống
        }
    }
    return linesCleared; // Trả về số hàng đã xóa
}