#include "renderer.h"



class Bullet
{
   private:
        int sizex,sizey,startx,starty;
        Renderer *renderer;
        int direction{0};
   public:
	    Bullet(int sizex,int sizey,int x,int y,Renderer *renderer,int direction=0);

        int getsizex()const{return sizex;}
        int getsizey()const{return sizey;}
        int getstartx()const{return startx;}
        int getstarty()const{return starty;}

        void move();
        void UpdateVisual();
        
 };
