#include "../include/main.h"
#include "../include/CGame.h"

enum Status
{
	Play,
	Map,
	Reset,
	Lose,
	Win
};

void CharacterMove(SDL_Event &e, CGame &Game, bool &quit, Status &CASE);
void ShowMap(SDL_Event &e, CGame &Game, bool &quit, Status &CASE);
void ResetMap(SDL_Event &e, CGame &Game, bool &quit, Status &CASE);
void AnnounceLosing(SDL_Event &e, CGame &Game, bool &quit, Status &CASE);
void AnnounceWinning(SDL_Event &e, CGame &Game, bool &quit, Status &CASE);
void WaitForSpace(SDL_Event &e, bool &quit);