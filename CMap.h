class CMap
{
private:
	vector<vector<int> > MapArray;
	int x, y, MapSize;


	void Setpath(int u, int v);
public:
	// Position
	void AssignNewPosition(int _x = 0, int _y = 0);
	bool isBomb();
	bool isWinning();
	bool goUp();
	bool goDown();
	bool goLeft();
	bool goRight();
	void PrintPosition();
	// Map
	void AssignNewMap(int _MapSize);
	void NextLevel();
	void PrintMap();
	void PrintGame();
	void SDLRenderingGame();	
};