#include "CPlayer.h"
#include "CMap.h"
#include "SDLFunc.h"

class CGame
{
private:
	CPlayer Player;
	CMap Map;

public:
	CGame(int _life = 20, int _level = 1, int _MapSize = 4);
	void NextLevel();
	void PrintMap();
	void PrintGame();
	void SDLRenderingMap();
	void SDLRenderingGame();
	void Reset();
	bool isDead();
	void CannotMove();
	bool Move(int c);
	bool isBomb();
	bool isWinning();
};
