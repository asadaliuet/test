#pragma once

#include "Libraries.h"

class Add_on
{
    public:

        static void Invalid()
        {
            cout << "\n! ! ! Invalid Input ! ! !\n";
        }

        static void Margin()
        {
            cout << "\n---------------------------------------------------------------\n";
        }

        static void Network_Connection_Status(char Status)
        {
            if(Status == '1')
            {
                cout << "\nNetwork connection has been established.\n";
            }
            else if(Status == '2')
            {
                cout << "\nFailed to establish a network conection.\n";
            }
        }
};