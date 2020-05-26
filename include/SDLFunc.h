//Screen dimension constants
const double SCREEN_WIDTH = 1000;
const double SCREEN_HEIGHT = 720;
const double MAP_SIZE = 640;
const double MAP_LOCATION = 40;
//The window we'll be rendering to

enum Image
{
	BackgroundImage,
	MapCellImage,
	MapSafeCellImage,
	MapBombCellImage,
	MapStartCellImage,
	MapFinishCellImage,
	PrincessImage,
	WinningImage,
	LosingImage,
	BangImage,
	NumberOfImage
};
enum KeyPress
{
	GoUpKey,
	GoDownKey,
	GoLeftKey,
	GoRightKey
};

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern string Imagepath [];
extern SDL_Texture* gImage[NumberOfImage];

bool init();
void RenderImage(SDL_Texture* Image, double x, double y, double w, double h);
SDL_Texture* loadTexture( string path );
bool loadMedia();
void close();
