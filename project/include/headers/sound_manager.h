// File: sound_manager.h
// Mục đích: Định nghĩa các hàm để quản lý nhạc nền và âm thanh trong game.
// Vai trò: Quản lý âm thanh xuyên suốt chương trình.

#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <SDL_mixer.h>

// Hàm khởi tạo hệ thống âm thanh (SDL_mixer)
void Init_audio();
// Hàm phát nhạc nền và lặp lại xuyên suốt
void Play_background_music();
// Hàm dừng nhạc nền
void Stop_background_music();
// Hàm hủy tài nguyên âm thanh
void Destroy_audio();

#endif