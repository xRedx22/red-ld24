#include <iostream>

#include "app/app.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    app::app game;
    game.create();

    game::controller control;

    while (game.window.isOpen())
    {
        game.input(control);
        game.window.display();
    }
}
