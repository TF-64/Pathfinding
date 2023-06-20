
#ifndef Algorithm_hpp
#define Algorithm_hpp

#include "Display.hpp"
#include "Map.hpp"

class Algorithm {
    Map* map;
    Display* display;
    
    
public:
    
    Algorithm(Map &map, Display &display);
    
    void AStar();
    
};



#endif
