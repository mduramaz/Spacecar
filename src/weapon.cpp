#include "weapon.h"
#include "params.h"

Weapon::Weapon(int centerx,int centery,int sizex,int sizey,int speed,int carsizex,int carsizey,Renderer *renderer,int direction):
centerx(centerx),centery(centery),sizex(sizex),sizey(sizey),speed(speed),carsizex(carsizex),carsizey(carsizey),renderer(renderer),direction(direction)
{    
    this->centerx=centerx+carsizex/2-sizex/2;
    this->centery=centery+(direction-1)*sizey+direction*carsizey;
    renderer->CreateVisualWeapon(centerx,centery,sizex,sizey);
}

void Weapon::move(int x,int y)
{   
    this->centerx=x+carsizex/2-sizex/2;
    this->centery=y+(direction-1)*sizey+direction*carsizey;
    renderer->CreateVisualWeapon(centerx,centery,sizex,sizey);
}
 
void Weapon::AddBulletWindow()
{
    bullets.push_back(new Bullet(sizeBulletx,sizeBullety,centerx,centery,renderer,direction));
}


void Weapon::MoveAllBullet()
{
  for(int i=0; i<bullets.size(); i++)
  {
     bullets[i]->move();
  }
}
void Weapon::eraseAllBullet()
{
  bullets.clear();
}

void Weapon::UpdateBullet()
{
           
  for(int i=0; i<bullets.size(); i++)
  {
     if(bullets[i]->getstarty()<0 || bullets[i]->getstarty()>kScreenHeight)
     {
          bullets.erase(bullets.begin()+i);
     }
  } 
   
  for(int i=0; i<bullets.size(); i++)
  {
     bullets[i]->UpdateVisual();
  }     
}


