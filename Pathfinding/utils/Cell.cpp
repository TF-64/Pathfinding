#include "Cell.hpp"



Cell::Cell(int x, int y, int size, State state) {
    this->x = x;
    this->y = y;
    this->size = size;
    this->state = state;
    //square = sf::CircleShape(size, 4);
    //square = sf::RectangleShape(sf::Vector2f(y + size, x + size));
    square = sf::RectangleShape(sf::Vector2f(size, size));
    square.setPosition((float) x, (float) y);
    setState(NONE);
}

void Cell::setState(State state) {
    this->state = state;
    
    switch (state) {
        case START:
            square.setFillColor(sf::Color(100, 250, 50));
            break;
            
        case END:
            square.setFillColor(sf::Color(250, 0, 0));
            break;
            
        case WALL:
            square.setFillColor(sf::Color(250, 250, 250));
            break;
        
        case CHECKED:
            square.setFillColor(sf::Color(0, 0, 255));
            break;
        
        case NONE:
            square.setFillColor(sf::Color(160, 160, 160));
            break;
    }
    
}

State Cell::getState() {
    return state;
    
}

