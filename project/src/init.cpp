// File: init.cpp
// Mục đích: Triển khai các hàm khởi tạo và hủy tài nguyên SDL.
// Vai trò: Thuộc mục 1 - Khởi tạo cửa sổ và renderer.

#include "init.h"
#include "overlay.h"
#include "logo.h"
#include "tabs_menu.h"
#include "background.h"
#include "start.h"
#include "setting.h"
#include "help.h"

// Định nghĩa biến toàn cục đã khai báo trong init.h
SDL_Window* window = NULL;    // Khởi tạo con trỏ cửa sổ là NULL
SDL_Renderer* renderer = NULL; // Khởi tạo con trỏ renderer là NULL
TTF_Font* font = NULL;        // Khởi tạo con trỏ font là NULL
TTF_Font* font2 = NULL;        // Khởi tạo con trỏ font là NULL

// Hàm khởi tạo SDL, cửa sổ, renderer, font, và hiển thị các layer
void Initialize(){
    // Khởi tạo SDL với tất cả các hệ thống (video, audio, v.v.)
    SDL_Init(SDL_INIT_EVERYTHING);
    // Khởi tạo SDL_ttf để sử dụng font chữ
    TTF_Init();
    // Khởi tạo hệ thống âm thanh
    Init_audio();

    // Tạo cửa sổ game với tiêu đề "Nier Automata"
    // Đặt vị trí cửa sổ ở giữa màn hình (SDL_WINDOWPOS_CENTERED)
    // Kích thước cửa sổ: 1920x1080 pixel
    window = SDL_CreateWindow("Tetris" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 1920 , 1080 , SDL_WINDOW_SHOWN);
    // Tạo renderer cho cửa sổ, sử dụng chế độ tăng tốc phần cứng (SDL_RENDERER_ACCELERATED)
    renderer = SDL_CreateRenderer(window , -1 , SDL_RENDERER_ACCELERATED);
    // Tải font chữ từ file arial.ttf với kích thước 36
    font = TTF_OpenFont("res/Fonts/arial.ttf" , 36);
    font2 = TTF_OpenFont("res/Fonts/arial.ttf" , 48);

    // Khởi tạo và hiển thị nền, logo, tabs menu, start, setting, và help
    Init_background();
    Render_background();
    Init_logo();
    Render_logo();
    Init_tabs_menu();
    Render_tabs_menu();
    Init_start();
    Render_start(0 , 0); // Gọi với tham số mặc định (không hover ban đầu)
    Init_setting();
    Render_setting(0 , 0); // Gọi với tham số mặc định (không hover ban đầu)
    Init_help();
    Render_help(0 , 0); // Gọi với tham số mặc định (không hover ban đầu)
    SDL_RenderPresent(renderer); // Cập nhật màn hình ngay lập tức
}

// Hàm hủy tài nguyên SDL khi kết thúc chương trình
void Destroy(){
    // Hủy hình nền trước
    Destroy_background();

    // Hủy tài nguyên logo, tabs menu, overlay, start, setting, và help
    Destroy_logo();
    Destroy_tabs_menu();
    Destroy_overlay();
    Destroy_start();
    Destroy_setting();
    Destroy_help();

    // Hủy tài nguyên âm thanh
    Destroy_audio();

    // Hủy font chữ
    TTF_CloseFont(font);
    // Hủy renderer
    SDL_DestroyRenderer(renderer);
    // Hủy cửa sổ
    SDL_DestroyWindow(window);
    // Thoát SDL_ttf
    TTF_Quit();
    // Thoát SDL
    SDL_Quit();
}