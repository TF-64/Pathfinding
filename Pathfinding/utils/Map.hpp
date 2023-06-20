#ifndef Map_hpp
#define Map_hpp


#include <SFML/Graphics.hpp>
#include "Cell.hpp"

class Map {
    
    int height, width, cellsize;
    std::vector<std::vector<Cell>> field;
    sf::RenderWindow* window;
    
    Cell* start_cell;
    Cell* end_cell;
    

public:
    
    Map(int width, int height, int cellsize, sf::RenderWindow &window);
    
    void draw();
    
    void setCellStateAt(int x, int y, State state);
    State getCellStateAt(int x, int y);
    
    int getHeight() {return height;}
    int getWidth() {return width;}
    
    Cell* getStartCell() {return start_cell;}
    Cell* getEndCell() {return end_cell;}
    
    
};

#endif
