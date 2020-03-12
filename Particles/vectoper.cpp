#include "vectoper.h"
#include <cmath>

ostream& operator<<(ostream& stream, vector<float> vect)
{
    stream << "{";
    for(int i = 0; i < vect.size(); i++)
    {
        stream << vect[i] << " ";
    }
    stream << "}";
}

float md(vector<float> v)
{
    float m = 0;
    for(int i = 0; i < v.size(); i++)
    {
        m = m+v[i]*v[i];
    }
    return sqrt(m);
}

float operator*(vector<float> v1, vector<float> v2)
{
    float sc = 0;
    for(int i = 0; i < v1.size(); i++)
    {
        sc = sc + v1[i]*v2[i];
    }
    return sc;
}

vector<float> operator+(vector<float> v1, vector<float> v2)
{
    vector<float> vec = v1;
    for(int i = 0; i < v1.size(); i++)
    {
        vec[i] = v1[i]+v2[i];
    }
    return vec;
}

vector<float> operator-(vector<float> v1, vector<float> v2)
{
    vector<float> vec = v1;
    for(int i = 0; i < v1.size(); i++)
    {
        vec[i] = v1[i]-v2[i];
    }
    return vec;
}


vector<float> operator*(const vector<float> &vect, float d)
{
    vector<float> v = vect;
    for(int i = 0; i < vect.size(); i++)
    {
        v[i] = vect[i]*d;
    }

    return v;

}