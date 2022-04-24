#include "controller.h"
#include <iostream>
#include "SDL.h"
#include <mutex>
 
#include <chrono>
#include <thread>
#define param 2 
 
 void Controller::HandleInput(bool running,Spacecar *spacecar)  
 {
  SDL_Event e;
  while (SDL_PollEvent(&e)) 
  { 
      if (e.type == SDL_QUIT) 
      {
        running = false;
      } 
      else if (e.type == SDL_KEYDOWN) 
      {
        if (e.key.keysym.sym==SDLK_UP) 
        {
          spacecar->move(0,-1*param);    
          break;
        }
        else if (e.key.keysym.sym==SDLK_DOWN) 
        {
          spacecar->move(0,param);       
          break;
        }
        else if (e.key.keysym.sym==SDLK_LEFT) 
        {
          spacecar->move(-1*param,0);       
          break;
        }
        else if (e.key.keysym.sym==SDLK_RIGHT) 
        {
          spacecar->move(param,0);      
          break;
        }
        else if (e.key.keysym.sym==SDLK_s) 
        {
          spacecar->weapon->AddBulletWindow();       
          break;
        }
      }
    }
  }   

 



