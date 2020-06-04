#include "../include/main.h"
#include "../include/GameState.h"

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if ( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if ( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			bool quit = false;
			SDL_Event e;
			CGame Game;
			PlayGame(Game,quit,e);
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
