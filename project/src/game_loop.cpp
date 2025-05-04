// File: game_loop.cpp
// Mục đích: Triển khai các hàm xử lý vòng lặp chính của game.
// Vai trò: Thuộc mục 4 - Vòng lặp chính của game.

#include "game_loop.h"
#include <string>
#include <game_over.h>
#include <game_init.h>

void transPos(bool matrix[MATRIX_SIZE][MATRIX_SIZE]){
    bool backUp[MATRIX_SIZE][MATRIX_SIZE];
    for (int i = 0; i < MATRIX_SIZE; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            backUp[i][j] = matrix[i][j];
        }
    }
    for (int i = 0; i < MATRIX_SIZE; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            matrix[j][MATRIX_SIZE - 1 - i] = backUp[i][j];
        }
    }
}

void fixTheSuperimposed(struct Block* block){
    if (!Check_collision(block)) return;

    Block temp = *block;
    temp.y -= BLOCK_SIZE;
    if (!Check_collision(&temp)){
        *block = temp;
        return;
    }
    temp.y -= BLOCK_SIZE;
    if (!Check_collision(&temp)){
        *block = temp;
        return;
    }
    temp = *block;
    temp.x -= BLOCK_SIZE;
    if (!Check_collision(&temp)){
        *block = temp;
        return;
    }
    temp = *block;
    temp.x += BLOCK_SIZE;
    if (!Check_collision(&temp)){
        *block = temp;
        return;
    }
    temp = *block;
    temp.x -= 2 * BLOCK_SIZE;
    if (!Check_collision(&temp)){
        *block = temp;
        return;
    }
    temp = *block;
    temp.x += 2 * BLOCK_SIZE;
    if (!Check_collision(&temp)){
        *block = temp;
        return;
    }
}

void Handle_events(){
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            running = false;
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
            int mouseX = event.button.x;
            int mouseY = event.button.y;
            // Click nút return
            if (mouseX >= 123 && mouseX <= 123 + 96 && mouseY >= 81 && mouseY <= 81 + 94){
                // Xóa texture game
                Destroy_overlay();
                Destroy_return_button();
                Destroy_game_over();
                // Tải texture menu
                Init_logo();
                Init_tabs_menu();
                Init_start();
                Init_setting();
                Init_help();
                game_state = MENU;
                if (finalscore_texture != NULL){
                    SDL_DestroyTexture(finalscore_texture);
                    finalscore_texture = NULL;
                }
            }
        }
        else if (event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym){
            case SDLK_ESCAPE:
                running = false;
                break;
            default:
                if (game_over) return;

                Block temp_block = Current_block;
                switch (event.key.keysym.sym){
                case SDLK_LEFT:
                    temp_block.x -= BLOCK_SIZE;
                    if (!Check_collision(temp_block)){
                        Current_block.x -= BLOCK_SIZE;
                    }
                    break;
                case SDLK_RIGHT:
                    temp_block.x += BLOCK_SIZE;
                    if (!Check_collision(temp_block)){
                        Current_block.x += BLOCK_SIZE;
                    }
                    break;
                case SDLK_DOWN:
                    temp_block.y += BLOCK_SIZE;
                    if (!Check_collision(temp_block)){
                        Current_block.y += BLOCK_SIZE;
                    }
                    break;
                case SDLK_UP: {
                    bool test_matrix[MATRIX_SIZE][MATRIX_SIZE];
                    for (int i = 0; i < MATRIX_SIZE; i++){
                        for (int j = 0; j < MATRIX_SIZE; j++){
                            test_matrix[i][j] = temp_block.matrix[i][j];
                        }
                    }
                    transPos(test_matrix);
                    for (int i = 0; i < MATRIX_SIZE; i++){
                        for (int j = 0; j < MATRIX_SIZE; j++){
                            temp_block.matrix[i][j] = test_matrix[i][j];
                        }
                    }
                    if (!Check_collision(&temp_block)){
                        Current_block = temp_block;
                    }
                    else{
                        fixTheSuperimposed(&temp_block);
                        if (!Check_collision(&temp_block)){
                            Current_block = temp_block;
                        }
                    }
                    break;
                }
                case SDLK_SPACE:
                    while (!Check_collision(temp_block)){
                        temp_block.y += BLOCK_SIZE;
                    }
                    temp_block.y -= BLOCK_SIZE;
                    Current_block = temp_block;
                    Lock_block(Current_block);
                    score += Clear_full_lines();
                    lines = score;
                    finalscore = score;
                    Current_block = Create_new_block();
                    break;
                }
                break;
            }
        }
        // Xử lý sự kiện chuột
        Handle_mouse_events(&event);
    }
}

void Update_game(){
    if (game_over) return;

    Uint32 current_time = SDL_GetTicks();
    if (current_time - Last_fall_time >= Fall_interval){
        Block temp_block = Current_block;
        temp_block.y += BLOCK_SIZE;
        if (!Check_collision(temp_block)){
            Current_block.y += BLOCK_SIZE;
        }
        else{
            Lock_block(Current_block);
            score += Clear_full_lines();
            lines = score;
            finalscore = score;
            Current_block = Create_new_block();
            if (Check_collision(Current_block)){
                game_over = true;
            }
        }
        Last_fall_time = current_time;
    }
}

void Render_game(){
    Render_background();
    Render_overlay();
    Render_return_button(mouseX , mouseY);

    for (int y = 0; y < HANG; y++){
        for (int x = 0; x < COT; x++){
            if (grid[y][x].r != 0 || grid[y][x].g != 0 || grid[y][x].b != 0){
                SDL_SetRenderDrawColor(renderer , grid[y][x].r , grid[y][x].g , grid[y][x].b , 255);
                SDL_Rect rect = { GRID_OFFSET_X + x * BLOCK_SIZE, GRID_OFFSET_Y + y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE };
                SDL_RenderFillRect(renderer , &rect);
            }
        }
    }

    if (!game_over){
        for (int i = 0; i < MATRIX_SIZE; i++){
            for (int j = 0; j < MATRIX_SIZE; j++){
                if (Current_block.matrix[i][j]){
                    SDL_SetRenderDrawColor(renderer , Current_block.color.r , Current_block.color.g , Current_block.color.b , 255);
                    SDL_Rect rect = { Current_block.x + j * BLOCK_SIZE, Current_block.y + i * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE };
                    SDL_RenderFillRect(renderer , &rect);
                }
            }
        }
    }

    if (score != last_score){
        if (score_texture != NULL){
            SDL_DestroyTexture(score_texture);
            score_texture = NULL;
        }
        char score_text[20];
        sprintf(score_text , "%d" , score);
        SDL_Surface* surface = TTF_RenderText_Solid(font , score_text , { 255, 255, 255 });
        score_texture = SDL_CreateTextureFromSurface(renderer , surface);
        score_rect.w = surface->w;
        score_rect.h = surface->h;
        SDL_FreeSurface(surface);
        last_score = score;
    }
    SDL_RenderCopy(renderer , score_texture , NULL , &score_rect);

    if (lines != last_lines){
        if (line_texture != NULL){
            SDL_DestroyTexture(line_texture);
            line_texture = NULL;
        }
        char line_text[20];
        sprintf(line_text , "%d" , lines);
        SDL_Surface* surface1 = TTF_RenderText_Solid(font , line_text , { 255, 255, 255 });
        line_texture = SDL_CreateTextureFromSurface(renderer , surface1);
        line_rect.w = surface1->w;
        line_rect.h = surface1->h;
        SDL_FreeSurface(surface1);
        last_lines = lines;
    }
    SDL_RenderCopy(renderer , line_texture , NULL , &line_rect);

    if (game_over){
        Render_game_over();
        Destroy_overlay();
        Reset_grid();
        if (line_texture != NULL){
            SDL_DestroyTexture(line_texture);
            line_texture = NULL;
        }
        if (score_texture != NULL){
            SDL_DestroyTexture(score_texture);
            score_texture = NULL;
        }
        if (finalscore != last_finalscore){
            if (finalscore_texture != NULL){
                SDL_DestroyTexture(finalscore_texture);
                finalscore_texture = NULL;
            }
            char finalscore_text[20];
            sprintf(finalscore_text , "%d" , finalscore);
            SDL_Surface* surface2 = TTF_RenderText_Solid(font2 , finalscore_text , { 0, 255, 255 });
            finalscore_texture = SDL_CreateTextureFromSurface(renderer , surface2);
            finalscore_rect.w = surface2->w;
            finalscore_rect.h = surface2->h;
            SDL_FreeSurface(surface2);
            last_finalscore = finalscore;
        }
        SDL_RenderCopy(renderer , finalscore_texture , NULL , &finalscore_rect);
    }

    SDL_RenderPresent(renderer);
}