#include "../include/main.h"
#include "../include/SDLFunc.h"

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

string Imagepath [] = {
	"Image/BackgroundImage.png",
	"Image/MapCellImage.png",
	"Image/MapSafeCellImage.png",
	"Image/MapBombCellImage.png",
	"Image/MapStartCellImage.png",
	"Image/MapFinishCellImage.png",
	"Image/PrincessImage.png",
	"Image/WinningImage.png",
	"Image/LosingImage.png",
	"Image/BangImage.png",
	
	"Image/StatusImage.png",
	"Image/Button/NewGameButton.png",
	"Image/Button/SaveButton.png",
	"Image/Button/LoadButton.png",
	"Image/Button/BackButton.png",
	"Image/BackgroundMenuImage.png",
	
	"Image/Number/0.png",
	"Image/Number/1.png",
	"Image/Number/2.png",
	"Image/Number/3.png",
	"Image/Number/4.png",
	"Image/Number/5.png",
	"Image/Number/6.png",
	"Image/Number/7.png",
	"Image/Number/8.png",
	"Image/Number/9.png"
};
SDL_Texture* gImage[NumberOfImage];
SDL_Texture* gNumber[10];


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

void RenderImage(SDL_Texture* Image, double x, double y, double w, double h)
{
	SDL_Rect stretchRect;
	stretchRect.x = x - 1;
	stretchRect.y = y - 1;
	stretchRect.w = w + 2;
	stretchRect.h = h + 2;
	SDL_RenderCopy(gRenderer,Image,NULL,&stretchRect);
}
SDL_Texture* loadTexture( string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load PNG surface
	for (int i = 0; i < NumberOfImage; i++)
	{
		gImage[i] = loadTexture( Imagepath[i] );
		if ( gImage[i] == NULL )
		{
			printf( "Failed to load ", Imagepath[i], "\n" );
			success = false;
		}
	}
	for(int i = 0;i<10;i++)
	{
		gNumber[i] = loadTexture(Imagepath[NumberOfImage+i]);
		if ( gNumber[i] == NULL )
		{
			printf( "Failed to load ", Imagepath[NumberOfImage+i], "\n" );
			success = false;
		}	
	}
	return success;
}

void close()
{
	//Free loaded image
	for (int i = 0; i < NumberOfImage; i++)
	{
		SDL_DestroyTexture( gImage[i] );
		gImage[i] = NULL;
	}
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
