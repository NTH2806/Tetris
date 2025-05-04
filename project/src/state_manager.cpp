// File: state_manager.cpp
// Mục đích: Triển khai các hàm để quản lý chuyển đổi trạng thái game và texture.
// Vai trò: Quản lý trạng thái game và giao diện.

#include "state_manager.h"
#include <SDL.h>
#include <iostream>
#include <music_label.h>

// Thêm enum và biến setting_state
enum Settingstate{ HELP_HELP , HELP_CREDIT };
Settingstate setting_state = HELP_HELP;

void Init_state_manager(){
    game_state = MENU;
    setting_state = HELP_HELP; // Đặt mặc định
    Initialize(); // Khởi tạo SDL, window, renderer, font, và menu
    Play_background_music();
    Init_mouse_manager();
}

void Handle_state_events(){
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)){
            running = false;
            return;
        }

        switch (game_state){
        case MENU:
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
                int mouseX = event.button.x;
                int mouseY = event.button.y;
                // Click nút start
                if (mouseX >= 521 && mouseX <= 521 + 335 && mouseY >= 499 && mouseY <= 499 + 121){
                    Destroy_logo();
                    Destroy_tabs_menu();
                    Destroy_start();
                    Destroy_setting();
                    Destroy_help();
                    Init_overlay();
                    Init_return_button();
                    Init_game_over();
                    Initialize_game();
                    Reset_grid();
                    game_state = GAME;
                }
                // Click nút setting
                else if (mouseX >= 1026 && mouseX <= 1026 + 335 && mouseY >= 499 && mouseY <= 499 + 121){
                    Destroy_logo();
                    Destroy_tabs_menu();
                    Destroy_start();
                    Destroy_setting();
                    Destroy_help();
                    Init_tabs_setting();
                    Init_music_label();
                    Init_right_press();
                    Init_left_press();
                    Init_return_button();
                    game_state = SETTING;
                }
                // Click nút help
                else if (mouseX >= 774 && mouseX <= 774 + 335 && mouseY >= 686 && mouseY <= 686 + 121){
                    Destroy_logo();
                    Destroy_tabs_menu();
                    Destroy_start();
                    Destroy_setting();
                    Destroy_help();
                    Init_help_credit();
                    Init_return_button();
                    Init_help_button();
                    Init_copyright_button();
                    Init_help_tex();
                    Init_copyright_tex();
                    game_state = HELP;
                }
            }
            break;
        case SETTING:
        case HELP:
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
                int mouseX = event.button.x;
                int mouseY = event.button.y;
                if (game_state == HELP){
                    // Click nút help_button
                    if (mouseX >= 411 && mouseX <= 411 + 339 && mouseY >= 473 && mouseY <= 473 + 75){
                        setting_state = HELP_HELP;
                    }
                    // Click nút copyright_button
                    else if (mouseX >= 411 && mouseX <= 411 + 339 && mouseY >= 557 && mouseY <= 557 + 75){
                        setting_state = HELP_CREDIT;
                    }
                }
                // Click nút return
                if (mouseX >= 123 && mouseX <= 123 + 96 && mouseY >= 81 && mouseY <= 81 + 94){
                    if (game_state == SETTING){
                        Destroy_tabs_setting();
                        Destroy_music_label();
                        Destroy_right_press();
                        Destroy_left_press();
                    }
                    else{
                        Destroy_help_credit();
                        Destroy_help_button();
                        Destroy_copyright_button();
                        Destroy_help_tex();
                        Destroy_copyright_tex();
                    }
                    Destroy_return_button();
                    Init_logo();
                    Init_tabs_menu();
                    Init_start();
                    Init_setting();
                    Init_help();
                    game_state = MENU;
                }
            }
            break;
        }
        Handle_mouse_events(&event);
    }
}

void Update_state(){
    if (game_state == GAME){
        Handle_events();
        if (game_state == GAME){
            Update_game();
            Render_game();
        }
    }
}

void Render_state(){
    Render_background();
    switch (game_state){
    case MENU:
        Render_logo();
        Render_tabs_menu();
        Render_start(mouseX , mouseY);
        Render_setting(mouseX , mouseY);
        Render_help(mouseX , mouseY);
        break;
    case SETTING:
        Render_tabs_setting();
        Render_music_label();
        Render_right_press(mouseX , mouseY);
        Render_left_press(mouseX , mouseY);
        Render_return_button(mouseX , mouseY);
        break;
    case HELP:
        switch (setting_state){
        case HELP_HELP:
            Render_help_credit();
            Render_return_button(mouseX , mouseY);
            Render_help_button(mouseX , mouseY);
            Render_copyright_button(mouseX , mouseY);
            Render_help_tex();
            break;
        case HELP_CREDIT:
            Render_help_credit();
            Render_return_button(mouseX , mouseY);
            Render_help_button(mouseX , mouseY);
            Render_copyright_button(mouseX , mouseY);
            Render_copyright_tex();
            break;
        }
        break;
    }
    SDL_RenderPresent(renderer);
}

void Destroy_state_manager(){
    switch (game_state){
    case MENU:
        Destroy_logo();
        Destroy_tabs_menu();
        Destroy_start();
        Destroy_setting();
        Destroy_help();
        break;
    case GAME:
        Destroy_overlay();
        Destroy_return_button();
        Destroy_game_over();
        break;
    case SETTING:
        Destroy_tabs_setting();
        Destroy_music_label();
        Destroy_right_press();
        Destroy_left_press();
        Destroy_return_button();
        break;
    case HELP:
        Destroy_help_credit();
        Destroy_help_tex();
        Destroy_copyright_tex();
        Destroy_return_button();
        Destroy_help_button();
        Destroy_copyright_button();
        break;
    }
    Destroy_background();
    Destroy_audio();
    Destroy_mouse_manager();
    Destroy();
}