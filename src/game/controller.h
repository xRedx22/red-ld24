#ifndef game_controller_h
#define game_controller_h

#include <vector>

#include <SFML/Window.hpp>

namespace game
{
    struct inputState
    {
        bool down[sf::Keyboard::KeyCount];
    };

    class gameInput
    {
        protected:
            inputState& _state;

        public:
            gameInput(inputState& state_) : _state(state_) {};

            virtual void input(sf::Event event_) = 0;
            virtual void tick() = 0;
    };

    class controller
    {
        private:
            std::vector<gameInput*> _inputs;

        public:
            inputState state;

            controller();

            void input(sf::Event event_);
            void track(gameInput& input_);
            void untrack(gameInput& input_);
    };
}

#endif
