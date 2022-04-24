#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
 

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
 void CreateVisualCar(int,int,int,int);
 void CreateVisualWeapon(int,int,int,int);
  ~Renderer();
 
 
  void UpdateWindowTitle(int score);
  void Clear();
  void CreateVisualBullet(int startx,int starty,int sizex,int sizey);
  void UpdateScreen();
 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif
