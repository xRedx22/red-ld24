#include <iostream>

#include "app/app.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    app::app game;
    game.create();

    while (game.window.isOpen())
    {
        game.input();
        game.window.display();
    }
}
