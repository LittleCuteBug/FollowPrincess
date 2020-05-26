class CMap
{
private:
	int MapArray[100][100];
	int x, y, MapSize;
	int t[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
	bool flag = false;
	bool Check(int u, int v);
	void DFS(int u, int v);
	bool Valid();
	void SetPath();
public:
	// Position
	static int myrandom (int i);
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
	void SDLRenderingMap();
};