#pragma once

#include "Libraries.h"
#include "Add-on.h"
#include "Command-Hub.h"

class Github_Configuration
{
    public:

        static vector<string> Take_GitHub_Credentials()
        {
            string Choice;
            vector<string> GitHub_Details(4);
            bool Loop = true;

            while(Loop)
            {
                cout << "\nEnter your github username: ";
                cin >> GitHub_Details[0];
                cout << "Enter your github email: ";
                cin >> GitHub_Details[1];
                cout << "Enter your github repository name: ";
                cin >> GitHub_Details[2];
                cout << "Enter your classic github token (enter 'none' if you don't have it): ";
                cin >> GitHub_Details[3];

                while(1)
                {
                    cout << "\nDo you wanna re-enter github credenials(Y/N): ";
                    cin >> Choice;

                    if(Choice == "Y" || Choice == "y")
                    {
                        break;
                    }
                    else if(Choice == "N" || Choice == "n")
                    {
                        Loop = false;
                        break;
                    }
                    else
                    {
                        Add_on::Margin();
                        Add_on::Invalid();
                        Add_on::Margin();
                    }
                }
            }

            return GitHub_Details;
        }

        static void Configure_Github(vector<string> GitHub_Details)
        {
            Git::Initialize();
            Git::Branch();
            Git::Username(GitHub_Details[0]);
            Git::Email(GitHub_Details[1]);
            Git::Repository_Connection(GitHub_Details[0], GitHub_Details[2], GitHub_Details[3]);
            Git::Add_All();
            Git::Commit();
            Git::Push();
        }
};