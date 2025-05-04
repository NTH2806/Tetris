// File: sound_manager.cpp
// Mục đích: Triển khai các hàm để quản lý nhạc nền và âm thanh trong game.
// Vai trò: Quản lý âm thanh xuyên suốt chương trình.

#include "sound_manager.h"
#include <SDL.h>
#include <iostream>

// Biến toàn cục lưu nhạc nền
Mix_Music* background_music = NULL;

void Init_audio(){
    // Khởi tạo SDL_mixer với định dạng âm thanh mặc định
    if (Mix_OpenAudio(44100 , MIX_DEFAULT_FORMAT , 2 , 2048) < 0){
        std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return;
    }
}

void Play_background_music(){
    // Tải file nhạc nền từ thư mục res/Musics/
    background_music = Mix_LoadMUS("res/Musics/backgroundMusic.mp3");
    if (background_music == NULL){
        std::cout << "Failed to load background music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return;
    }
    // Đặt âm lượng (giá trị từ 0 đến 128, 128 là tối đa)
    Mix_VolumeMusic(128);
    // Phát nhạc nền và lặp lại vô hạn (-1)
    if (Mix_PlayMusic(background_music , -1) == -1){
        std::cout << "Failed to play background music! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
}

void Stop_background_music(){
    if (background_music != NULL){
        Mix_HaltMusic();
    }
}

void Destroy_audio(){
    Stop_background_music();
    if (background_music != NULL){
        Mix_FreeMusic(background_music);
        background_music = NULL;
    }
    Mix_CloseAudio();
}