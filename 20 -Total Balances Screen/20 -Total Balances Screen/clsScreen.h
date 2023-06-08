#pragma once
#include <iostream>
#include "clsBankClient.h"

using namespace std;

class clsScreen
{
    static string _Space(short NumOfSpace)
    {
        string Space = "";
        for (short i = 0; i < NumOfSpace; i++)
        {
            Space += " ";
        }
        return Space;
    }
protected:
    

	static void _DrawHeder(string Title, string subTitle = "")
	{
        short CountSpace = (36 - Title.size()) / 2;
		cout << "===================================\n";
		cout << _Space(CountSpace) << Title << endl;

		if (subTitle != "")		
			cout << "\t\t\t" << subTitle << endl;
		
		cout << "===================================\n";
	}

    static void _Print(clsBankClient Client)
    {
        cout << "\nClient Card\n";
        cout << "__________________________________\n";
        cout << "First Name      : " << Client.FirstName << endl;
        cout << "Last Name       : " << Client.LastName << endl;
        cout << "Email           : " << Client.Email << endl;
        cout << "Phone           : " << Client.Phone << endl;
        cout << "Account Number  : " << Client.AccountNumber() << endl;
        cout << "Pin Code        : " << Client.PinCode << endl;
        cout << "Account Balance : " << to_string(Client.AccountBalance) << endl;
        cout << "__________________________________\n";
    }

    static void _ReadAddClientInfo(clsBankClient& Client)
    {
        Client.FirstName = clsInputValidation::ReadString("Plaese enter first Name : ");

        Client.LastName = clsInputValidation::ReadString("Plaese enter last name : ");

        Client.Email = clsInputValidation::ReadString("Plaese enter email : ");

        Client.Phone = clsInputValidation::ReadString("Plaese enter phone : ");

        Client.PinCode = clsInputValidation::ReadString("Plaese enter pin code : ");

        Client.AccountBalance = clsInputValidation::ReadDoubleNumber("Plaese enter balance : ");
    }
};

