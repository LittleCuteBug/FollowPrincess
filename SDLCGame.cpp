#include<C:\Users\quang\Desktop\FollowPrincess\main.h>
#include<C:\Users\quang\Desktop\FollowPrincess\CGame.h>

void CPlayer::SDLRenderingGame()
{
	;
}

void CMap::SDLRenderingGame()
{
	for(int i=0;i<MapSize;i++)
	{
		for(int j=0;j<MapSize;j++)
		{
			double x = j*SCREEN_WIDTH/MapSize;
			double y = i*SCREEN_HEIGHT/MapSize;
			double w = SCREEN_WIDTH/MapSize;
			double h = SCREEN_HEIGHT/MapSize;
			RenderImage(gImage[MapSafeCellImage],x,y,w,h);
		}
	}

	RenderImage(gImage[MapStartCellImage],
		0,
		0,
		SCREEN_WIDTH/MapSize,
		SCREEN_HEIGHT/MapSize);

	RenderImage(gImage[MapFinishCellImage],
		(MapSize-1)*SCREEN_WIDTH/MapSize,
		(MapSize-1)*SCREEN_HEIGHT/MapSize,
		SCREEN_WIDTH/MapSize,
		SCREEN_HEIGHT/MapSize);

	RenderImage(gImage[PrincessImage],
		y*SCREEN_WIDTH/MapSize,
		x*SCREEN_HEIGHT/MapSize,
		SCREEN_WIDTH/MapSize,
		SCREEN_HEIGHT/MapSize);
}