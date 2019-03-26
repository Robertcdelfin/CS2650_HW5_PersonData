#include "CustomerData.h"
#include <string.h>
#include <iostream>

//function prototype for checking
bool isThere(int);
//limit size on how many people can be in list.
const int customerLimit = 10;
CustomerData customers[customerLimit];
int count = 0;

//checks if the customer number exists already
bool isThere(int arrayNumber) 
{
	for (int i = 0; i < count; i++) 
	{
		if (customers[i].getCustomerNumber() == arrayNumber)
		{
			//customer was found
			return true;
		}
	}
	return false;
}
//main functions that calls all other files and classes.
int main() 
{
	std::string lastName;
	std::string firstName;
	std::string address;
	std::string city;
	std::string state;
	//for mailing list
	std::string addToMailing;
	std::string zip;
	std::string phone;
	int customerNumber;
	bool mailingList;
	char userChoice;

	do 
	{
		std::cout << "Enter Customer Number: ";
		std::cin >> customerNumber;
		//check if the number is in array
		if (!isThere(customerNumber)) 
		{
			//gets the first name
			std::cout << "Enter first name: ";
			std::cin >> firstName;
			std::cout << std::endl;
			//gets the last name
			std::cout << "Enter last name: ";
			std::cin >> lastName;
			std::cout << std::endl;
			//gets the address
			std::cout << "Enter address: ";
			std::cin >> address;
			std::cout << std::endl;
			//gets the city
			std::cout << "Enter city: ";
			std::cin >> city;
			std::cout << std::endl;
			//gets the state
			std::cout << "Enter state: ";
			std::cin >> state;
			std::cout << std::endl;
			//gets the zip
			std::cout << "Enter zip code: ";
			std::cin >> zip;
			std::cout << std::endl;
			//gets the phone number 
			std::cout << "Enter phone number: ";
			std::cin >> phone;
			std::cout << std::endl;
			//asks if they want to be on on the mailing list
			std::cout << "Do you want to be on the mailing list (yes/no): ";
			std::cin >> addToMailing;
			std::cout << std::endl;
			if (addToMailing == "yes") 
			{
				mailingList = true;
			}
			else 
			{
				mailingList = false;
			}
			CustomerData customer(firstName, lastName, address, state, city, zip, phone, customerNumber, mailingList);
			customers[count] = customer;
			count++;
		}
		else 
		{
			//error person is already in the list
			std::cout << "The customer is already in the list." << std::endl;
		}
		std::cout << "Enter another customer? (Y/N):";
		std::cin >> userChoice;
		std::cout << std::endl;
	} while ((userChoice == 'y' || userChoice == 'Y') && count < customerLimit);
	std::cout << "Information on all customers" << std::endl;
	
	//displays every customer created
	for (int i = 0; i < count; i++) 
	{
		customers[i].displayCustomerDetails();
	}
	return 0;
}