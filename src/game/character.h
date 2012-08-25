#ifndef game_character_h
#define game_character_h

#include <iostream>

#include "entity.h"
#include "controller.h"

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
            charInput _input;
            controller& _controller;

        public:
            float x, y;

            character(controller& controller_) : _input(controller_.state, _xvel, _yvel), _controller(controller_) {};

            void tick();
            void destroy();
    };
}

#endif
