#include<C:\Users\quang\Desktop\FollowPrincess\main.h>
#include<C:\Users\quang\Desktop\FollowPrincess\CMap.h>

void CMap::Setpath(int u, int v){
	// will work later
	for (int i = 0; i < MapSize; i++)
		MapArray[i][0] = 0;
	for (int j = 0; j < MapSize; j++)
		MapArray[MapSize - 1][j] = 0;
}
void CMap::AssignNewPosition(int _x, int _y)
{
	x = _x;
	y = _y;
}

bool CMap::isBomb()
{
	return MapArray[x][y];
}
bool CMap::isWinning()
{
	return (x == MapSize - 1 && y == MapSize - 1);
}
bool CMap::goUp()		{	if (x == 0) return false; x--; return true;}
bool CMap::goDown() 	{	if (x == MapSize - 1) return false; x++; return true;}
bool CMap::goLeft()	{	if (y == 0) return false; y--; return true;}
bool CMap::goRight()	{	if (y == MapSize - 1) return false; y++; return true;	}

void CMap::PrintPosition()
{
	cout << "Position:" << x << " " << y << endl;
}
// Map
void CMap::AssignNewMap(int _MapSize)
{
	MapSize = _MapSize;
	MapArray.clear();
	for (int i = 0; i < _MapSize; i++)
	{
		vector<int> v;
		for (int j = 0; j < _MapSize; j++)
			v.push_back(1);
		MapArray.push_back(v);
	}
	Setpath(0, 0);
}
void CMap::NextLevel()
{
	AssignNewMap(MapSize + 1);
	AssignNewPosition();
}
void CMap::PrintMap()
{
	cout << "Map: \n";
	for (int i = 0; i < MapSize; i++)
	{
		for (int j = 0; j < MapSize; j++)
			cout << MapArray[i][j] << " ";
		cout << endl;
	}
}
void CMap::PrintGame()
{
	cout <<	"Map:\n";
	for (int i = 0; i < MapSize; i++)
	{
		for (int j = 0; j < MapSize; j++)
			if (i == x && j == y)
				cout << "x ";
			else
				cout << "o ";
		cout << endl;
	}
}