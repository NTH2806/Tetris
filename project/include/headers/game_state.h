// File: game_state.h
// Mục đích: Khai báo các biến toàn cục dùng trong game (trạng thái game, điểm số, khối hiện tại, v.v.).
// Vai trò: Thuộc mục 4 - Quản lý trạng thái game trong vòng lặp chính.

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "init.h"
#include "tetris.h"

// Enum định nghĩa các trạng thái game
enum GameState{
    MENU ,
    GAME ,
    SETTING ,
    HELP
};

// Biến toàn cục lưu trạng thái game hiện tại
extern enum GameState game_state;

// Khai báo các biến toàn cục liên quan đến SDL
extern SDL_Renderer* renderer; // Renderer để vẽ lên màn hình
extern TTF_Font* font;         // Font chữ để hiển thị điểm số và thông báo
extern TTF_Font* font2;         // Font chữ để hiển thị điểm số và thông báo
extern SDL_Event event;        // Biến sự kiện để xử lý input từ người chơi

// Khai báo các biến trạng thái game
extern struct Block Current_block; // Khối hiện tại đang rơi
extern bool game_over;             // Trạng thái game over (true nếu game kết thúc)
extern int score;                  // Điểm số hiện tại của người chơi
extern int lines;                  // Lines hiện tại của người chơi
extern int finalscore;                  // Điểm số hiện tại của người chơi
extern bool running;               // Trạng thái vòng lặp chính (true nếu game đang chạy)
extern Uint32 Last_fall_time;      // Thời gian lần cuối khối rơi
extern const Uint32 Fall_interval; // Khoảng thời gian giữa các lần rơi

// Biến để quản lý hiển thị điểm số
extern SDL_Texture* score_texture; // Texture chứa điểm số để vẽ lên màn hình
extern SDL_Texture* finalscore_texture; // Texture chứa điểm số để vẽ lên màn hình
extern SDL_Texture* line_texture;// Texture chứa lines để vẽ lên màn hình
extern int last_score;             // Giá trị điểm số trước đó (dùng để kiểm tra thay đổi)
extern int last_lines;             // Giá trị điểm số trước đó (dùng để kiểm tra thay đổi)
extern int last_finalscore;             // Giá trị điểm số trước đó (dùng để kiểm tra thay đổi)
extern SDL_Rect score_rect;        // Vị trí và kích thước của điểm số trên màn hình
extern SDL_Rect line_rect;          // Vị trí và kích thước của lines trên màn hình
extern SDL_Rect finalscore_rect;        // Vị trí và kích thước của điểm số trên màn hình

#endif