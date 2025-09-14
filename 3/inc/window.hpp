#pragma once

#include <iostream>
#include <cmath>

#define SCREEN_SIZE_IN_ARGS

class Window
{
#ifndef SCREEN_SIZE_IN_ARGS
    int screenWidth;
    int screenHeight;
#endif

#ifdef SCREEN_SIZE_IN_ARGS
    friend class Screen;
#endif

    std::string window_name;
    static const int minWindowWidth = 20;
    static const int minWindowHeight = 10;
    int basePointXposition;
    int basePointYposition;
    int windowWidth;
    int windowHeight;
public:
#ifndef SCREEN_SIZE_IN_ARGS
    Window(const std::string &inWindowName, int inScreenWidth, int inScreenHeight);
#endif
#ifdef SCREEN_SIZE_IN_ARGS
    Window(const std::string &inWindowName);
#endif

    std::string GetName();
    void ShowInfo();
#ifndef SCREEN_SIZE_IN_ARGS
    void move();
    void resize();
    void display();
#endif

#ifdef SCREEN_SIZE_IN_ARGS
private:
    void move(int screenWidth, int screenHeight);
    void resize(int screenWidth, int screenHeight);
    void display(int screenWidth, int screenHeight);
#endif
};