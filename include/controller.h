#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <mutex>
#include "enemycar.h" 

class Controller {
	  public:
             void HandleInput(bool running,Spacecar *spacecar);
};

#endif
