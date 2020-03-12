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
#include"Particle.h"


class Vect{
public:
    Vect(double x0, double y0, const vector<double> &direction);
    void Draw(sf::RenderWindow &window);


    static double EPS;
    double xb, yb;
    double xe, ye;
    sf::Vertex line[2];

};

vector<double> Compute_Force(double x, double y, const vector<shared_ptr<Particle>> &particles);
void Draw_Force_Lines(const vector<shared_ptr<Particle>> &particles, sf::RenderWindow &window);