



#include "Map.hpp"


Map::Map(int width, int height, int cellsize, sf::RenderWindow &window)
{
    this->height = height;
    this->width = width;
    this->cellsize = cellsize;
    this->window = &window;
    
    for(int i = 0; i < width; i++) {
        std::vector<Cell> line;
        for(int j = 0; j < height; j++)
            line.push_back(Cell(i*cellsize, j*cellsize, cellsize, NONE));
        field.push_back(line);
        
    }
    
    
}

void Map::draw() {
    
    for(int i = 0; i < width; i++)
        for(int j = 0; j < height; j++) {
            
            window->draw(field[i][j].getShape());
        }
}

void Map::setCellStateAt(int x, int y, State state) {
    field[x][y].setState(state);
    
    if(state == START)
        start_cell = &field[x][y];
        
    else if(state == END)
        end_cell = &field[x][y];
    
}


State Map::getCellStateAt(int x, int y) {
    return field[x][y].getState();
}

