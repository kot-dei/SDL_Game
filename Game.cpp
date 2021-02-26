#include "Game.h"

bool Game::init(const char *title, int x_pos, int y_pos, int width, int height, int flags)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success" << std::endl;
        m_pWindow = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);
        if(m_pWindow != 0)
        {
            std::cout << "Create Window success" << std::endl;
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if(m_pRenderer != 0)
            {
                std::cout << "Renderer creation succes" << std::endl;
                SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
            }
            else
            {
                std::cout << "window init fail" << std::endl;
                return false;
            }
        }
        else
        {
            std::cout << "renderer init fail" << std::endl;
            return false;
        }
    }  
    else
    {
        std::cout << "SDL_Init fail" << std::endl;
    } 
    std::cout << "init success" << std::endl;
    m_bRunning = true;
    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    SDL_RenderPresent(m_pRenderer);
}

void Game::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_bRunning = false;
            break;

        default:
        break;
        }
    }
}

void Game::clean()
{
    std::cout << "cleaning game" << std::endl;
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}