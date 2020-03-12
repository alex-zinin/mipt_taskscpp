#include "vectoper.h"
#include <cmath>

ostream& operator<<(ostream& stream, const vector<double> &vect)
{
    stream << "{";
    for(int i = 0; i < vect.size(); i++)
    {
        stream << vect[i] << " ";
    }
    stream << "}";
}

double md(const vector<double> &v)
{
    double m = 0;
    for(int i = 0; i < v.size(); i++)
    {
        m = m+(v[i])*(v[i]);
    }
    return sqrt(m);
}

double operator*(const vector<double> &v1, const vector<double> &v2)
{
    double sc = 0;
    for(int i = 0; i < v1.size(); i++)
    {
        sc = sc + v1[i]*v2[i];
    }
    return sc;
}

vector<double> operator+(const vector<double> &v1, const vector<double> &v2)
{
    vector<double> vec = v1;
    for(int i = 0; i < v1.size(); i++)
    {
        vec[i] = v1[i]+v2[i];
    }
    return vec;
}

vector<double> operator-(const vector<double> &v1, const vector<double> &v2)
{
    vector<double> vec = v1;
    for(int i = 0; i < v1.size(); i++)
    {
        vec[i] = v1[i]-v2[i];
    }
    return vec;
}


vector<double> operator*(const vector<double> &vect, double d)
{
    //cout <<"fdsgsg";
    vector<double> v = vect;
    for(int i = 0; i < vect.size(); i++)
    {
        v[i] = vect[i]*d;
    }
    //cout <<"fdsgsg";
    return v;

}

vector<double> normalise(const vector<double> &v)
{
    vector<double> res;
    double module = md(v);
    for(auto &x : v)
        res.push_back(x/module);
    return res;
}