#include "sprite.h"

namespace graphics
{
    animation::animation(const sf::Texture& image_, unsigned int xwidth_, unsigned int ywidth_, unsigned int xcount_, unsigned int ycount_, float time_) : _image(image_)
    {
        _count = xcount_ * ycount_;
        _time = time_;

        unsigned int xinc_, yinc_;
        xinc_ = xwidth_ / xcount_;
        yinc_ = ywidth_ / ycount_;

        for (unsigned int y_ = 0; y_ < ycount_; y_ ++)
        {
            for (unsigned int x_ = 0; x_ < xcount_; x_ ++)
            {
                _frames.push_back(sf::IntRect(x_ * xinc_, y_ * yinc_, (x_ + 1) * xinc_, (y_ + 1) * yinc_));
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
        if (frame_ > _image->frames())
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
