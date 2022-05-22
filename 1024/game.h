#pragma once
#include "core.h"
#include <SDL.h>
#include <SDL_ttf.h>

/* Initializes the SDL window. */
bool initSDL(SDL_Window* window, SDL_Renderer* renderer);

/* Frees up resource by destroying the SDL window. */
void closeSDL(SDL_Window* window);

/* Draws text centered inside the rect. */
void draw_text(SDL_Renderer* renderer, TTF_Font* font, const char* text, SDL_Rect rect, SDL_Color color);

/* Draws white text centered inside a rect. */
void draw_white_text(SDL_Renderer* renderer, TTF_Font* font, const char* text, SDL_Rect rect);

/* Clears the window screen. Fills a color to entire screen. */
void clear_screen(SDL_Renderer* renderer);

/* Draws black text centered inside the window. */
void draw_black_text(SDL_Renderer* renderer, const char* text, int size);

/* Draws the game tiles. */
void draw_board(SDL_Renderer* renderer, const Board board, TTF_Font* font);

/* Draws the new game button to the bottom corner. */
void draw_button(SDL_Renderer* renderer, TTF_Font* font);

/* Handles the action of New Game button. Resets the game board for a new game 
   if the correct mouse event had occured.
 */
void button_handler(SDL_Event e, Board board);

/* Draws the current game score to the window */
void draw_score(SDL_Renderer* renderer, Board board, TTF_Font* font);

/* Draws everything for the game and renders it to screen.
   It calls clear_screen(),draw_board(),draw_score() and draw_button()
   and also renders it to screen.
 */
void render_game(SDL_Renderer* renderer, Board board, TTF_Font* font);

/* The main game loop that handles all events and drawing */
void game_loop(Board board, SDL_Renderer* renderer);

/* Handles keyboard presses that correspond with the arrow keys
   It transforms the game board according to the keypresses.
   It also checks if the game has been finished, draws game over screen
   and resets the board if game over.
 */
void handle_move(SDL_Event e, Board board, SDL_Renderer* renderer);
