
#include <stdio.h>

#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>

SDL_Window *window;                    // Declare a pointer
SDL_Renderer *renderer;

void g_init(int iw, int ih){

    SDL_Surface *surface;

    SDL_Init(SDL_INIT_EVERYTHING);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "Assembly animation",              // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        iw,                                // width, in pixels
        ih,                                // height, in pixels
        SDL_WINDOW_SHOWN                   // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return;
    }
    surface = SDL_GetWindowSurface(window);
    renderer = SDL_CreateSoftwareRenderer(surface);
    if (!renderer) {
        printf("Render creation for surface fail \n");
        return;
    }  
  printf("init graphics\n");
}

void print_d(int x){

    if(x != 0)

    printf("value %d" , x);
}

void g_draw_boxes(int x , int y){

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    SDL_RenderClear(renderer);

    SDL_Rect rect, darea;

    /* Get the Size of drawing surface */
    SDL_RenderGetViewport(renderer, &darea);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    rect.w = darea.w/64;
    rect.h = darea.h/64;
    rect.x = x;
    rect.y = y;
    SDL_RenderFillRect(renderer, &rect);

    rect.y = y - 25;

    SDL_RenderFillRect(renderer, &rect);

    rect.x = x - 12;
    rect.y = y - 12;

    SDL_RenderFillRect(renderer, &rect);

    rect.x = x + 12;

    SDL_RenderFillRect(renderer, &rect);

    rect.x = x + 12;
    rect.y = y - 12;

    SDL_RenderFillRect(renderer, &rect);

    
        
    SDL_UpdateWindowSurface(window);
    SDL_RenderPresent(renderer);
 
}
