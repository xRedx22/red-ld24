#include "entity.h"

namespace game
{
    void world::add(entity& entity_)
    {
        _entities.push_back(&entity_);
    }

    void world::destroy(entity& entity_)
    {
        for (unsigned int i = 0; i < _entities.size(); i ++)
        {
            if (&entity_ == _entities[i])
            {
                _entities[i]->destroy();
                _entities.erase(_entities.begin() + i);
                break;
            }
        }
    }

    void world::tick()
    {
        for (unsigned int i = 0; i < _entities.size(); i++)
        {
            _entities[i]->tick();
        }
    }
}
