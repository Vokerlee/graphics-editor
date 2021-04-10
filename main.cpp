#include "window.hpp"

const int X_SIZE = 1000;
const int Y_SIZE = 700;

int main()
{
    // MANAGER
    window manager(X_SIZE, Y_SIZE, "Paint");

    // COLOURS
    manager.add_tool(new visual_section(X_SIZE - 200 - 2, 2, 200, 140, "Colours"));

    manager.add_tool(new colour_button(X_SIZE - 180, 50, 25, 25, 255, 0, 0));
    manager.add_tool(new colour_button(X_SIZE - 140, 50, 25, 25, 0, 255, 0));
    manager.add_tool(new colour_button(X_SIZE - 100, 50, 25, 25, 0, 0, 255));
    manager.add_tool(new colour_button(X_SIZE - 60, 50, 25, 25, 0, 255, 255));
    manager.add_tool(new colour_button(X_SIZE - 140, 90, 25, 25, 255, 0, 255));
    manager.add_tool(new colour_button(X_SIZE - 100, 90, 25, 25, 255, 255, 0));

    // FIGURES
    manager.add_tool(new visual_section(X_SIZE - 200 - 2, 142, 200, 140, "Figures"));
    manager.add_tool(new ellipse(X_SIZE - 180, 180, 30, 15, 100, 70, 70));
    manager.add_tool(new rectangle(X_SIZE - 140, 180, 30, 15, 100, 70, 70));
    manager.add_tool(new triangle(X_SIZE - 100, 180, 30, 15, 100, 70, 70));

    // THICKNESS
    manager.add_tool(new visual_section(X_SIZE - 200 - 2, 282, 200, 60, "Thickness"));
    manager.add_tool(new thikness_adjuster(X_SIZE - 125, 310));

    // SIZES AND ANGLE
    manager.add_tool(new visual_section(X_SIZE - 200 - 2, 342, 200, 60, "X size"));
    manager.add_tool(new xsize_adjuster(X_SIZE - 125, 370));

    manager.add_tool(new visual_section(X_SIZE - 200 - 2, 402, 200, 60, "Y size"));
    manager.add_tool(new ysize_adjuster(X_SIZE - 125, 430));

    manager.add_tool(new visual_section(X_SIZE - 200 - 2, 462, 200, 60, "All sizes"));
    manager.add_tool(new scale_size_adjuster(X_SIZE - 125, 490));

    manager.add_tool(new visual_section(X_SIZE - 200 - 2, 522, 200, 60, "Angle"));
    manager.add_tool(new angle_adjuster(X_SIZE - 125, 550));

    // CANVAS
    manager.add_tool(new canvas(50, 50, 720, 500, 255, 255, 255));


    manager.run();

    return 0;
}