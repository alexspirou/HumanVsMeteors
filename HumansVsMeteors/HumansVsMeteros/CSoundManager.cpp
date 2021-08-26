#include "CSoundManager.h"

CSoundManager::CSoundManager()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		std::cout << "Error: " << Mix_GetError() << std::endl;
}

void CSoundManager::loadSound(const char* id)
{
	m_sfx = Mix_LoadWAV(id);
	Mix_PlayChannel(-1, m_sfx, 0);

}

void CSoundManager::playSound()
{
	Mix_PlayChannel(-1, m_sfx, 0);

}
void  CSoundManager::clean()
{
	Mix_FreeChunk(m_sfx);
	Mix_Quit();
}