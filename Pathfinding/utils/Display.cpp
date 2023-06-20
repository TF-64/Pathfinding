

#include "Display.hpp"

Display::Display(sf::RenderWindow &window, Map &map) {
    this->map = &map;
    this->window = &window;
}


void Display::draw() {
    
    window->clear();
    
    map->draw();
    
    for(Button b : buttons)
        b.draw();
    
    
    window->display();
    
    
}
