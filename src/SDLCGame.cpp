#include "../include/main.h"
#include "../include/CGame.h"

void CPlayer::SDLRenderingGame()
{
	RenderImage(gImage[StatusImage],
		0,0,
		SCREEN_WIDTH,
		SCREEN_HEIGHT
		);
	// Rendering Level
	int lv = Level;
	double x = 940,y = 45;
	while(lv!=0)
	{
		int digit = lv%10;
		lv/=10;
		RenderImage(gNumber[digit],
			x,
			y,
			50*0.7,
			70*0.7
		);
		x-=50*0.7;
	}
	//Rendering Life
	int lf = Life;
	x = 940,y = 100;
	while(lf!=0)
	{
		int digit = lf%10;
		lf/=10;
		RenderImage(gNumber[digit],
			x,
			y,
			50*0.6,
			70*0.6
		);
		x-=50*0.6;
	}
}

void CMap::SDLRenderingGame()
{
	double CellSize = MAP_SIZE / MapSize;
	for (int i = 0; i < MapSize; i++)
	{
		for (int j = 0; j < MapSize; j++)
		{
			double x = MAP_LOCATION + j * CellSize;
			double y = MAP_LOCATION + i * CellSize;
			double w = CellSize;
			double h = CellSize;
			RenderImage(gImage[MapCellImage], x, y, w, h);
		}
	}
	RenderImage(gImage[MapStartCellImage],
	            MAP_LOCATION,
	            MAP_LOCATION,
	            CellSize,
	            CellSize);

	RenderImage(gImage[MapFinishCellImage],
	            MAP_LOCATION + (MapSize - 1)*CellSize,
	            MAP_LOCATION + (MapSize - 1)*CellSize,
	            CellSize,
	            CellSize);

	RenderImage(gImage[PrincessImage],
	            MAP_LOCATION + y * CellSize,
	            MAP_LOCATION + x * CellSize,
	            CellSize,
	            CellSize);
}

void CMap::SDLRenderingMap()
{
	double CellSize = MAP_SIZE / MapSize;
	for (int i = 0; i < MapSize; i++)
	{
		for (int j = 0; j < MapSize; j++)
		{
			double x = MAP_LOCATION +  j * CellSize;
			double y = MAP_LOCATION + i * CellSize;
			double w = CellSize;
			double h = CellSize;
			if (MapArray[i][j] == 0)
				RenderImage(gImage[MapSafeCellImage], x, y, w, h);
			else
				RenderImage(gImage[MapBombCellImage], x, y, w, h);
		}
	}
	RenderImage(gImage[MapStartCellImage],
	            MAP_LOCATION,
	            MAP_LOCATION,
	            CellSize,
	            CellSize);

	RenderImage(gImage[MapFinishCellImage],
	            MAP_LOCATION + (MapSize - 1)*CellSize,
	            MAP_LOCATION + (MapSize - 1)*CellSize,
	            CellSize,
	            CellSize);

	RenderImage(gImage[PrincessImage],
	            MAP_LOCATION + y * CellSize,
	            MAP_LOCATION + x * CellSize,
	            CellSize,
	            CellSize);
}