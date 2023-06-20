
#include "Button.hpp"

Button::Button(int size_x, int size_y, int pos_x, int pos_y, int font_size, std::string str1, std::string str2, sf::RenderWindow &window) {
    shape = sf::RectangleShape(sf::Vector2f(size_x, size_y));
    shape.setPosition(pos_x, pos_y);
    shape.setFillColor(color_off);
    
    text.setString(str1);
    text.setPosition(pos_x, pos_y);
    text.setCharacterSize(font_size);
    text.setFillColor(sf::Color(250, 250, 250));
    
    this->window = &window;
    this->str_off = str1;
    this->str_on = str2;
    
    current = &str1;
    
}

void Button::draw() {
    
    //window->clear();
    
    window->draw(text);
    window->draw(shape);
    
    //window->display();
}

void Button::toggle() {
    is_toggled = !is_toggled;
    
    if(current == &str_off) {
        current = &str_on;
        shape.setFillColor(color_on);
    }
    else {
        current = &str_off;
        shape.setFillColor(color_off);
    }
        
    
    text.setString(*current);
}


