//
// Created by alexzinin on 01.05.19.
//
#pragma once



#include<iostream>
#include<vector>
#include<cmath>

using namespace std;



ostream& operator<<(ostream& stream, const vector<double> &vect);
double md(const vector<double> &v);
double operator*(const vector<double> &v1, const vector<double> &v2);
vector<double> operator+(const vector<double> &v1, const vector<double> &v2);
vector<double> operator-(const vector<double> &v1, const vector<double> &v2);
vector<double> operator*(const vector<double> &vect, double d);
vector<double> normalise(const vector<double> &v);
