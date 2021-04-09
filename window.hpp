#pragma once

#include "colour_button.hpp"
#include "figures.hpp"
#include "canvas.hpp"
#include "config.hpp"

class window : noncopyable
{
private:

    sf::Vector2<int> size_;
    const char* name_;

    vidget** tools_;
    int n_tool_;

    draw_state state_;
    sf::Vector2i last_click_pos_;

    sf::RenderWindow shell_;

public:

    window(int x, int y, const char* name) :
        n_tool_(0),
        name_(name),
        state_(),
        last_click_pos_()
    {
        size_.x = x;
        size_.y = y;

        shell_.create(sf::VideoMode(x, y), name);
        shell_.clear(sf::Color(208, 242, 247, 255));

        tools_ = new vidget* [MAX_TOOLS_AMOUNT];
    }

    ~window()
    {
        size_.x = 0;
        size_.y = 0;
        name_ = nullptr;

        for (int i = 0; i < n_tool_; ++i)
            delete tools_[i];

        n_tool_ = 0;
        delete[] tools_;
    }

    void set_colour(sf::Color& colour)
    {
        shell_.clear(colour);
    }

    void set_colour(uint8_t red, uint8_t green, uint8_t blue)
    {
        shell_.clear(sf::Color(red, green, blue, 255));
    }

    void add_tool(vidget* tool)
    {
        tools_[n_tool_++] = tool;
    }

    void draw()
    {
        for (int i = 0; i < n_tool_; ++i)
        {
            (*(tools_[i])).draw(shell_);
        }
    }

    int get_tools()
    {
        return n_tool_;
    }

    void run()
    {
        while (shell_.isOpen())
        {
            sf::Event event;

            sf::Vector2i mouse_pos = sf::Mouse::getPosition(shell_);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition(shell_);

                if (mouse_pos != last_click_pos_)
                {
                    for (int i = 0; i < n_tool_; ++i)
                    {
                        if ((*tools_[i]).is_pressed(mouse_pos))
                            (*tools_[i]).action(state_);

                        printf("tool = %d\n", state_.current_tool);
                    }
                }

                last_click_pos_ = mouse_pos;
            }

            while (shell_.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    shell_.close();
            }

            shell_.clear(sf::Color(208, 242, 247, 255));
            draw();
            shell_.display();
        }
    }
};