#include "../include/main.h"
#include "../include/CGame.h"

void CPlayer::SDLRenderingGame()
{
	;
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