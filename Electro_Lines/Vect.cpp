#include"Vect.h"



Vect::Vect(double x0, double y0, const vector<double> &direction){
    std::vector<double> dir = normalise(direction)*EPS;
    xb = x0;
    yb = y0;
    xe  = xb + dir[0];
    ye = yb + dir[1];
    line[0] = sf::Vertex(sf::Vector2f(x0, y0));
    line[1] = sf::Vertex(sf::Vector2f(xe, ye));
}

void Vect::Draw(sf::RenderWindow &window){
    window.draw(line, 2, sf::Lines);
}

vector<double> Compute_Force(double x, double y, const vector<shared_ptr<Particle>> &particles)
{
    vector<double> res_direction(2);
    for(const auto &a: particles){
        {
            vector<double> r1 = {(x - a->pos_x), (y - a->pos_y)};
            double md_r1 = md(r1);
            if(a->charge_val > 0)
                res_direction = res_direction + r1*((a->charge_val)/(md_r1*md_r1*md_r1));
            else
                res_direction = res_direction - r1*((-a->charge_val)/(md_r1*md_r1*md_r1));

        }
    }
    return res_direction;
}

void Draw_Force_Lines(const vector<shared_ptr<Particle>> &particles, sf::RenderWindow &window)
{
    for(const auto &p: particles){
        double x0 = p->pos_x;
        double y0 = p->pos_y;
        Vect dir[8] = {Vect(x0, y0, {-1, 0}),
                       Vect(x0, y0, {1, 0}),
                       Vect(x0, y0, {0, 1}),
                       Vect(x0, y0, {0, -1}),
                       Vect(x0, y0, {-0.5, -0.5}),
                       Vect(x0, y0, {0.5, 0.5}),
                       Vect(x0, y0, {-0.5, 0.5}),
                       Vect(x0, y0, {0.5, -0.5})};
        for(int i = 0; i < 8; i++)
        {
            dir[i].Draw(window);
            x0 = (dir[i]).xe;
            y0 = (dir[i]).ye;
            while(x0 > 0 && y0 > 0 && x0 < 2000 && y0 < 2000 && md(Compute_Force(x0 + 0.1, y0 + 0.1, particles)) < 2.59){
                dir[i] = Vect(x0, y0, Compute_Force(x0 + 0.1, y0 + 0.1, particles));
                (dir[i]).Draw(window);
                x0 = (dir[i]).xe;
                y0 = (dir[i]).ye;
            }
        }



    }
}