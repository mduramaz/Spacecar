#include "renderer.h"
#include <iostream>
#include <string>


Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) 
{
 
  if (SDL_Init(SDL_INIT_VIDEO) < 0) 
  {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) 
  {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);

  if (nullptr == sdl_renderer) 
  {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() 
{
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::CreateVisualCar(int centerx,int centery,int sizex,int sizey)
{
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  SDL_Rect block;

  block.w = sizex;
  block.h = sizey;
  block.x = centerx;
  block.y = centery;
    
  SDL_RenderFillRect(sdl_renderer, &block);
}

void Renderer::Clear()
{
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);
}

void Renderer::CreateVisualWeapon(int centerx,int centery,int sizex,int sizey)
{
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0xCC, 0xFF, 0xFF);
  SDL_Rect block;

  block.w = sizex;
  block.h = sizey;
  block.x = centerx;
  block.y = centery;
    
  SDL_RenderFillRect(sdl_renderer, &block); 
}


void Renderer::CreateVisualBullet(int startx,int starty,int sizex,int sizey)
{
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0xCC, 0xFF, 0xFF);
  SDL_Rect block;

  block.w = sizex;
  block.h = sizey;
  block.x = startx;
  block.y = starty;
    
  SDL_RenderFillRect(sdl_renderer, &block);

}

void Renderer::UpdateScreen()
{
  SDL_RenderPresent(sdl_renderer); 
}

 
void Renderer::UpdateWindowTitle(int score) 
{
  std::string title{"Game Score: " + std::to_string(score)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
