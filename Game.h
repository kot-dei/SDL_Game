#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Game
{
public:
	Game();
	~Game();
	bool init(const char *title, int x_pos, int y_pos, int width, int height, int flags);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return m_bRunning; };

private:
	SDL_Window *m_pWindow;
	SDL_Renderer *m_pRenderer;
	bool m_bRunning;
};
