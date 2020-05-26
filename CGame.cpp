#include<C:\Users\quang\Desktop\FollowPrincess\main.h>
#include<C:\Users\quang\Desktop\FollowPrincess\CGame.h>

CGame::CGame(int _life, int _level, int _MapSize) {
	Player.Setter(_life, _level);
	Map.AssignNewMap(_MapSize);
	Map.AssignNewPosition();
}
void CGame::NextLevel()
{
	Player.LevelIncrease();
	Map.NextLevel();
}
void CGame::PrintMap()
{
	Player.Print();
	Map.PrintMap();
}
void CGame::PrintGame()
{
	for (int i = 0; i < 20; i++)
		cout << endl;
	Player.Print();
	Map.PrintGame();
}
void CGame::SDLRenderingGame()
{
	RenderImage(gImage[BackgroundImage], 0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
	Map.SDLRenderingGame();	
	Player.SDLRenderingGame();
}
void CGame::SDLRenderingMap()
{
	RenderImage(gImage[BackgroundImage], 0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
	Map.SDLRenderingMap();
	Player.SDLRenderingGame();
}
void CGame::Reset()
{
	Player.LifeDecrease();
	Map.AssignNewPosition();
}
bool CGame::isDead()
{
	return Player.isDead();
}
void CGame::CannotMove()
{
	cout << "CannotMove" << endl;
}
bool CGame::Move(int c)
{
	switch (c)
	{
	case GoUpKey:
	{
		if (!Map.goUp())
			CannotMove();
		return true;
	}
	case GoDownKey:
	{
		if (!Map.goDown())
			CannotMove();
		return true;
	}
	case GoLeftKey:
	{
		if (!Map.goLeft())
			CannotMove();
		return true;
	}
	case GoRightKey:
	{
		if (!Map.goRight())
			CannotMove();
		return true;
	}
	};
	return false;
}
bool CGame::isBomb()
{
	return Map.isBomb();
}
bool CGame::isWinning()
{
	return Map.isWinning();
}