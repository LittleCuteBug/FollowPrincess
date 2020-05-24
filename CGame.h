#include<C:\Users\quang\Desktop\FollowPrincess\CPlayer.h>
#include<C:\Users\quang\Desktop\FollowPrincess\CMap.h>
#include<C:\Users\quang\Desktop\FollowPrincess\SDLFunc.h>
void CMap::SDLRenderingGame()
{
	for(int i=0;i<MapSize;i++)
	{
		for(int j=0;j<MapSize;j++)
		{
			double x = j*SCREEN_WIDTH/MapSize;
			double y = i*SCREEN_HEIGHT/MapSize;
			double w = SCREEN_WIDTH/MapSize;
			double h = SCREEN_HEIGHT/MapSize;
			RenderImage(gImage[MapSafeCellImage],x,y,w,h);
		}
	}

	RenderImage(gImage[MapStartCellImage],
		0,
		0,
		SCREEN_WIDTH/MapSize,
		SCREEN_HEIGHT/MapSize);

	RenderImage(gImage[MapFinishCellImage],
		(MapSize-1)*SCREEN_WIDTH/MapSize,
		(MapSize-1)*SCREEN_HEIGHT/MapSize,
		SCREEN_WIDTH/MapSize,
		SCREEN_HEIGHT/MapSize);

	RenderImage(gImage[PrincessImage],
		y*SCREEN_WIDTH/MapSize,
		x*SCREEN_HEIGHT/MapSize,
		SCREEN_WIDTH/MapSize,
		SCREEN_HEIGHT/MapSize);
}
void CPlayer::SDLRenderingGame()
{
	;
}
class CGame
{
private:
	CPlayer Player;
	CMap Map;

public:
	CGame(int _life = 10, int _level = 1, int _MapSize = 4)
	{
		Player.Setter(_life,_level);
		Map.AssignNewMap(_MapSize);
		Map.AssignNewPosition();
	}
	void NextLevel()
	{
		Player.LevelIncrease();
		Map.NextLevel();
	}
	void PrintMap()
	{
		Player.Print();
		Map.PrintMap();
	}
	void PrintGame()
	{
		for(int i = 0;i<20;i++)
			cout<<endl;
		Player.Print();
		Map.PrintGame();
	}
	void SDLRenderingGame()
	{
		Player.SDLRenderingGame();
		Map.SDLRenderingGame();
	}
	void Reset()
	{
		Player.LifeDecrease();
		Map.AssignNewPosition();
	}
	bool isDead()
	{
		return Player.isDead();
	}
	void CannotMove()
	{
		cout<<"CannotMove"<<endl;
	}
	bool Move(int c)
	{
		switch (c)
		{
			case GoUpKey:
			{
				if(!Map.goUp())
					CannotMove();
				return true;
			}
			case GoDownKey:
			{
				if(!Map.goDown())
					CannotMove();
				return true;
			}
			case GoLeftKey:
			{
				if(!Map.goLeft())
					CannotMove();
				return true;
			}
			case GoRightKey:
			{
				if(!Map.goRight())
					CannotMove();
				return true;
			}
		};
		return false;
	}
	bool isBomb()
	{
		return Map.isBomb();
	}
	bool isWinning()
	{
		return Map.isWinning();
	}
};
