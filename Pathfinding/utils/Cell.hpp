#ifndef Cell_hpp
#define Cell_hpp


#include <SFML/Graphics/RectangleShape.hpp>

enum State {
  START, END, WALL, CHECKED, NONE
    
};


class Cell {
    State state;
    int x, y, size;
    sf::RectangleShape square;
    
public:
    
    Cell(int x, int y, int size, State state);
    
    void setState(State state);
    State getState();
    
    int getX() {return x;}
    int getY() {return y;}
    
    sf::RectangleShape getShape() {return square;}
    
    
    
    
    
};


#endif
