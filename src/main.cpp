#include <iostream>

#include <SFML/Graphics.hpp>

#include "app/app.h"
#include "game/character.h"

using namespace std;

int main()
{
    app::app game;
    game.create();

    game::world world;
    game::controller control;

    game::character player(control);
    world.add(player);

    sf::Texture test;
    if (!test.loadFromFile("rc/test_player.png"))
    {
        cout << "Error loading test image\n";
        return 1;
    }

    sf::Sprite sprite(test);

    while (game.window.isOpen())
    {
        game.input(control);
        world.tick();

        game.window.clear();

        sprite.setPosition(player.x, player.y);
        game.window.draw(sprite);

        game.window.display();
    }

    world.destroy(player);
    return 0;
}
