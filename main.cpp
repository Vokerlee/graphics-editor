#include "window.hpp"

int main()
{
    window manager(850, 550, "Paint");

    manager.add_button(new button(100, 50, 620, 430, 255, 255, 255));
    manager.add_button(new button(755, 100, 25, 25, 255, 0, 0));
    manager.add_button(new button(755, 140, 25, 25, 0, 255, 0));
    manager.add_button(new button(755, 180, 25, 25, 0, 0, 255));
    manager.add_button(new button(755, 220, 25, 25, 0, 255, 255));
    manager.add_button(new button(755, 260, 25, 25, 255, 0, 255));
    manager.add_button(new button(755, 300, 25, 25, 255, 255, 0));

    manager.run();

    return 0;
}