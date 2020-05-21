#include<C:\Users\quang\Desktop\FollowPrincess\main.h>
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
	void Move(char c)
	{
		switch (c)
		{
			case 'a':
			{
				if(!Map.goLeft())
					CannotMove();
				break;
			}
			case 'd':
			{
				if(!Map.goRight())
					CannotMove();
				break;
			}
			case 'w':
			{
				if(!Map.goUp())
					CannotMove();
				break;
			}
			case 's':
			{
				if(!Map.goDown())
					CannotMove();
				break;
			}
		};
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

int main()
{
	CGame Game;
	Game.PrintMap();
	Game.PrintGame();
	while(true)
	{
		char c;
		cout<<"Your move: ";
		cin>>c;
		Game.Move(c);
		Game.PrintGame();
		if(Game.isBomb())
		{
			Game.Reset();
			cout<<"Bang";
			Game.PrintGame();
		}
		if(Game.isDead())
		{
			cout<<"Lose";
			break;
		}
		if(Game.isWinning())
		{
			cout<<"Win";
			Game.NextLevel();
			Game.PrintGame();
		}
	}

}
