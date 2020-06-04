#include "../include/GameState.h"
void PlayGame(CGame &Game, bool &quit, SDL_Event &e)
{	
	Status CASE = Map;
	while ( !quit )
	{
		switch (CASE)
		{
		case Play:
			CharacterMove(e, Game, quit, CASE);
			break;
		case Map:
			ShowMap(e, Game, quit, CASE);
			break;
		case Reset:
			ResetMap(e, Game, quit, CASE);
			break;
		case Lose:
			AnnounceLosing(e, Game, quit, CASE);
			break;
		case Win:
			AnnounceWinning(e, Game, quit, CASE);
			break;
		}
		//Update screen
		SDL_RenderPresent( gRenderer );
	}
}