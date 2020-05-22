#include<C:\Users\quang\Desktop\FollowPrincess\CPlayer.h>
#include<C:\Users\quang\Desktop\FollowPrincess\CMap.h>
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
	bool Move(char c)
	{
		switch (c)
		{
			case 68:
			case 'a':
			{
				if(!Map.goLeft())
					CannotMove();
				return true;
			}
			case 67:
			case 'd':
			{
				if(!Map.goRight())
					CannotMove();
				return true;
			}
			case 65:
			case 'w':
			{
				if(!Map.goUp())
					CannotMove();
				return true;
			}
			case 66:
			case 's':
			{
				if(!Map.goDown())
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
