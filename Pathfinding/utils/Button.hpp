#ifndef Button_hpp
#define Button_hpp

#include <string>
#include <SFML/Graphics.hpp>

class Button {
    sf::RectangleShape shape;
    sf::Text text;
    sf::RenderWindow* window;
    
    
    std::string str_off, str_on;
    bool is_toggled = false;
    
    std::string* current;
    sf::Color color_off = sf::Color(0, 250, 0), color_on = sf::Color(250, 0, 0);
    
    
    
    
    
public:
    
    Button(int size_x, int size_y, int pos_x, int pox_y, int font_size, std::string str1, std::string str2, sf::RenderWindow &window);
    
    int getPosX() {return shape.getPosition().x;}
    int getPosY() {return shape.getPosition().y;}
    int getSizeX() {return shape.getSize().x;}
    int getSizeY() {return shape.getSize().y;}
    
    void setOffColor(sf::Color color_off) {this->color_off = color_off;}
    void setOnColor(sf::Color color_on) {this->color_on = color_on;}
    
    void draw();
    void toggle();

    
};



#endif
