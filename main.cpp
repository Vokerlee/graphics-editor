#include "button.hpp"

int main()
{
    button red({ 200, 200 }, { 20, 20 }, 100, 200, 100);

    red.action();

    return 0;
}