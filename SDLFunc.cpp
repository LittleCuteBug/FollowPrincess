#include<C:\Users\quang\Desktop\FollowPrincess\main.h>
#include<C:\Users\quang\Desktop\FollowPrincess\SDLFunc.h>

SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

string Imagepath [] = {
	//"BackGroundImage.png",
	"Image/MapSafeCellImage.png",
	"Image/MapBombCellImage.png",
	"Image/MapStartCellImage.png",
	"Image/MapFinishCellImage.png",
	"Image/PrincessImage.png"
};
SDL_Surface* gImage[NumberOfImage];

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if ( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if ( !( IMG_Init( imgFlags ) & imgFlags ) )
			{
				printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
				success = false;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface( gWindow );
			}
		}
	}

	return success;
}
void RenderImage(SDL_Surface* Image, double x, double y, double w, double h)
{
	SDL_Rect stretchRect;
	stretchRect.x = x - 1;
	stretchRect.y = y - 1;
	stretchRect.w = w + 2;
	stretchRect.h = h + 2;
	SDL_BlitScaled(Image, NULL, gScreenSurface, &stretchRect);
}
SDL_Surface* loadSurface( std::string path )
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if ( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
		if ( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load PNG surface
	for (int i = 0; i < NumberOfImage; i++)
	{
		gImage[i] = loadSurface( Imagepath[i] );
		if ( gImage[i] == NULL )
		{
			printf( "Failed to load ", Imagepath, "\n" );
			success = false;
		}
	}
	return success;
}

void close()
{
	//Free loaded image
	for (int i = 0; i < NumberOfImage; i++)
		gImage[i] = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
