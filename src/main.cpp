#include "../include/main.h"
#include "../include/Cgame.h"
enum Status
{
	Play,
	Map
};
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
				{
					while ( SDL_PollEvent( &e ) != 0 )
					{
						//User requests quit
						if ( e.type == SDL_QUIT )
						{
							quit = true;
						}
						else if ( e.type == SDL_KEYDOWN )
						{
							//Select surfaces based on key press
							switch ( e.key.keysym.sym )
							{
							case SDLK_UP:
								Game.Move(GoUpKey);
								break;
							case SDLK_DOWN:
								Game.Move(GoDownKey);
								break;
							case SDLK_LEFT:
								Game.Move(GoLeftKey);
								break;
							case SDLK_RIGHT:
								Game.Move(GoRightKey);
								break;
							}
						}
					}
					if (Game.isBomb())
					{
						Game.Reset();
						CASE = Map;
					}
					if (Game.isDead())
					{
						cout << "Lose" << endl;
						quit = true;
						break;
					}
					if (Game.isWinning())
					{
						cout << "Win" << endl;
						Game.NextLevel();
						CASE = Map;
					}
					Game.SDLRenderingGame();
					break;
				}
				case Map:
					while ( SDL_PollEvent( &e ) != 0 )
					{
						//User requests quit
						if ( e.type == SDL_QUIT )
						{
							quit = true;
						}
						else if ( e.type == SDL_KEYDOWN )
						{
							if (e.key.keysym.sym == SDLK_SPACE)
							{
								CASE = Play;
							}
						}
					}
					Game.SDLRenderingMap();
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
