#ifndef graphics_sprite_h
#define graphics_sprite_h

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace graphics
{
    class animation
    {
        private:
            unsigned int _count;
            float _time;
            const sf::Texture& _image;
            std::vector<sf::IntRect> _frames;

        public:
            animation(const sf::Texture& image_, unsigned int xwidth_, unsigned int ywidth_, unsigned int xcount_, unsigned int ycount_, float time_);

            const unsigned int& frames() {return _count;};
            const float& duration() {return _time;};
            const sf::Texture& texture() {return _image;};
            const sf::IntRect& frame(unsigned int i_) {return _frames[i_];};
    };

    class sprite: public sf::Sprite
    {
        private:
            bool _running;
            unsigned int _frame;
            animation* _image;
            sf::Clock _time;

        public:
            sprite(animation& image_) : sf::Sprite(), _running(true) {setImage(image_);};

            void tick();
            void setFrame(unsigned int frame_);
            void setImage(animation& image_);
            void setRunning(bool running_);
    };
}

#endif
