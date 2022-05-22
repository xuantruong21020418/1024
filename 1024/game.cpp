#include "styles.h"
#include "game.h"
#include <ctime>
#include <stdlib.h>
#include <SDL_mixer.h>
#include <stdio.h>



/* The pointer to the background music.*/
Mix_Music* g_background_music = NULL;

Game mainGame;
/* The pointer to the mix music chunk.*/
Mix_Chunk* g_mix_music = NULL;
SDL_Window* g_window = NULL;
SDL_Renderer* g_renderer = NULL;

bool initSDL()
{
	TTF_Init();
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize. SDL_ERROR: %s\n", SDL_GetError());
		return false;
	}
	g_window = SDL_CreateWindow("1024", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (g_window == NULL)
	{
		printf("Window could not be created. SDL_ERROR: %s\n", SDL_GetError());
		return false;
	}
	g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
	if (g_renderer == NULL)
	{
		printf("Renderer could not be created. SDL_ERROR: %s\n", SDL_GetError());
		return false;
	}

	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}
	return true;
}

void draw_text(SDL_Renderer* renderer, TTF_Font* font, const char* text, SDL_Rect rect, SDL_Color color)
{
	SDL_Surface* surfaceMessage = TTF_RenderText_Blended(font, text, color);
	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_Rect message_rect;

	TTF_SizeText(font, text, &message_rect.w, &message_rect.h);
	message_rect.x = rect.x + rect.w / 2 - message_rect.w / 2;
	message_rect.y = rect.y + rect.h / 2 - message_rect.h / 2;

	SDL_RenderCopy(renderer, Message, NULL, &message_rect);
	SDL_DestroyTexture(Message);
	SDL_FreeSurface(surfaceMessage);
}

void draw_white_text(SDL_Renderer* renderer, TTF_Font* font, const char* text, SDL_Rect rect)
{
	SDL_Color White = { 255, 255, 255 };
	draw_text(renderer, font, text, rect, White);
}

void closeSDL()
{
	SDL_DestroyWindow(g_window);
	g_window = NULL;
	SDL_DestroyRenderer(g_renderer);
	g_renderer = NULL;
	TTF_Quit();
	SDL_Quit();
}

void clear_screen(SDL_Renderer* renderer)
{

	SDL_SetRenderDrawColor(renderer, g_bg.r, g_bg.g, g_bg.b, g_bg.a);
	SDL_RenderClear(renderer);
}

void draw_black_text(SDL_Renderer* renderer, const char* text, int size)
{
	TTF_Font* font = NULL;
	font = TTF_OpenFont(FONT_PATH, size);
	if (font == NULL)
	{
		printf("The required font was not found. TTF_OpenFont: %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_Color black = { g_fg.r, g_fg.g, g_fg.b, g_fg.a };
	clear_screen(renderer);
	SDL_Rect rect1 = { SCREEN_PAD, SCREEN_HEIGHT / 4, SCREEN_WIDTH - 2 * SCREEN_PAD, SCREEN_HEIGHT / 2 };
	draw_text(renderer, font, text, rect1, black);
	SDL_RenderPresent(renderer);
	TTF_CloseFont(font);
}

void draw_board(SDL_Renderer* renderer, const Board board, TTF_Font* font)
{
	int squareSize = (SCREEN_WIDTH - 2 * SCREEN_PAD) / SIZE - SCREEN_PAD;

	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			SDL_Rect fillRect = { SCREEN_PAD + x * (squareSize + SCREEN_PAD), SCREEN_PAD + y * (squareSize + SCREEN_PAD), squareSize, squareSize };
			COLOR s = g_COLORS[board[y][x]];
			SDL_SetRenderDrawColor(renderer, s.r, s.g, s.b, s.a);
			SDL_RenderFillRect(renderer, &fillRect);
			char str[15];
			sprintf_s(str, "%lu", pow_int(BASE, board[y][x]));

			if (board[y][x] == 0)
			{
				str[0] = ' ';
				str[1] = '\0';
			}
			draw_white_text(renderer, font, str, fillRect);

		}
	}
}

void handle_move(SDL_Event e, Board board, SDL_Renderer* renderer)
{
	switch (e.key.keysym.sym)
	{
	case SDLK_UP:
		Mix_PlayChannel(-1, g_mix_music, 0);
		
		break;
	case SDLK_DOWN:
		Mix_PlayChannel(-1, g_mix_music, 0);
		mainGame.move_y(board, 1);
		break;
	case SDLK_LEFT:
		Mix_PlayChannel(-1, g_mix_music, 0);
		mainGame.move_x(board, 0);
		break;
	case SDLK_RIGHT:
		Mix_PlayChannel(-1, g_mix_music, 0);
		mainGame.move_x(board, 1);
		break;
	default:;
	}
}

void draw_new_game_button(SDL_Renderer* renderer, TTF_Font* font)
{
	char txt[] = "New Game";
	SDL_Rect fillRect = { SCREEN_PAD / 2,
						 SCREEN_WIDTH + SCREEN_PAD,
						 SCREEN_WIDTH / 2 - 2 * SCREEN_PAD,
						 (SCREEN_HEIGHT - SCREEN_WIDTH) - 2 * SCREEN_PAD };
	SDL_SetRenderDrawColor(renderer, g_button_bg.r, g_button_bg.g, g_button_bg.b, g_button_bg.a);
	SDL_RenderFillRect(renderer, &fillRect);
	draw_white_text(renderer, font, txt, fillRect);
}
void button_handler(SDL_Event e, Board board)
{
	SDL_Rect draw_rect = { SCREEN_PAD / 2,
						  SCREEN_WIDTH + SCREEN_PAD,
						  SCREEN_WIDTH / 2 - 2 * SCREEN_PAD,
						  SCREEN_HEIGHT - SCREEN_WIDTH - 2 * SCREEN_PAD };
	if (e.button.button == SDL_BUTTON_LEFT &&
		e.button.x >= draw_rect.x &&
		e.button.x <= (draw_rect.x + draw_rect.w) &&
		e.button.y >= draw_rect.y &&
		e.button.y <= (draw_rect.y + draw_rect.h))
	{
		mainGame.clear_board(board);
		mainGame.add_random(board);
	}
}
void draw_score(SDL_Renderer* renderer, Board board, TTF_Font* font)
{
	char score[15]; //15 chars is enough for score.
	sprintf_s(score, "%lu", mainGame.calculate_score(board));
	char scoreText[30] = "Score:";
	strncat_s(scoreText, score, 15);
	SDL_Rect fillRect = { SCREEN_WIDTH / 2 + 5,
						 SCREEN_WIDTH + SCREEN_PAD,
						 SCREEN_WIDTH / 2 - 2 * SCREEN_PAD,
						 SCREEN_HEIGHT - SCREEN_WIDTH - 2 * SCREEN_PAD };
	SDL_SetRenderDrawColor(renderer, g_score_bg.r, g_score_bg.g, g_score_bg.b, g_score_bg.a);
	SDL_RenderFillRect(renderer, &fillRect);
	draw_white_text(renderer, font, scoreText, fillRect);
}
void render_game(SDL_Renderer* renderer, Board board, TTF_Font* font)
{
	clear_screen(renderer);
	draw_board(renderer, board, font);
	draw_score(renderer, board, font);
	draw_new_game_button(renderer, font);
	SDL_RenderPresent(renderer);
}

void game_loop(Board board, SDL_Renderer* renderer)
{
	TTF_Font* font = NULL;
	font = TTF_OpenFont(FONT_PATH, CELL_FONT_SIZE);
	if (font == NULL)
	{
		printf("The required font was not found. TTF_OpenFont: %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

	render_game(renderer, board, font);

	bool quit = false;
	SDL_Event e;
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYUP)
			{
				handle_move(e, board, renderer);
				if (mainGame.is_game_over(board))
				{
					draw_black_text(renderer, "Game Over!", GOVER_FONT_SIZE);
					SDL_Delay(2000);
					mainGame.clear_board(board);
					mainGame.add_random(board);
				}
				//Redraw all portions of game
				render_game(renderer, board, font);
			}
			else if (e.type == SDL_MOUSEBUTTONUP)
			{
				button_handler(e, board);
				render_game(renderer, board, font);
			}
		}
	}
	TTF_CloseFont(font);
}

void load_music() {
	g_background_music = Mix_LoadMUS(BACKGROUND_MUSIC_PATH);
	g_mix_music = Mix_LoadWAV(MIX_MUSIC_PATH);
	if (g_background_music == NULL || g_mix_music == NULL)
	{
		printf("Music files couldn't be loaded.");
		exit(EXIT_FAILURE);
	}

	Mix_PlayMusic(g_background_music, -1);
}

int main(int argc, char* argv[])
{
	srand(time(NULL));

	//Set up the game board.
	unsigned char board[SIZE][SIZE];
	mainGame.clear_board(board);
	mainGame.add_random(board);

	initSDL();
	load_music();
	
	draw_black_text(g_renderer, "1024", TITLE_FONT_SIZE);
	SDL_Delay(1500);
	game_loop(board, g_renderer);

	closeSDL();
	Mix_FreeMusic(g_background_music);
	Mix_FreeChunk(g_mix_music);

	return EXIT_SUCCESS;
}