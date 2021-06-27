#ifndef GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#define SDL_MAIN_HANDLED // helps resolve linking errors regarding _SDL_main
#define GAME_H

using namespace std;

class Game {
 public:
  Game(size_t grid_width, size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  SDL_Point food;

  random_device dev;
  mt19937 engine;
  uniform_int_distribution<int> random_w, random_h;
 
  int score{0};

  void PlaceFood();
  void Update();
};

#endif