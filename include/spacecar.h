#include "renderer.h"
#include "weapon.h"

class Spacecar{
	public:
              Spacecar(int centerx,int centery,int sizex,int sizey,Renderer &renderer,int direction=0);
              void updateVisual();
              void move(int x,int y);
              Weapon *weapon;
              int getsizex()const{return sizex;}  
              int getsizey()const{return sizey;}  
              int getcenterx()const{return centerx;}  
              int getcentery()const{return centery;}  

	private:
            int sizex;
            int sizey;
            int centerx;
            int centery;
            int direction=0;
            Renderer *renderer; 
};
