#include "state_manager.h"
#include <cstdlib>
#include <ctime>

int main(int argc , char* argv[]){
  srand(time(NULL));
  Init_state_manager();
  while (running){
    Handle_state_events();
    while (game_state == GAME && running != false){
      Update_state();
    }
    if (running){
      Render_state();
    }
  }
  Destroy_state_manager();
  return 0;
}