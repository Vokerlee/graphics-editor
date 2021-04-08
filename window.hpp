#pragma once

#include "button.hpp"
#include "config.hpp"

#include <SFML/Graphics.hpp>

class noncopyable
{
protected:
    noncopyable() {}
    ~noncopyable() {}
private:
    noncopyable(const noncopyable&);
    const noncopyable& operator=(const noncopyable&);
};

class window : noncopyable
{
private:

    vector2_t size_;
    const char* name_;

    button** buttons_;
    int n_button_;

    sf::RenderWindow shell_;
    sf::Texture paint_;
    sf::Sprite back_;

public:

    window(int x, int y, const char* name) :
        n_button_(0),
        name_(name)
    {
        size_.x_ = x;
        size_.y_ = y;

        shell_.create(sf::VideoMode(x, y), name);
        paint_.create(x, y);
        paint_.loadFromFile("back.png");
        back_.setTexture(paint_);
        back_.setOrigin(20, 20);
        back_.setScale(1, 1);

        buttons_ = new button* [MAX_BUTTONS_AMOUNT];
    }

    ~window()
    {
        size_.x_ = 0;
        size_.y_ = 0;
        name_ = nullptr;

        for (int i = 0; i < n_button_; ++i)
            delete buttons_[i];

        n_button_ = 0;
        delete[] buttons_;
    }

    void add_button(button* button)
    {
        buttons_[n_button_] = button;
        ++n_button_;
    }

    void run()
    {
        while (shell_.isOpen())
        {
            sf::Event event;

            while (shell_.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    shell_.close();
            }

            shell_.clear();
            shell_.draw(back_);
            shell_.display();
        }
    }
};