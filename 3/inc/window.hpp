#pragma once

#include <iostream>
#include <cmath>

class Window
{
    int screenWidth;
    int screenHeight;
    std::string window_name;
    static const int minWindowWidth = 20;
    static const int minWindowHeight = 10;
    int basePointXposition;
    int basePointYposition;
    int windowWidth;
    int windowHeight;
public:
    Window(std::string inWindowName, int inScreenWidth, int inScreenHeight);
    std::string GetName();
    void ShowInfo();
    void move();
    void resize();
    void display();
};