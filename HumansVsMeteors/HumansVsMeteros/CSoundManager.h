#pragma once
#include "SDL_mixer.h"
#include <iostream>
class CSoundManager
{

public:
	CSoundManager();
	void loadSound(const char* id);
	void playSound();
	void clean();

private:

	Mix_Chunk* m_sfx{};
};

