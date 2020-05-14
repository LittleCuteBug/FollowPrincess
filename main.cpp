#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <stack>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>

#define ll long long
#define ld long double
#define endl '\n'
#define maxN 1000001
#define maxM 1000001
#define oo 1000000000000000001
#define Mod 1000000007
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define fi first
#define se second

#define pc putchar
#define gc getchar

using namespace std;


class Player
{
private:
	int Life, Level;
	class Position
	{
	private:
		int x, y;
	public:
		void AssignNewPosition(int _x = 0, int _y = 0)
		{
			x=_x;
			y=_y;
		}
		void Print()
		{
			cout<<"Position:"<<x<<" "<<y<<endl;
		}
		void Goup()		{	y++;	}
		void Godown() 	{	y--;	}
		void Goleft()	{	x--;	}
		void Goright()	{	x++;	}
	};
	Position CurrentPosition;
	class Map
	{
	private:
		vector<vector<int> > MapArray;
		void Setpath(int u, int v)
		{
			// will work later
			for (int i = 0; i < MapSize; i++)
				MapArray[i][0] = 0;
			for (int j = 0; j < MapSize; j++)
				MapArray[MapSize - 1][j] = 0;
		}
	public:
		int MapSize;
		void AssignNewMap(int _MapSize)
		{
			MapSize = _MapSize;
			for (int i = 0; i < _MapSize; i++)
			{
				vector<int> v;
				for (int j = 0; j < _MapSize; j++)
					v.push_back(1);
				MapArray.push_back(v);
			}
			Setpath(0, 0);
		}
		void Print()
		{
			cout << "Map: \n";
			for (int i = 0; i < MapSize; i++)
			{
				for (int j = 0; j < MapSize; j++)
					cout << MapArray[i][j] << " ";
				cout << endl;
			}
		}
	};
	Map CurrentMap;
public:
	Player(int _life = 10, int _level = 1, int _MapSize = 4, int _PositionX = 0, int _PositionY = 0)
	{
		Life = _life;
		Level = _level;
		CurrentMap.AssignNewMap(_MapSize);
		CurrentPosition.AssignNewPosition(_PositionX,_PositionY);
	}
	void LifeDecrease()
	{
		Life--;
	}
	void LifeRestore(int _Life = 10)
	{
		Life = _Life;
	}
	void LevelIncrease()
	{
		Level++;
	}
	void NewLevel()
	{
		LevelIncrease();
		LifeRestore();
		CurrentMap.AssignNewMap(CurrentMap.MapSize+1);
		CurrentPosition.AssignNewPosition();
	}
	void Print()
	{
		cout << "Life: " << Life << "  Level: " << Level << endl;
		CurrentMap.Print();
		CurrentPosition.Print();
	}
};
void Solve()
{

}
void Enter()
{
	Player NewPlayer;
	NewPlayer.Print();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("/Users/quanghuy/Desktop/Input.inp","r", stdin);
	//freopen("/Users/quanghuy/Desktop/Output.out","w", stdout);
	//freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	Enter();
	Solve();
}