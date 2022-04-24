#include "game.h"
#include "params.h"

 
Game::Game( Renderer *renderer):renderer(renderer)
{

  spacecar   =new Spacecar(startx(kScreenWidth),starty(kScreenHeight),carwith,carlength,*renderer);
  Controller controller;

  EnemyCar *enemyCar=new EnemyCar(renderer,enemyGame,spacecar);
  bool loop=true;
  
  while(loop)
  {
   std::this_thread::sleep_for(std::chrono::milliseconds(5));
   renderer->Clear();

   controller.HandleInput(true,spacecar);

   spacecar->weapon->MoveAllBullet();
   spacecar->updateVisual();

   enemyCar->UpdateVisual();
   enemyCar->Collision();
   enemyCar->RandomFireBullet();
   enemyCar->collitionMyCar(loop);
   enemyCar->RandomMove();

   renderer->UpdateScreen();
   renderer->UpdateWindowTitle(enemyCar->getDiedEnemy());

  }
} 
