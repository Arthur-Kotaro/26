#include "window.hpp"


Window::Window(std::string inWindowName = "Default", int inScreenWidth = 80, int inScreenHeight = 50): window_name(inWindowName), screenWidth(inScreenWidth), screenHeight(inScreenHeight)
    {
        basePointXposition = 0;
        basePointYposition = 0;
        windowWidth = inScreenWidth - 10;
        windowHeight = inScreenHeight - 10;
    }
    void Window::ShowInfo()
    {
        std::cout<< '\"' << window_name << "\" window basePointXposition = " << basePointXposition <<", basePointYposition = " << basePointYposition << ", windowWidth = " << windowWidth << ", windowHeight = " << windowHeight << std::endl;
    }
    std::string Window::GetName()
    {
        return window_name;
    }
    void Window::move()
    {
        int offsetX = 0;
        int offsetY = 0;
        std::cout<< "Enter X-axis and Y-axis offset: ";
        std::cin>> offsetX >> offsetY;
        if(offsetX > 0)
        {
            int MaxdeltaX2 = screenWidth - windowWidth - basePointXposition;
            if (MaxdeltaX2 >= offsetX) basePointXposition += offsetX;
            else basePointXposition += MaxdeltaX2;
        }
        else if (offsetX < 0)
        {
            if(basePointXposition >= abs(offsetX)) basePointXposition += offsetX;
            else basePointXposition = 0;
        }

        if(offsetY > 0)
        {
            int MaxdeltaY2 = screenHeight - windowHeight - basePointYposition;
            if (MaxdeltaY2 >= offsetY) basePointYposition += offsetY;
            else basePointYposition += MaxdeltaY2;
        }
        else if (offsetY < 0)
        {
            if(basePointYposition >= abs(offsetY)) basePointYposition += offsetY;
            else basePointYposition = 0;
        }
        std::cout<<"New left upper left corner position: X = " << basePointXposition << ", Y = " << basePointYposition << ".\n";
    }

    void Window::resize()
    {
        int sizeRequestWidth = 0;
        int sizeRequestHeight = 0;
        int MaxNewWidth;
        int MaxNewHeight;
        std::cout<< "Enter new width and height: ";
        std::cin>> sizeRequestWidth >> sizeRequestHeight;
        if(sizeRequestWidth <= minWindowWidth) windowWidth = minWindowWidth;
        else
        {
            MaxNewWidth = screenWidth - basePointXposition;
            if (sizeRequestWidth <= MaxNewWidth) windowWidth = sizeRequestWidth;
            else windowWidth = MaxNewWidth;
        }


        if(sizeRequestHeight <= minWindowHeight) windowHeight = minWindowHeight;
        else
        {
            MaxNewHeight = screenHeight - basePointYposition;
            if (sizeRequestHeight <= MaxNewHeight) windowHeight = sizeRequestHeight;
            else windowHeight = MaxNewHeight;
        }
        std::cout<<"New window width = " << windowWidth << ", height = " << windowHeight << ".\n";
    }

void Window::display()
    {
        std::cout << std::endl  << std::endl << std::endl;
        for (int i = 0; i < basePointYposition; ++i) {
            for (int j = 0; j < screenWidth; ++j) {
                std::cout<<'0';
            }
            std::cout<<'\n';
        }
        for (int i = 0; i < windowHeight; ++i) {
            for (int j = 0; j < basePointXposition; ++j) {
                std::cout<<'0';
            }
            for (int j = 0; j < windowWidth; ++j) {
                std::cout<<'1';
            }
            for (int j = 0; j < screenWidth - (basePointXposition + windowWidth); ++j) {
                std::cout<<'0';
            }
            std::cout<<'\n';
        }
        for (int i = basePointYposition + windowHeight; i < screenHeight; ++i) {
            for (int j = 0; j < screenWidth; ++j) {
                std::cout<<'0';
            }
            std::cout<<'\n';
        }
        std::cout << std::endl  << std::endl << std::endl;
    }