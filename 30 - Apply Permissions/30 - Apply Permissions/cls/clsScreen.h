#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsUsers.h"
#include "Global.h"

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

    static string _Letter (short NumOfLetter, string Letter)
    {
        string letter = "";
        for (short i = 0; i < NumOfLetter; i++)
        {
            letter += Letter;
        }
        return letter;
    }
protected:
    
    static string WriteLetters(short NumOfLetter, string Letter)
    {
        return _Letter(NumOfLetter, Letter);
    }

	static void _DrawHeder(string Title, string subTitle = "")
	{
        short CountSpace = (36 - Title.size()) / 2;
		cout << "===================================\n";
		cout << _Space(CountSpace) << Title << endl;

		if (subTitle != "")		
			cout << "\t\t\t" << subTitle << endl;
		
		cout << "===================================\n";
	}

    static void _DrawHeder(short Num, string Title, string Letter = "=", string subTitle = "")
    {
        short CountSpace = (Num - Title.size()) / 2;
        cout << _Letter(Num, Letter) << endl ;
        cout << _Space(CountSpace) << Title << endl;

        if (subTitle != "")
            cout << "\t\t\t" << subTitle << endl;

        cout << _Letter(Num, Letter) << endl;
    }

    static void _PrintClientCard(clsBankClient Client)
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

    static void _ReadUpdateUserInfo(clsUsers& User)
    {
        User.FirstName = clsInputValidation::ReadString("Plaese enter first Name : ");

        User.LastName = clsInputValidation::ReadString("Plaese enter last name : ");

        User.Email = clsInputValidation::ReadString("Plaese enter email : ");

        User.Phone = clsInputValidation::ReadString("Plaese enter phone : ");

        User.Password = clsInputValidation::ReadString("Plaese enter pin code : ");

        User.Permission = _ReadPermission();
    }

    static short _ReadPermission()
    {
        short Permission = 0;
        if (clsInputValidation::ValidationYesNo("Do you want to give full access y/n : "))
            Permission = -1;
        else
        {
            if (clsInputValidation::ValidationYesNo("Client List y/n : "))
                Permission += clsUsers::enPerListClient;

            if (clsInputValidation::ValidationYesNo("Add New Client y/n : "))
                Permission += clsUsers::enPerAddNew;

            if (clsInputValidation::ValidationYesNo("Delete Client y/n : "))
                Permission += clsUsers::enPerDelete;

            if (clsInputValidation::ValidationYesNo("Update Client Info : "))
                Permission += clsUsers::enPerUpdate;

            if (clsInputValidation::ValidationYesNo("Find Client y/n : "))
                Permission += clsUsers::enPerFind;

            if (clsInputValidation::ValidationYesNo("Transactions y/n : "))
                Permission += clsUsers::enPerTransactions;

            if (clsInputValidation::ValidationYesNo("Manage users y/n : "))
                Permission += clsUsers::enPerManage;
        }
        return Permission;
    }

    static void _PrintUserCard(clsUsers User)
    {
        cout << "\nUser Card\n";
        cout << "__________________________________\n";
        cout << "First Name : " << User.FirstName << endl;
        cout << "Last Name  : " << User.LastName << endl;
        cout << "Email      : " << User.Email << endl;
        cout << "Phone      : " << User.Phone << endl;
        cout << "Username   : " << User.Username() << endl;
        cout << "Password   : " << User.Password << endl;
        cout << "Permission : " << to_string((short)User.Permission) << endl;
        cout << "__________________________________\n";
    }

    static bool CheckAccessRights(clsUsers::enPermission Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            _DrawHeder("Access Denied! Contact your admin!");
            return false;
        }
        else
            return true;
    }
};

