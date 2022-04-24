#include <iostream>
#include "renderer.h"
#include "controller.h"
#include "game.h"
#include "params.h"

int main() 
{
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Game game(&renderer);
  printf("Thank you for you play this game");
  return 0;
}
