//
// Created by alexzinin on 01.05.19.
//
#pragma once


#include<iostream>
#include<vector>
#include<cmath>

using namespace std;



ostream& operator<<(ostream& stream, vector<float> vect);
float md(vector<float> v);
float operator*(vector<float> v1, vector<float> v2);
vector<float> operator+(vector<float> v1, vector<float> v2);
vector<float> operator-(vector<float> v1, vector<float> v2);
vector<float> operator*(const vector<float> &vect, float d);