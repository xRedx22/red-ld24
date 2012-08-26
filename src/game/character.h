#ifndef game_character_h
#define game_character_h

#include <iostream>

#include "entity.h"
#include "controller.h"

#include "app/app.h"
#include "graphics/sprite.h"

namespace game
{
    class charInput: public gameInput
    {
        private:
            float& _xvel, &_yvel;
            float _speed;

        public:
            charInput(inputState& state_, float& xvel_, float& yvel_) : gameInput(state_), _xvel(xvel_), _yvel(yvel_), _speed(5) {};

            void input(sf::Event event_) {};
            void tick();
    };

    class character: public entity
    {
        private:
            float _xvel, _yvel;

            graphics::sprite _image;
            charInput _input;

            app::app& _app;
            controller& _controller;

        public:
            float x, y;

            character(graphics::animation& image_, app::app& app_, controller& controller_) : _image(image_), _input(controller_.state, _xvel, _yvel), _app(app_), _controller(controller_) {};

            void tick();
            void destroy();
    };
}

#endif
