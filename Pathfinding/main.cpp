
#include <chrono>
#include <ctime>
#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Display.hpp"
#include "Algorithm.hpp"

#define HEIGHT 2000
#define WIDTH 1600
#define SIZE 30
#define FPS 60
#define WINDOW_HEIGHT 1800
#define WINDOW_WIDTH 2400
#define CLICK_DURATION 0.3




int main() {
    
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pathfinding");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(FPS);
    
    Map map(WIDTH/SIZE, HEIGHT/SIZE, SIZE, window);
    Button start_button(180, 30, WINDOW_WIDTH-30, WINDOW_HEIGHT-30, 14, "Start", "Stop", window);
    
    Display display(window, map);
    display.addButton(start_button);
    
    Algorithm algorithm(map, display);
    
    auto lastpress = std::chrono::system_clock::now();
    
    bool start_set = false, end_set = false;
    int last_x = -1, last_y = -1;
    
    
    
    
    
    while (window.isOpen()) {
        sf::Event event;
        
//===========================================DRAWING PREDICTING LOGIC===========================================
        
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            
            if(pos.x >= 0 && pos.y >= 0 && pos.x < WIDTH && pos.y < HEIGHT) {
                
                int x = pos.x/SIZE;
                int y = pos.y/SIZE;
                
                if(!start_set) {
                    map.setCellStateAt(x, y, START);
                    start_set = true;
                    continue;
                }
                
                else if(!end_set && map.getCellStateAt(x, y) != START) {
                    
                    map.setCellStateAt(x, y, END);
                    end_set = true;
                    continue;
                }

                else if (map.getCellStateAt(x, y) != START && map.getCellStateAt(x, y) != END) {
                    map.setCellStateAt(x, y, WALL);
                    auto press = std::chrono::system_clock::now();
                    std::chrono::duration<double> delta = press-lastpress;
                    
                    if(delta.count() <= (double) 2/FPS) {
                        
                        if(last_x == -1 || last_y == -1) {
                            last_x = x;
                            last_y = y;
                            continue;
                        }
                        
                        if(last_x == x && last_y == y)
                            continue;
                        
                        else if(last_x == x) {
                            for(int i = (last_y > y? y : last_y); i <= (last_y > y? last_y : y); i++)
                                if(map.getCellStateAt(x, i) != START && map.getCellStateAt(x, i) != END)
                                    map.setCellStateAt(x, i, WALL);
                        
                        }
                        
                        else if(last_y == y) {
                            for(int i = (x > last_x? last_x : x); i <= (x > last_x? x : last_x); i++)
                                if(map.getCellStateAt(i, y) != START && map.getCellStateAt(i, y) != END)
                                    map.setCellStateAt(i, y, WALL);
                        }
                        
                        else {
                            float k = (last_y - y) / (last_x - x);
                            int b = last_y - k * last_x;
                            
                            for(int i = (x > last_x? last_x : x); i <= (x > last_x? x : last_x); i++) {
                                int j = k * i + b;
                                if(map.getCellStateAt(i, j) != START && map.getCellStateAt(i, j) != END)
                                    map.setCellStateAt(i, j, WALL);
                            }
                        }
                        
                        
                    }
                    
                    last_x = x;
                    last_y = y;
                    
                    lastpress = std::chrono::system_clock::now();
                    
                }
            }
        }

        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
                
//===========================================ALGORITHM START LOGIC===========================================
// (press S to start)
                
             
                if(start_set && end_set) {
                    algorithm.AStar();
                    
                }
                
            
            }
        }
        
        
        
        display.draw();
    
        
        
    }
    
}
