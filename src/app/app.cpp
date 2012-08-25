#include "app.h"

namespace app
{
    app::app()
    {
        _fullscreen = true;
        _video = sf::VideoMode::getDesktopMode();
    }

    void app::create()
    {
        sf::Uint32 style_ = sf::Style::Titlebar | (_fullscreen ? sf::Style::Fullscreen : sf::Style::None);

        window.create(_video, std::string("ld24"), style_);
        window.setVerticalSyncEnabled(true);
    }

    void app::setFull(bool fullscreen_)
    {
        _fullscreen = fullscreen_;
        create();
    }

    void app::toggleFull()
    {
        setFull(!_fullscreen);
    }

    void app::input(game::controller& controller_)
    {
        sf::Event event_;

        while (window.pollEvent(event_))
        {
            controller_.input(event_);

            switch (event_.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    switch (event_.key.code)
                    {
                        case sf::Keyboard::Escape:
                            window.close();
                            break;

                        case sf::Keyboard::F11:
                            toggleFull();
                            break;

                        default:
                            break;
                    }
                default:
                    break;
            }
        }
    }
}
