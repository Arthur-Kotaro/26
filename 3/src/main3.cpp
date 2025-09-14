#include <iostream>
#include <map>
#include <cstdio>
#include <string>
#include "window.hpp"
#include "main3.hpp"


//#define DEBUG


class Screen
{
    int screenWidth = 80;
    int screenHeight = 50;
    unsigned int windowsCount = 0;
    int currentWindowNum = 0;
    Window* currentWindowPtr = nullptr;
    std::map<int, Window*> window_list;
//    std::vector <Window*> window_list;

public:
    Window* GetCurrent()
    {
        return currentWindowPtr;
    }
    void addScreen(std::string inName = "Title")
    {
        bool checkInsertation;
        checkInsertation = (window_list.insert(std::make_pair<int, Window*>(windowsCount+1, new Window(inName, screenWidth, screenHeight))).second);
        if(checkInsertation) windowsCount++;
        if (window_list.size() == 1)
        {
            currentWindowPtr = window_list.begin()->second;
            currentWindowNum = window_list.begin()->first;
        }
    }
    int closeScreen()
    {
        int windowsLeft;
        std::string delName = currentWindowPtr->GetName();
        int delNum = currentWindowNum;
        delete currentWindowPtr;
        window_list.erase(currentWindowNum);
        std::cout << "Window " << delNum << ". " << delName << " closed.\n";
        windowsLeft = window_list.size();
        if ( windowsLeft != 0)
        {
            currentWindowNum = window_list.begin()->first;
            currentWindowPtr = window_list.find(currentWindowNum)->second;
#ifdef DEBUG
            std::cout << "Debug:  currentWindowNum = " <<  currentWindowNum << ",  " << window_list.find(currentWindowNum)->second->GetName() << ".\n";
#endif
        }
        return windowsLeft;
    }
    void ShowList()
    {
        std::cout << std::endl << "\tN windows names" << std::endl << std::endl;
        for (std::map<int, Window*>::iterator itr = window_list.begin(); itr != window_list.end() ; ++itr)
        {
            std::cout << ((itr->second == currentWindowPtr)? ">>>\t" : "\t");
            std::cout << itr->first << ". " << itr->second->GetName() << std::endl;
        }
        std::cout << std::endl;
    }
    void ChangeActive()
    {
        int winNumber;
        do {
            std::cout << "Choose number of window to set active: ";
            std::cin >> winNumber;
            if (winNumber < 1)
            {
                std::cout<< "Incorrect input. Try again.\n";
                continue;
            }
            if(window_list.contains(winNumber))
            {
                currentWindowPtr = window_list.find(winNumber)->second;
                currentWindowNum = window_list.find(winNumber)->first;
#ifdef DEBUG
                std::cout<< "Active window is: " << currentWindowNum << ". " << currentWindowPtr->GetName() << std::endl;
#endif
                break;
            } else std::cout << std::endl << "No window with number " << winNumber << std::endl;
        } while(true);
    }
};

int main()
{
    char input_symbol;
    Screen* user_screen = new Screen;
    user_screen->addScreen("Welcome window");

#ifdef DEBUG
//    user_window->ShowInfo();
#endif
    do
    {
        std::cout<< "Enter command: a(add) / l(show list) / c(change active) / m(move) / r(resize) / d(display) / X(close active):";
        std::cin>>input_symbol;
//        input_symbol = getchar();
        std::cin.ignore();
        if (input_symbol == 'a')
        {
            user_screen->addScreen();
        }
        if (input_symbol == 'l')
        {
            user_screen->ShowList();
        }
        if (input_symbol == 'c')
        {
            user_screen->ChangeActive();
        }
        if (input_symbol == 'm')
        {
            user_screen->GetCurrent()->move();
        }
        else if (input_symbol == 'r')
        {
            user_screen->GetCurrent()->resize();
        }
        else if (input_symbol == 'd')
        {
            user_screen->GetCurrent()->display();
        }
        else if (input_symbol == 'X')
        {
            if(!user_screen->closeScreen()) break;
        }
//        else
//        {
//            std::cout<< "Invalid input. Try again.\n";
//            continue;
//        }
    } while (true);
    delete user_screen;
    user_screen = nullptr;
	return 0;
}
