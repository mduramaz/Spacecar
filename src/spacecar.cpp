#include "spacecar.h"
#include "params.h"
Spacecar::Spacecar(int centerx,int centery,int sizex,int sizey,Renderer &renderer,int direction):centerx(centerx),centery(centery),sizex(sizex),sizey(sizey),renderer(&renderer)
{

this->direction=direction;
weapon=new Weapon(centerx,centery,sizeBulletx,sizeBullety,speedBullet,sizex,sizey,&renderer,direction);
renderer.CreateVisualCar(centerx,centery,sizex,sizey);

}  

void Spacecar::move(int x,int y)
{
  centerx=centerx+x;
  centery=centery+y;
  renderer->CreateVisualCar(centerx,centery,sizex,sizey);
  weapon->move(centerx,centery);
}



void Spacecar::updateVisual()
{
  renderer->CreateVisualCar(centerx,centery,sizex,sizey);
  weapon->move(centerx,centery);
  weapon->UpdateBullet();
}



