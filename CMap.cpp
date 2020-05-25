#include<C:\Users\quang\Desktop\FollowPrincess\main.h>
#include<C:\Users\quang\Desktop\FollowPrincess\CMap.h>

int CMap::myrandom (int i) { return std::rand()%i;}
bool CMap::Check(int u,int v)
{
	return u>=0&&u<MapSize&&v>=0&&v<MapSize&&MapArray[u][v]==0;
}
void CMap::DFS(int u,int v)
{
	if(u==MapSize-1&&v==MapSize-1)
	{
		flag = true;
		return;
	}
	if(MapArray[u][v]==1)
		return;
	for(int i=0;i<4;i++)
	{
		if(Check(u+t[0][i],v+t[1][i]))
		{
			MapArray[u+t[0][i]][v+t[1][i]] = -1;
			DFS(u+t[0][i],v+t[1][i]);
		}
	}
}
bool CMap::Valid()
{
	flag = false;
	DFS(0,0);
	for(int i=0;i<MapSize;i++)
		for(int j=0;j<MapSize;j++)
			if(MapArray[i][j]==-1) MapArray[i][j] = 0;
	return flag;
}
void CMap::SetPath()
{
	srand( time( NULL ) );
	vector<int> Index;
	for(int i=0;i<MapSize*MapSize;i++)
		Index.push_back(i);
	std::random_shuffle(Index.begin(),Index.end(),myrandom);
	for(int i=0;i<MapSize*MapSize;i++)
	{
		int u = Index[i]%MapSize;
		int v = Index[i]/MapSize;
		MapArray[u][v] = 1;
		//cout<<"Erase: "<<u<<" "<<v<<endl;
		if(!Valid())
			MapArray[u][v]= 0;
	}
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
	fill_n(&MapArray[0][0],sizeof(MapArray)/sizeof(MapArray[0][0]),0);
	SetPath();
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