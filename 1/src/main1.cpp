#include <iostream>
#include <string>
#include <ctime>
#include "main1.hpp"

class Track
{
    std::string name;
    std::tm creation_date;
    unsigned int length;
public:
    void showInfo()
    {

    }
};

class Player
{
    public:
    void play()
    {

    }
    void pause()
    {

    }
    void next()
    {

    }
    void stop()
    {

    }
};

int main()
{
    std::string input_str;
    Player * user_player = new Player;
    do
    {
        std::cout<< "Enter command (play/pause/next/stop/exit): ";
        std::cin>>input_str;
        if (input_str == "play")
        {
            user_player->play();
        }
        else if (input_str == "pause")
        {
            user_player->pause();
        }
        else if (input_str == "next")
        {
            user_player->next();
        }
        else if (input_str == "stop")
        {
            user_player->next();
        }
        else if (input_str == "exit")
        {
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
