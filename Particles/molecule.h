#pragma once
#ifndef SFML_MOLECULE_H
#define SFML_MOLECULE_H

#endif //SFML_MOLECULE_H
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include"vectoper.h"
#include<SFML/Graphics.hpp>
#include<future>

using namespace std;


//vector<pair<float, float>> pos = {};

//vector<void*> mas;


static const float radius = 8;

class Obj
{
public:
    Obj();

    Obj(float cr1, float cr2, vector<float> sp);
    void SetStartPosition();
    void move();
    void movelit();
    vector<float> speed;
    float x, y;
    sf::CircleShape shape;
    int index;
    static size_t number;

    // static const int MAX_NUM_OF_PARTICLES;
    static int NUM_OF_PARTICLES;
};


int Obj::NUM_OF_PARTICLES = 0;
void bump(Obj& ob1, Obj& ob2);
void movement(std::vector<Obj>& mass);