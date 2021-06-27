#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

using namespace std;

int main() {

  // can be used for both member and non-member functions, as well as constructors
  constexpr size_t kFramesPerSecond{60};
  constexpr size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr size_t kScreenWidth{640};
  constexpr size_t kScreenHeight{640};
  constexpr size_t kGridWidth{32};
  constexpr size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  cout << "게임은 성공적으로 끝났습니다!\n";
  cout << "점수: " << game.GetScore() << "\n";
  cout << "뱀의 크기: " << game.GetSize() << "\n";
  return 0;
}