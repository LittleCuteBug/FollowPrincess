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
extern SDL_Renderer* gRenderer;
extern string Imagepath [];
extern SDL_Texture* gImage[NumberOfImage];

bool init();
void RenderImage(SDL_Texture* Image, double x, double y, double w, double h);
SDL_Texture* loadTexture( string path );
bool loadMedia();
void close();
