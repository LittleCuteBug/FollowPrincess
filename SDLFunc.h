//Screen dimension constants
const double SCREEN_WIDTH = 640;
const double SCREEN_HEIGHT = 640;
//The window we'll be rendering to

enum Image
{
	//BackGroundImage,
	MapSafeCellImage,
	MapBombCellImage,
	MapStartCellImage,
	MapFinishCellImage,
	PrincessImage,
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
//The surface contained by the window
extern SDL_Surface* gScreenSurface;
extern string Imagepath [];
extern SDL_Surface* gImage[NumberOfImage];

bool init();
void RenderImage(SDL_Surface* Image, double x, double y, double w, double h);
SDL_Surface* loadSurface( std::string path );
bool loadMedia();
void close();
