#include"molecule.h"
#include<math.h>





Obj::Obj(): x(0), y(0), shape(8.f)
{

    index = NUM_OF_PARTICLES;
    NUM_OF_PARTICLES++;

    if(index < number/2)
    {
        x = (rand()%1000);
        y = (rand()%1000);
        shape.setPosition(x, y);
        if(x > 900)
            x = x -350;
        if(y > 900)
            y = y -250;
        if(y < 100)
            y = y + 200;
        if(x < 300)
            x = x + 200;
    }
    else
    {
        if(index < number*0.9)
        {
            x = (rand()%1000) + 1200;
            y = (rand()%1000);
            shape.setPosition(x, y);
            if(x > 900+1200)
                x = x -350;
            if(y > 900)
                y = y -250;
            if(y < 100)
                y = y + 200;
            if(x < 100)
                x = x + 200;
        }

    }


    int z;
    if(index % 2 == 0)
        z = 1;
    else
        z = -1;
    speed = {(float)(-z*((rand()%1000)%100%10-5))/3 ,(float) (z*((rand()%1000)%100%10-5))/3};


}


void Obj::SetStartPosition()
{
    x = (rand()%1000) + 1200;
    y = (rand()%1000);
    shape.setPosition(x, y);
    if(x > 900+1200)
        x = x -350;
    if(y > 900)
        y = y -250;
    if(y < 100)
        y = y + 200;
    if(x < 100)
        x = x + 200;

    int z;
    if(index % 2 == 0)
        z = 1;
    else
        z = -1;
    speed = {(float)(-z*((rand()%1000)%100%10-5)) ,(float) (z*((rand()%1000)%100%10-5))};
}






Obj::Obj(float cr1, float cr2, vector<float> sp): x(cr1), y(cr2), speed(sp), shape(8.f)
{
    shape.setFillColor(sf::Color::Yellow);
    this->shape.setPosition(cr1, cr2);
    this->speed = sp;
}

void Obj::move()
{
    shape.setPosition(x+speed[0], y+speed[1]);
    x = x + speed[0];
    y = y + speed[1];

    if(y > 900)
        speed[1] = -abs(speed[1]);
    if(y < 100)
        speed[1] = abs(speed[1]);
    if(x > 900 && ((y < 405) || (y > 505)) && x < 905)
        speed[0] = -abs(speed[0]);
    if(x > 1800)
        speed[0] = -abs(speed[0]);
    if(x < 300)
        speed[0] = abs(speed[0]);
    if(((x > 905) && (x < 1195)) && y < 400)
        speed[1] = abs(speed[1]);
    if(((x > 905) && (x < 1195)) && y > 500)
        speed[1] = -abs(speed[1]);
    if(x > 1195 && x < 1200 && ((y < 405) || (y > 505)))
        speed[0] = abs(speed[0]);

}

void Obj::movelit()
{
    //window.draw(this->shape);
    shape.setPosition(x+speed[0]/2, y+speed[1]/2);
    x = x + speed[0]/2;
    y = y + speed[1]/2;
    //pos[num] = {x,y};

    if(y > 900)
        speed[1] = -speed[1];
    if(y < 0)
        speed[1] = -speed[1];
    if(x > 900)
        speed[0] = -speed[0];
    if(x < 100)
        speed[0] = -speed[0];
}

void bump(Obj& ob1, Obj& ob2)//, int pos1, int pos2)
{
    vector<float> dir = {ob1.x-ob2.x, ob1.y-ob2.y};
    float cos1, cos2;
    vector<float> pr1  = dir*((dir*ob1.speed)/(md(dir)*md(dir)));
    vector<float> pr2 = dir*((dir*ob2.speed)/(md(dir)*md(dir)));
    ob1.speed = ob1.speed - pr1 + pr2;
    ob2.speed = ob2.speed - pr2 + pr1;
    float s = sqrt((ob1.x-ob2.x)*(ob1.x-ob2.x)+(ob1.y-ob2.y)*(ob1.y-ob2.y));
    float delta = 2*radius - s;
    vector<float> vect = {ob1.x-ob2.x, ob1.y-ob2.y};
    float modul = md(vect);
    float k = delta/modul;
    ob1.x = ob1.x + 1.5*(vect*k)[0];
    ob1.y = ob1.y + 1.5*(vect*k)[1];
    (ob1.shape).setPosition(ob1.x, ob1.y);
}




void movement(std::vector<Obj> &mass)
{
    const int size = mass.size();
    pair<int, int> cor[size];
    for(int i = 0; i < size; i++)
    {
        float x = mass[i].x;
        float y = mass[i].y;
        cor[i] = make_pair(x,y);
    }

    for(int i = 0; i < size; i++)
    {
        mass[i].move();
    }

    for(int i = 0; i < size*0.9; i++)
    {
        for(int j = 0; j < size*0.9; j++)
        {
            float s = 9999;
            if(i != j)
                s = sqrt((cor[i].first-cor[j].first)*(cor[i].first-cor[j].first)+(cor[i].second-cor[j].second)*(cor[i].second-cor[j].second));
            if(s <= 2*radius && i != j)
            {
                if(s == 0)
                    return;
                if(i != j)
                {
                    bump(mass[i], mass[j]);
                    cor[i] = {4999+i*200,4999*i*300};
                    cor[j] = {4999+j*200,4999+j*300};
                }
            }
        }
    }

    for(int i = 0; i < size; i++)
    {
        mass[i].move();
    }

}