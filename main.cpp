#include "window.hpp"

int main()
{
    window manager(850, 550, "Paint");

    manager.add_tool(new ellipse(30, 50, 20, 10, 100, 55, 55));
    manager.add_tool(new canvas(100, 50, 620, 430, 255, 255, 255));
    manager.add_tool(new colour_button(755, 100, 25, 25, 255, 0, 0));
    manager.add_tool(new colour_button(755, 140, 25, 25, 0, 255, 0));
    manager.add_tool(new colour_button(755, 180, 25, 25, 0, 0, 255));
    manager.add_tool(new colour_button(755, 220, 25, 25, 0, 255, 255));
    manager.add_tool(new colour_button(755, 260, 25, 25, 255, 0, 255));
    manager.add_tool(new colour_button(755, 300, 25, 25, 255, 255, 0));

    manager.run();

    return 0;
}