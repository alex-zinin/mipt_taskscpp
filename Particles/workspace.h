#include <SFML/Graphics.hpp>
#include<cstdlib>
#include <vector>
#include<cstdio>
//#include<vector>
#include<cmath>

#include<ctime>
#include <iostream>
#include<algorithm>
//#include "vectoper.cpp"
//#include"molecule.cpp"
#include<SFML/Window.hpp>

using namespace std;

class WorkSpace
{
public:

    WorkSpace()
    {
        sf::RectangleShape rectangle;
        rectangle.setSize(sf::Vector2f(10, 1000));
        rectangle.setFillColor(sf::Color::White);
        rectangle.setPosition(300, 0);


        sf::RectangleShape rectangle2;
        rectangle2.setSize(sf::Vector2f(10, 1500));
        rectangle2.setFillColor(sf::Color::White);
        rectangle2.setPosition(900, 500);

        sf::RectangleShape rectangle3;
        rectangle3.setSize(sf::Vector2f(10, 1000));
        rectangle3.setFillColor(sf::Color::White);
        rectangle3.setPosition(1800, 0);

        sf::RectangleShape rectangle4;
        rectangle4.setSize(sf::Vector2f(10, 400));
        rectangle4.setFillColor(sf::Color::White);
        rectangle4.setPosition(900, 0);

        sf::RectangleShape rectangle5;
        rectangle5.setSize(sf::Vector2f(1800, 10));
        rectangle5.setFillColor(sf::Color::White);
        rectangle5.setPosition(0, 900);

        sf::RectangleShape rectangle6;
        rectangle6.setSize(sf::Vector2f(1800, 10));
        rectangle6.setFillColor(sf::Color::White);
        rectangle6.setPosition(0, 100);

        sf::RectangleShape rectangle7;
        rectangle7.setSize(sf::Vector2f(300, 2));
        rectangle7.setFillColor(sf::Color::White);
        rectangle7.setPosition(900, 400);

        sf::RectangleShape rectangle8;
        rectangle8.setSize(sf::Vector2f(300, 2));
        rectangle8.setFillColor(sf::Color::White);
        rectangle8.setPosition(900, 500);

        sf::RectangleShape rectangle9;
        rectangle9.setSize(sf::Vector2f(10, 1500));
        rectangle9.setFillColor(sf::Color::White);
        rectangle9.setPosition(1200, 500);

        sf::RectangleShape rectangle10;
        rectangle10.setSize(sf::Vector2f(10, 402));
        rectangle10.setFillColor(sf::Color::White);
        rectangle10.setPosition(1200, 0);

        borders = {rectangle, rectangle2, rectangle3, rectangle4, rectangle5, rectangle6,
                   rectangle7, rectangle8, rectangle9, rectangle10};
    }


    void Draw_Space(sf::RenderWindow& window) const;

private:
    std::vector<sf::RectangleShape> borders;
};