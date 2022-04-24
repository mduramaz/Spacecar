#include "enemycar.h"
#include "params.h"
EnemyCar::EnemyCar(Renderer *renderer,int cars,Spacecar *spacecar):cars(cars),renderer(renderer),spacecar(spacecar)
{
  int distance=kScreenWidth/(cars+1);
  for(int i=0; i<cars; i++)
  {
    emenycars.push_back(new Enemy(i,new Spacecar(startx(distance*(i+1)*2),starty(100),carwith,carlength,*renderer,1)));
  }
}


void EnemyCar::Collision()
{
    for(int i=0; i<collision_enemy_id.size(); i++)
    {
       if(++collision_enemy_id[i]->timestamp>500)
       {
              collision_enemy_id.erase(collision_enemy_id.begin()+i);
       }
    }
    comeingbullets=spacecar->weapon->getBullets();

    for(int i=0; i<comeingbullets.size(); i++)
    {
	for(int j=0; j<emenycars.size(); j++)
        {
              bool check=true;
              for(int test=0; test<collision_enemy_id.size(); test++)
              {
                   if(collision_enemy_id[test]->id==j)
                   {
                         check=false;
                   }
                   
              }
              if(comeingbullets.size()>0 && check)
              {
		 int enemy_x1=emenycars[j]->spacecar->getcenterx();
		 int enemy_x2=emenycars[j]->spacecar->getcenterx()+emenycars[j]->spacecar->getsizex();
		      
		 int enemy_y1=emenycars[j]->spacecar->getcentery();
		 int enemy_y2=emenycars[j]->spacecar->getcentery()+emenycars[j]->spacecar->getsizey();

		 int bullet_x1=comeingbullets[i]->getstartx();
		 int bullet_x2=comeingbullets[i]->getstartx()+comeingbullets[i]->getsizex();

		 int bullet_y1=comeingbullets[i]->getstarty();
		 int bullet_y2=comeingbullets[i]->getstarty()+comeingbullets[i]->getsizey();

     
                 if(((enemy_x1<bullet_x1 && enemy_x2>bullet_x1) || (enemy_x1<bullet_x2 && enemy_x2>bullet_x2)) && ((enemy_y1<bullet_y1 && enemy_y2>bullet_y1) || (enemy_y1<bullet_y2 && enemy_y2>bullet_y2))) 
                 { 
                    printf("collision !!! %d\n",j);
                    collision_enemy_id.push_back(new CollisionSpawn(0,j));
                    spacecar->weapon->eraseBullet(i);
                    emenycars[j]->spacecar->weapon->eraseAllBullet();
                    diedEnemy++;
                 }
             }
	}            
     }

   }



void EnemyCar::RandomMove()
{
 for(int i=0; i<cars; i++)
 {
     bool check=true;
     for(int test=0; test<collision_enemy_id.size(); test++)
     {
       if(collision_enemy_id[test]->id==i)
       {
          check=false;
       }
     }
     if(check)
     {
       int r=(rand()%5)-2;  
       emenycars[i]->spacecar->move(r,0);  
     }
  }
}





void EnemyCar::RandomFireBullet()
{
  for(int i=0; i<cars; i++)
  {
    int r=rand()%randomBullet;
    if(r==100)
      emenycars[i]->spacecar->weapon->AddBulletWindow();
  }
}



void EnemyCar::UpdateVisual()
{
  
 for(int i=0; i<cars; i++)
 {
  bool check=true;
  for(int j=0; j<collision_enemy_id.size(); j++)
  {
    if(collision_enemy_id[j]->id==i)
    {
         check=false;
    } 
  }

  if(check)
  {
     emenycars[i]->spacecar->updateVisual();
     emenycars[i]->spacecar->weapon->MoveAllBullet();
  }
 }
}



std::vector<Bullet*> EnemyCar::totalEnemyBullet()
{
  std::vector<Bullet*> enemybullet;

  for(int i=0; i<cars; i++)
  {
    std::vector<Bullet*> emeca=emenycars[i]->spacecar->weapon->bullets;
    for(int j=0; j<emeca.size(); j++)
   	enemybullet.push_back(emeca[j]);
  }

return enemybullet;
}

void EnemyCar::collitionMyCar(bool& loop)
{
 
    int enemy_x1=spacecar->getcenterx();
    int enemy_x2=spacecar->getcenterx()+spacecar->getsizex();
	
    int enemy_y1=spacecar->getcentery();
    int enemy_y2=spacecar->getcentery()+spacecar->getsizey();

    std::vector<Bullet*> bulletEnemy=totalEnemyBullet();
	
    for(int i=0; i<bulletEnemy.size(); i++){
         
	int bullet_x1=bulletEnemy[i]->getstartx();
	int bullet_x2=bulletEnemy[i]->getstartx()+bulletEnemy[i]->getsizex();

	int bullet_y1=bulletEnemy[i]->getstarty();
	int bullet_y2=bulletEnemy[i]->getstarty()+bulletEnemy[i]->getsizey();


    if(((enemy_x1<bullet_x1 && enemy_x2>bullet_x1) || (enemy_x1<bullet_x2 && enemy_x2>bullet_x2)) && ((enemy_y1<bullet_y1 && enemy_y2>bullet_y1) || (enemy_y1<bullet_y2 && enemy_y2>bullet_y2))) 
    { 
       loop=false;
       printf("You Died !!!!!!!!!!!!!!!!!!!\n Rest in peace\n ");
    }

 }

}

int EnemyCar::getDiedEnemy()
{
  return diedEnemy;
}

