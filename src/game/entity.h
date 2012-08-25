#ifndef game_entity_h
#define game_entity_h

#include <vector>

namespace game
{
    class entity
    {
        public:
            float x, y;

            virtual void tick() = 0;
            virtual void destroy() = 0;
    };

    class world
    {
        private:
            std::vector<entity*> _entities;

        public:
            void add(entity& entity_);
            void destroy(entity& entity_);
            void tick();
    };
}

#endif
