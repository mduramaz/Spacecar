#include "renderer.h"
#include "bullet.h"


Bullet::Bullet(int sizex,int sizey,int startx,int starty,Renderer *renderer,int direction):sizex(sizex),sizey(sizey),startx(startx),starty(starty),renderer(renderer),direction(direction)
{
  renderer->CreateVisualBullet(startx,starty,sizex,sizey);
}

void Bullet::move()
{
  if(direction==0)
  {
    starty-=1;
  }
  else
  {
    starty+=1;
  }
    renderer->CreateVisualBullet(startx,starty,sizex,sizey);
}
        
void Bullet::UpdateVisual()
{ 
  renderer->CreateVisualBullet(startx,starty,sizex,sizey);
}
