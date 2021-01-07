const char MAP_PATH[11] = "C:map.txt",
FONT_PATH[27] = "C:/Windows/Fonts/Arial.ttf";

const int WINDOW_WIDTH = 640,
WINDOW_HEIGHT = 500,
TEXTURE_SIZE = 32;

enum MainMenuOption
{
	StartGame,
	EditMaps,
	Exit
};

//---------------------
enum ObjectType
{
	Space,
	Wall,
	Ladder,
	Rope,
	Money,
	Player,
	Enemy
};