#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

#include "renderer.h"
#include "spacecar.h"
#include <iostream>
#include <vector>
#include <queue>


class Enemy{
      public:
      int id;
      Spacecar* spacecar;
     
      Enemy(int id,Spacecar* spacecar):id(id),spacecar(spacecar){}
 };


class CollisionSpawn
{
  public:
  int timestamp=0;
  int id;
  CollisionSpawn(int timestamp,int id):timestamp(timestamp),id(id){}
};


class EnemyCar
{
   private:
	int cars;
        Renderer *renderer;
        Spacecar *spacecar; 
        std::vector<Enemy*> emenycars;
        std::vector<CollisionSpawn*> collision_enemy_id;
        std::vector<Bullet*> comeingbullets;
        int diedEnemy{0};
   public:
        EnemyCar(Renderer *renderer,int cars,Spacecar *spacecar);
        void UpdateVisual();
	void Collision();
        void RandomFireBullet();
        std::vector<Bullet*> totalEnemyBullet();
        void collitionMyCar(bool& loop);
        void RandomMove();
        int getDiedEnemy();


};


#endif

