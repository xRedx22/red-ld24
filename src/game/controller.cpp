#include "controller.h"

namespace game
{
    controller::controller()
    {
        for (unsigned int i = 0; i < _inputs.size(); i ++)
        {
            state.down[i] = false;
        }
    }

    void controller::input(sf::Event event_)
    {
        for (unsigned int i = 0; i < _inputs.size(); i ++)
        {
            _inputs[i]->input(event_);
        }
    }

    void controller::track(gameInput& input_)
    {
        _inputs.push_back(&input_);
    }

    void controller::untrack(gameInput& input_)
    {
        for (unsigned int i = 0; i < _inputs.size(); i ++)
        {
            if (&input_ == (_inputs[i]))
            {
                _inputs.erase(_inputs.begin() + i);
                break;
            }
        }
    }
}
