// File: state_manager.h
// Mục đích: Định nghĩa các hàm để quản lý chuyển đổi trạng thái game và texture.
// Vai trò: Quản lý trạng thái game và giao diện.

#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "game_state.h"
#include "init.h"
#include "game_init.h"
#include "game_loop.h"
#include "background.h"
#include "logo.h"
#include "tabs_menu.h"
#include "start.h"
#include "setting.h"
#include "help.h"
#include "return_button.h"
#include "tabs_setting.h"
#include "help_credit.h"
#include "mouse_manager.h"
#include "help_button.h"
#include "help_tex.h"
#include "copyright_tex.h"
#include "copyright_button.h"
#include "help_button.h"
#include "copyright_button.h"
#include "game_over.h"
#include <left_press.h>
#include <right_press.h>

// Hàm khởi tạo trạng thái ban đầu
void Init_state_manager();

// Hàm xử lý sự kiện theo trạng thái
void Handle_state_events();

// Hàm cập nhật trạng thái game
void Update_state();

// Hàm vẽ giao diện theo trạng thái
void Render_state();

// Hàm hủy tài nguyên trạng thái
void Destroy_state_manager();

#endif