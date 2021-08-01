#include <iostream>
#include "SDL.h"
#include <SDL_image.h>
#include "CEngine.h"
#include "CMenu.h"

int main(int argc, char** argv)
{
    CEngine* engine = nullptr;
    engine = new CEngine();
    while (engine->getIsRunning())
    {
        //Handle all the inputs from user
        engine->event();
        //Update the changes
        engine->update();
        //Render the changes
        engine->render();
    }
    engine->clean();
    delete  engine;

    return 0;
}