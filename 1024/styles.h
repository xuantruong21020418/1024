#pragma once


#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 600
/* The padding to use while drawing elements to window */
#define SCREEN_PAD 10

#define FONT_PATH "FiraCode-Regular.ttf"

/* The font size used while displaying "1024" at the start of game. */
#define TITLE_FONT_SIZE 180

/* The font size used while displaying "Game Over" at the end of game. */
#define GOVER_FONT_SIZE 75

/* The font size used while displaying each number inside the cells */
#define CELL_FONT_SIZE 40

#define MIX_MUSIC_PATH "mix.wav"

#define BACKGROUND_MUSIC_PATH "background.mp3"

class COLOR
{
public:
     unsigned char r;
     unsigned char g;
     unsigned char b;
     unsigned char a;
     COLOR(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a) {
         r = _r;
         g = _g;
         b = _b;
         a = _a;
     }
};

/* The background color used by the application */ 
COLOR g_bg(214, 201, 195, 255);

/* The text color used by the ui elemets (dark only). */
COLOR g_fg(80, 80, 80, 255);

/* The background color used by the new game button  */
COLOR g_button_bg(255, 153, 102, 255);

/* The background color used by the score field  */
COLOR g_score_bg(143, 122, 102, 255);

/* The colors used by the tiles
   They are according to exponent.
   Example: exponent of 1 will use g_COLORS[1]
 */
COLOR g_COLORS[] = {
    {230, 227, 232, 255},
    {224, 217, 202, 255},
    {235, 195, 145, 255},
    {235, 177, 106, 255},
    {235, 139, 70, 255},
    {235, 110, 21, 255},
    {240, 71, 14, 255},
    {245, 217, 95, 255},
    {242, 205, 41, 255},
    {245, 203, 17, 255},
    {221, 245, 7, 255},
    {142, 245, 7, 255},
    {27, 245, 7, 255},
    {7, 245, 197, 255},
    {7, 205, 245, 255},
    {7, 110, 245, 255},
    {1, 50, 115, 255} };
