#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include<cstdlib>
#include <vector>
#include<cstdio>
#include<cmath>
#include<future>
#include<ctime>
#include <iostream>
#include<algorithm>
#include<SFML/Window.hpp>
#include"vectoper.h"
#include<memory>


class Particle{
public:
    Particle(double x, double y, int val);
    void Draw(sf::RenderWindow &window);
    void move(int x, int y);


    double pos_x, pos_y;
    int charge_val;
    sf::CircleShape circle;
    int FORCE_NUM_LINES = 4;

};