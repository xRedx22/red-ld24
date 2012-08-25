#ifndef app_h
#define app_h

#define GLEW_BUILD

#include <string>
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "game/controller.h"

namespace app
{
    class app
    {
        private:
            bool _fullscreen;
            sf::VideoMode _video;

        public:
            sf::RenderWindow window;

            app();

            void create();
            void setFull(bool fullscreen_);
            void toggleFull();
            void input(game::controller& controller_);
    };
}

#endif
