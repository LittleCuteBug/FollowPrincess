class CMap
{
private:
	vector<vector<int> > MapArray;
	int x, y, MapSize;


	void Setpath(int u, int v)
	{
		// will work later
		for (int i = 0; i < MapSize; i++)
			MapArray[i][0] = 0;
		for (int j = 0; j < MapSize; j++)
			MapArray[MapSize - 1][j] = 0;
	}
public:
	// Position
	void AssignNewPosition(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}
	
	bool isBomb()
	{
		return MapArray[x][y];
	}
	bool isWinning()
	{
		return (x==MapSize-1 && y ==MapSize-1);
	}
	bool goUp()		{	if (x == 0) return false; x--; return true;}
	bool goDown() 	{	if (x == MapSize-1) return false; x++; return true;}
	bool goLeft()	{	if (y == 0) return false; y--; return true;}
	bool goRight()	{	if (y == MapSize-1) return false; y++; return true;	}

	void PrintPosition()
	{
		cout << "Position:" << x << " " << y << endl;
	}
	// Map
	void AssignNewMap(int _MapSize)
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
	void NextLevel()
	{
		AssignNewMap(MapSize+1);
		AssignNewPosition();
	}
	void PrintMap()
	{
		cout << "Map: \n";
		for (int i = 0; i < MapSize; i++)
		{
			for (int j = 0; j < MapSize; j++)
				cout << MapArray[i][j] << " ";
			cout << endl;
		}
	}
	void PrintGame()
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
};