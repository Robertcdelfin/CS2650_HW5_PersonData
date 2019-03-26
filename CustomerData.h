#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
#include "PersonData.h"
#include <string.h>

class CustomerData : public PersonData 
{
private:
	int customerNumber;
	bool mailingList;
public:
	//Constructors
	CustomerData();
	CustomerData(std::string, std::string, std::string, std::string, std::string, std::string, std::string, int, bool);
	//setters mutator
	void setCustomerNumber(int);
	void setMailingList(bool);
	//getters accessor
	int getCustomerNumber();
	bool getMailingList();
	void displayCustomerDetails();
};
#endif