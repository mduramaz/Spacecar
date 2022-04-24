#include "renderer.h"
#include "bullet.h"
#include <iostream>
class Weapon{
      private:
	int centerx,centery,sizex,sizey,speed,carsizex,carsizey,direction=1;
        Renderer *renderer;

      public:
	 Weapon(int centerx,int centery,int sizex,int sizey,int speed,int carsizex,int carsizey,Renderer *renderer,int direction=0);
         void move(int x,int y);
         void AddBulletWindow();
         void MoveAllBullet();
         void UpdateBullet();
         void eraseBullet(int i){  bullets.erase (bullets.begin()+i);};
         std::vector<Bullet*> getBullets()const{return bullets;}
         void eraseAllBullet();
	std::vector<Bullet*> bullets;
};
