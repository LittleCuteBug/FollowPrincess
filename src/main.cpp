#include "../include/main.h"
#include "../include/GameStatus.h"

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
			//Main loop flag
			bool quit = false;
			//Event handler
			SDL_Event e;
			CGame Game;
			//While application is running
			Status CASE = Map;
			while ( !quit )
			{
				//Handle events on queue
				switch (CASE)
				{
				case Play:
					CharacterMove(e,Game,quit,CASE);
					break;
				case Map:
					ShowMap(e,Game,quit,CASE);
					break;
				case Reset:
					ResetMap(e,Game,quit,CASE);
					break;
				case Lose:
					AnnounceLosing(e,Game,quit,CASE);
					break;
				case Win:
					AnnounceWinning(e,Game,quit,CASE);
					break;
				}
				//Update screen
				SDL_RenderPresent( gRenderer );

			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
