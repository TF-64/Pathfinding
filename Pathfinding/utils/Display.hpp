#ifndef Display_hpp
#define Display_hpp


#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>


#include "Map.hpp"
#include "Button.hpp"

class Display {
    Map* map;
    sf::RenderWindow* window;
    std::vector<Button> buttons;
    
public:
    Display(sf::RenderWindow &window, Map &map);
    
    void addButton(Button button) {buttons.push_back(button);}
    
    
    void draw();
    
    
    
    
};


#endif
