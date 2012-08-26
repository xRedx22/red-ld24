#include "character.h"

namespace game
{
    void charInput::tick()
    {
        bool moveL_, moveR_, moveU_, moveD_;

        moveL_ = gameInput::_state.down[sf::Keyboard::A] | gameInput::_state.down[sf::Keyboard::Left];
        moveR_ = gameInput::_state.down[sf::Keyboard::D] | gameInput::_state.down[sf::Keyboard::Right];
        moveU_ = gameInput::_state.down[sf::Keyboard::W] | gameInput::_state.down[sf::Keyboard::Up];
        moveD_ = gameInput::_state.down[sf::Keyboard::S] | gameInput::_state.down[sf::Keyboard::Down];

        if (moveL_ != moveR_)
            _xvel = moveR_ ? _speed : -_speed;
        else
            _xvel = 0;

        if (moveU_ != moveD_)
            _yvel = moveD_ ? _speed : -_speed;
        else
            _yvel = 0;
    }

    void character::tick()
    {
        _input.tick();
        _image.tick();

        x += _xvel;
        y += _yvel;

        _image.setPosition(x, y);

        _app.window.draw(_image);
    }

    void character::destroy()
    {
        _controller.untrack(_input);
    }
}
