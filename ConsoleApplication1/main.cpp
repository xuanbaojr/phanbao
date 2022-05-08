#include <iostream>
#include <SDL.h>
using namespace std;
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "An Implementation of Code.org Painter";

//const int x = SCREEN_WIDTH/2;
//const int y = SCREEN_HEIGHT/2;

//int step = 0;
//The window we'll be rendering to
SDL_Window* gWindow = NULL;
    
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;
SDL_Surface* thumon = NULL;


bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

SDL_Surface* loadMedia(char* path)
{
    gHelloWorld = SDL_LoadBMP(path);
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
    }
    return gHelloWorld;
}

void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, NULL, des, &offset);
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
       if( SDL_WaitEvent(&e) == 0) SDL_Delay(00);
	   else if(e.type == SDL_QUIT) break;
	   else if(e.type == SDL_KEYDOWN )
	   {
		   switch (e.key.keysym.sym)
		   {
		   case SDLK_UP: 
			   {	
				   cout<<"1";
				   break;
			   }

		   //default:
			 //  break;
		   }
	   }

    }
}


int main(int argc, char* argv[])
{
	//SDL_Surface* thumon;
	
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia("hello_world.bmp") )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {	
			ApplySurface(gHelloWorld, gScreenSurface, 0, 0);
			thumon = loadMedia("1.bmp");
			ApplySurface(thumon, gScreenSurface, 500 , 250);

            //Apply the image
          //  SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
			  //Update the surface
            SDL_UpdateWindowSurface( gWindow );
			            //Wait two seconds
            SDL_Delay( 10000 );
        }

    }
	waitUntilKeyPressed();
    //Free resources and close SDL
    close();

   
  //  quitSDL(window, renderer);
    return 0;
}