#include"Particle.h"



Particle::Particle(double x, double y, int val): pos_x(x), pos_y(y), charge_val(val){
    if(charge_val > 0)
        circle.setFillColor(sf::Color::Red);
    else
        circle.setFillColor(sf::Color::White);
    circle.setPosition(pos_x, pos_y);
    circle.setRadius(10);
    float delta_c = -circle.getRadius();
    circle.move(delta_c, delta_c);
}

void Particle::Draw(sf::RenderWindow &window) {
    window.draw(circle);
}

void Particle::move(int x, int y){
    pos_x += x;
    pos_y += y;
    circle.move(x, y);
}

