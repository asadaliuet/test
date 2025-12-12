#pragma once

#include "Libraries.h"

class Menus
{   
    public:

        static void Main_Menu()
        {
            cout << "\nWhat do you wanna do?\n";
            cout << "1. Setup Auto-Push\n";
            cout << "2. Setup Github\n";
            cout << "3. Settings\n";
            cout << "4. Exit\n\n";
            cout << "Enter your choice: ";
        }

        static void Push_And_Pull_Menu()
        {
            cout << "\nWhat do you wanna do?\n";
            cout << "1. Set Time Duration\n";
            cout << "2. Go Back\n\n";
            cout << "Enter your choice: ";
        }

        static void Display_Status(int Status)
        {
            if(Status)
            {
                cout << "True";
            }
            else
            {
                cout << "False";
            }
        }

        static void View_Settings(vector<int> Setting)
        {
            cout << "Current Settings:\n\n";
            cout << "Auto Push Delay: " << Setting[0];
            cout << "Instant Pull Enabled: "; Display_Status(Setting[1]);
        }

        static void Time_Duration(string Type)
        {
            cout << "Enter Delay Duration for " + Type + " : ";
        }
};