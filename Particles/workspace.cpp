#include "workspace.h"



void WorkSpace::Draw_Space(sf::RenderWindow& window) const
{
      for(auto &x : borders)
       window.draw(x);
}