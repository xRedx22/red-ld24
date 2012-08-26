#include <iostream>

#include <SFML/Graphics.hpp>

#include "app/app.h"
#include "game/character.h"
#include "graphics/sprite.h"

using namespace std;

int main()
{
    app::app game;
    game.create();

    game::world world;
    game::controller control;

    sf::Texture test;
    if (!test.loadFromFile("rc/test_sheet.png"))
    {
        cout << "Error loading test image\n";
        return 1;
    }

    graphics::animation sprite(test, 5, 6, 16);

    game::character player(sprite, game, control);
    world.add(player);

    while (game.window.isOpen())
    {
        game.window.clear();

        game.input(control);
        world.tick();

        game.window.display();
    }

    world.destroy(player);
    return 0;
}
