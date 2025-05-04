// File: game_state.cpp
// Mục đích: Định nghĩa các biến toàn cục dùng trong game.
// Vai trò: Thuộc mục 4 - Quản lý trạng thái game trong vòng lặp chính.

#include "game_state.h"
#include <cstdlib>

// Định nghĩa biến trạng thái game
enum GameState game_state = MENU;

// Định nghĩa biến sự kiện SDL
SDL_Event event;

// Định nghĩa các biến trạng thái game
struct Block Current_block;         // Khối hiện tại (khởi tạo mặc định, sẽ được gán giá trị trong game_init.cpp)
bool game_over = false;             // Game chưa kết thúc
int score = 0;                      // Điểm số ban đầu là 0
int lines = 0;                      // lines ban đầu là 0
int finalscore = 0;                      // Điểm số ban đầu là 0
bool running = true;                // Vòng lặp chính đang chạy
Uint32 Last_fall_time = 0;          // Thời gian lần cuối khối rơi (khởi tạo là 0)
const Uint32 Fall_interval = 1000;  // Định nghĩa khoảng thời gian giữa các lần rơi (1 giây = 1000ms)

// Định nghĩa các biến để hiển thị điểm số
SDL_Texture* score_texture = NULL;  // Texture điểm số (khởi tạo là NULL)
SDL_Texture* finalscore_texture = NULL;  // Texture điểm số (khởi tạo là NULL)
SDL_Texture* line_texture = NULL;  // Texture lines (khởi tạo là NULL)
int last_score = -1;                // Điểm số trước đó (khởi tạo là -1 để buộc vẽ lại lần đầu)
int last_lines = -1;                // Lines trước đó (khởi tạo là -1 để buộc vẽ lại lần đầu)
int last_finalscore = -1;                // Điểm số trước đó (khởi tạo là -1 để buộc vẽ lại lần đầu)
SDL_Rect score_rect = { 670, 710, 0, 0 }; // Vị trí điểm số (x=670, y=610), kích thước sẽ được cập nhật khi vẽ
SDL_Rect line_rect = { 670, 610, 0, 0 }; // Vị trí điểm số (x=770, y=610), kích thước sẽ được cập nhật khi vẽ
SDL_Rect finalscore_rect = { 589, 460, 0, 0 }; // Vị trí điểm số (x=670, y=610), kích thước sẽ được cập nhật khi vẽ