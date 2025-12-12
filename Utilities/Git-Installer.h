#pragma once

#include "Libraries.h"

class Git_Installer
{
    public:

        static void Ensure_Git_Installation()
        {
            if(!Check_Git_Installation())
            {
                Install_Git();
            }
        }

        static bool Check_Git_Installation()
        {
            int Result = system("git --version >nul 2>&1");
            return (Result == 0);
        }

        static void Install_Git()
        {
            cout << "\nGit is not installed on your system.\n";
            cout << "Installing Git using winget...\n\n";

            int Result = system("winget install --id Git.Git -e --source winget");

            if(Result == 0)
            {
                cout << "\nGit has been successfully installed.\nPlease restart the program to continue.\n";
                system("pause");
                exit(0);
            }
            else
            {
                cout << "\nFailed to install Git. Please install it manually from https://git-scm.com\n";
                system("pause");
                exit(1);
            }
        }
};