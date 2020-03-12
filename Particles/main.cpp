#include <SFML/Graphics.hpp>
#include<cstdlib>
#include <vector>
#include<cstdio>
#include<cmath>
#include<future>

#include<ctime>
#include <iostream>
#include<algorithm>
#include "vectoper.cpp"
#include"molecule.cpp"
#include<SFML/Window.hpp>
#include"workspace.cpp"

size_t Obj::number = 100;

// Makefile
int main()
{
    FILE *gp = popen("gnuplot", "w");
    FILE* fp = fopen("file.txt", "w");

    WorkSpace workspace;
    sf::RenderWindow window(sf::VideoMode(2000, 2000), "heyyyyyy works!");

    size_t size = Obj::number;
    //Obj::MAX_NUM_OF_PARTICLES = number;
    // Obj::NUM_OF_PARTICLES = 0;

    vector<Obj> k(Obj::number);
    vector<Obj> he(Obj::number);
    for(auto &x : he)
        x.shape.setFillColor(sf::Color::Red);


    FILE* fp3 = fopen("filek.txt", "w");
    int num1 = 0, num2 = 0;
    vector<double> speeds;
    srand(time(NULL));


    for(int i = 0; i < size*0.1; i++)
    {
       he[i].SetStartPosition();
    }


    int sch = 0;
    vector<float> data;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        sch = sch + 1;

        if(sch%1000 == 0)
        {
            speeds.clear();
            for(int i = 0; i < Obj::number; i++)
            {
                speeds.push_back(10*md((k[i]).speed));

            }
            pclose(gp);
        }

            //future<void> f1 = async(movement(vector(k.begin(), k.begin()+(int)k.size()/4;)))
            movement(k);
            movement(he);
             num1 = 0;
             num2 = 0;
             for(int i = 0; i < k.size()*0.9; i++)
             {
                 window.draw((k[i]).shape);
             }


        for(int i = 0; i < size*0.1; i++)
        {
            if(he[i].x > 1200)
                num2 = num2 + 1;
            if(he[i].x < 900)
                num1 = num1 + 1;
            window.draw((he[i]).shape);
        }

        if(sch%100 == 0)
            fprintf(fp3, "%d %d\n", sch/100,(int)((-num1+num2)));

        if(num1 == num2)
        {
            fclose(fp);
            return 0;
        }
        workspace.Draw_Space(window);
        window.display();

        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
          //  circle.setPosition(mousePosition.x, mousePosition.y);
            k.push_back(Obj(mousePosition.x, mousePosition.y, {1,1}));
            //Obj::number++;
        }

        window.clear();
    }

    fclose(fp);
    return 0;
}




