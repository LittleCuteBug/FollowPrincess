#include "../include/main.h"
#include "../include/GameStatus.h"
void CharacterMove(SDL_Event &e, CGame &Game, bool &quit, Status &CASE)
{
	while ( SDL_PollEvent( &e ) != 0 )
	{
		//User requests quit
		if ( e.type == SDL_QUIT )
		{
			quit = true;
			break;
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
		CASE = Reset;
	}
	if (Game.isDead())
	{
		CASE = Lose;
	}
	if (Game.isWinning())
	{
		CASE = Win;
	}
	Game.SDLRenderingGame();
}
void ShowMap(SDL_Event &e, CGame &Game, bool &quit, Status &CASE)
{
	while ( SDL_PollEvent( &e ) != 0 )
	{
		//User requests quit
		if ( e.type == SDL_QUIT )
		{
			quit = true;
			break;
		}
		else if ( e.type == SDL_KEYDOWN )
		{
			if (e.key.keysym.sym == SDLK_SPACE)
			{
				CASE = Play;
				break;
			}
		}
	}
	Game.SDLRenderingMap();
}
void ResetMap(SDL_Event &e, CGame &Game, bool &quit, Status &CASE)
{
	Game.Reset();
	CASE = Map;
	RenderImage(gImage[BangImage],MAP_LOCATION,MAP_LOCATION,MAP_SIZE,MAP_SIZE);
	SDL_RenderPresent(gRenderer);
	WaitForSpace(e,quit);
}
void AnnounceLosing(SDL_Event &e, CGame &Game, bool &quit, Status &CASE)
{
	//cout << "Lose" << endl;
	RenderImage(gImage[LosingImage],MAP_LOCATION,MAP_LOCATION,MAP_SIZE,MAP_SIZE);
	SDL_RenderPresent(gRenderer);
	WaitForSpace(e,quit);
	quit = true;
}
void AnnounceWinning(SDL_Event &e, CGame &Game, bool &quit, Status &CASE)
{
	//cout << "Win" << endl;
	Game.NextLevel();
	CASE = Map;
	RenderImage(gImage[WinningImage],MAP_LOCATION,MAP_LOCATION,MAP_SIZE,MAP_SIZE);
	SDL_RenderPresent(gRenderer);
	WaitForSpace(e,quit);
}
void WaitForSpace(SDL_Event &e, bool &quit)
{
	bool subquit = false;
	while((!subquit)&&(!quit))
	{
		while ( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if ( e.type == SDL_QUIT )
			{
				quit = true;
				break;
			}
			else if ( e.type == SDL_KEYDOWN )
			{
				if (e.key.keysym.sym == SDLK_SPACE)
				{
					subquit = true;
					break;
				}
			}
		}
	}
}