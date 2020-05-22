#include<C:\Users\quang\Desktop\FollowPrincess\main.h>
#include<C:\Users\quang\Desktop\FollowPrincess\CGame.h>
int main(int argc, char* args[])
{
	CGame Game;
	Game.PrintMap();
	Game.PrintGame();
	while(true)
	{
		char c;
		c = cin.get();
		if(Game.Move(c))
		{
			Game.PrintGame();
			if(Game.isBomb())
			{
				cout<<"Bang"<<endl;
				c = cin.get();
				Game.Reset();
				Game.PrintGame();
			}
			if(Game.isDead())
			{
				cout<<"Lose"<<endl;
				c = cin.get();
				break;
			}
			if(Game.isWinning())
			{
				cout<<"Win"<<endl;
				c = cin.get();
				Game.NextLevel();
				Game.PrintGame();
			}
		}
	}
}
