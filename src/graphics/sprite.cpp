#include "sprite.h"

namespace graphics
{
    animation::animation(const sf::Texture& image_, unsigned int xcount_, unsigned int ycount_, float time_) : _image(image_)
    {
        _count = xcount_ * ycount_;
        _time = time_;

        sf::Vector2u size_ = image_.getSize();

        unsigned int xinc_, yinc_;
        xinc_ = size_.x / xcount_;
        yinc_ = size_.y / ycount_;

        for (unsigned int y_ = 0; y_ < ycount_; y_ ++)
        {
            for (unsigned int x_ = 0; x_ < xcount_; x_ ++)
            {
                _frames.push_back(sf::IntRect(x_ * xinc_, y_ * yinc_, xinc_, yinc_));
            }
        }
    }

    void sprite::tick()
    {
        if (_running)
        {
            if (_time.getElapsedTime().asMilliseconds() >= _image->duration())
                setFrame(_frame + 1);
        }
    }

    void sprite::setFrame(unsigned int frame_)
    {
        if (frame_ >= _image->frames())
            frame_ = 0;

        _frame = frame_;
        _time.restart();

        setTextureRect(_image->frame(_frame));
    }

    void sprite::setImage(animation& image_)
    {
        _image = &image_;
        setTexture(_image->texture());
        setFrame(0);
    }

    void sprite::setRunning(bool running_)
    {
        _running = running_;
        _time.restart();
    }
}
