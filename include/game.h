#include "renderer.h"
#include "controller.h"
#include <thread>
 



 
class Game{
        private:
           Renderer *renderer;      
 
        public:
	   Game( Renderer *renderer);
           void UpdateVisual(Spacecar *);
           Spacecar *spacecar;
           std::vector<Spacecar*> enemyCar;
           void GeneretaEnemy(int enemysize);
	       void counter();
           int count=0;

};
