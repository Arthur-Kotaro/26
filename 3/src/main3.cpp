#include <iostream>
#include <cmath>
#include "main3.hpp"

#define DEBUG


class Window
{
    static const int screenWidth = 80;
    static const int screenHeight = 50;
    static const int minWindowWidth = 20;
    static const int minWindowHeight = 10;
    int basePointXposition = 0;
    int basePointYposition = 0;
    int windowWidth = screenWidth - 10;
    int windowHeight = screenHeight - 10;
//    int basePointXposition;
//    int basePointYposition;
//    int windowWidth;
//    int windowHeight;
public:
//    Window()
//    {
//        int basePointXposition = 0;
//        int basePointYposition = 0;
//        int windowWidth = screenWidth - 10;
//        int windowHeight = screenHeight - 10;
//    }
    void ShowInfo()
    {
        std::cout<< "basePointXposition = " << basePointXposition <<", basePointYposition = " << basePointYposition << ", windowWidth = " << windowWidth << ", windowHeight = " << windowHeight << std::endl;
    }
    void move()
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

    void resize()
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

    void display()
    {
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
    }
};

int main()
{
    std::string input_str;
    Window* user_window = new Window;
#ifdef DEBUG
    user_window->ShowInfo();
#endif
    do
    {
        std::cout<< "\nEnter command (move/resize/display/close):";
        std::cin>>input_str;
        if (input_str == "move")
        {
            user_window->move();
        }
        else if (input_str == "resize")
        {
            user_window->resize();
        }
        else if (input_str == "display")
        {
            user_window->display();
        }
        else if (input_str == "close")
        {
            std::cout<< "Window closed.\n";
            break;
        }
        else
        {
            std::cout<< "Invalid input. Try again.\n";
            continue;
        }
    } while (true);
	return 0;
}
