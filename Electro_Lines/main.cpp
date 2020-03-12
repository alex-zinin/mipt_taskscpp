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
#include"vectoper.cpp"
#include<memory>
#include"Particle.cpp"
#include"Vect.cpp"

using  namespace std;

int CHARGE_VAL = 1;



double Vect::EPS = 1.0;

int main() {
    sf::RenderWindow window(sf::VideoMode(2000, 2000), "SFML window");

    vector<shared_ptr<Particle>> particles = {make_shared<Particle>(300.0, 400.0, CHARGE_VAL),
                                              make_shared<Particle>(950.0, 700.0, CHARGE_VAL),
                                              make_shared<Particle>(400.0, 100.0, CHARGE_VAL),
                                              make_shared<Particle>(700.0, 250.0, CHARGE_VAL),
                                              make_shared<Particle>(300.0, 450.0, CHARGE_VAL),
                                              make_shared<Particle>(250.0, 400.0, -CHARGE_VAL),
                                              make_shared<Particle>(150.0, 100.0, -CHARGE_VAL),
                                              make_shared<Particle>(750.0, 500.0, -CHARGE_VAL), };


    int i  = 0;
    while (window.isOpen() && i < 10000) {
        sf::Event event;
        window.clear();
        i++;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        for(auto &x: particles)
            x->Draw(window);
        Draw_Force_Lines(particles, window);
        window.display();
    }

    return 0;
}