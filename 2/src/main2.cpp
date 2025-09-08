#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
//#include <cassert>
#include "main2.hpp"


bool CheckNumber(std::string &number)
{
	if(number.length() != 10) return false;
	for(int iter = 0; iter < 10; iter++)
	{
		if(number[iter] < '0'|| number[iter] > '9') return false;
	}
	return true;
}



class Contact
{
	std::string name;
	const std::string prefix = "+7";
	std::string number;

public:
		Contact()
	{
		std::cout<< "Enter name of the contact: ";
		std::cin.ignore();
		std::getline(std::cin, name);
		do
		{	
			std::cin.ignore();
			std::cout<< "Enter phone number: " << prefix;
			std::getline(std::cin, number);
		} while(!CheckNumber(number));	
	}


	std::string GetNumber(std::string &contact_name)
	{
		if(contact_name == name) return number;
		else return std::string();
	}
	friend bool CheckNumber(std::string &number); 
};




class Phone
{
	std::vector <Contact*> contactList;

public:
	Phone()
	{


	}
	void add()
	{

	}
	std::string	findContact(std::string &contactName)
	{
		std::string contactNumber;
		for(int i = 0; i < contactList.size(); i++)
		{
			contactNumber = contactList[i]->GetNumber(contactName);
			if(contactNumber.length() == 10) return contactNumber;
		}
		return contactNumber;
	}
	void call()
	{
		std::string answ;
		do
		{
			std::cout<< "Enter \"name\" or \"num\": ";
			std::cin>> answ;
			if(answ == "name")
			{
				std::cin.ignore();
				std::cout<< "Enter contact name: ";
				std::getline(std::cin, answ);
				answ = findContact(answ);
				if(answ.length() != 10)
				{
					std::cout << "No such contact in the list.\n";
					return;
				}
			}
			else if(answ == "num")
			{
				std::cin.ignore();
				std::cout<< "Enter phone number: ";
				std::getline(std::cin, answ);
				if(CheckNumber(answ))
					std::cout<< "Calling to +7" << answ << ".\n";
				else
				{
					std::cout<< "Incorrect number. Try again.\n";
					return;
				}
			}
			else
			{
				std::cout<< "Incorrect input. Try again.\n";
			}
		} while(true);	
	}
	void sms()
	{

	}
};

int main()
{
    std::string input_str;
    Phone * user_phone = new Phone;
    do
    {
        std::cout<< "\nEnter command (add/call/sms/exit): ";
        std::cin>>input_str;
        if (input_str == "add")
        {
            user_phone->add();
        }
        else if (input_str == "call")
        {
            user_phone->call();
        }
        else if (input_str == "sms")
        {
            user_phone->sms();
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
