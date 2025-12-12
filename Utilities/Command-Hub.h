#pragma once

#include "Libraries.h"

class Git
{
    private:
        
        static void Command(const string& command)
        {
            system(command.c_str());
        }

    public:

        static void Initialize()
        {
            Command("git init");
        }

        static void Branch()
        {
            Command("git branch -m main");
        }

        static void Username(string User_Data)
        {
            // We construct the string directly inside the function call
            Command("git config --local user.name \"" + User_Data + "\"");
        }

        static void Email(string User_Data)
        {
            Command("git config --local user.email \"" + User_Data + "\"");
        }

        static void Repository_Connection(string Username, string Repository, string Token)
        {
            if(Token == "none" || Token == "")
            {
                Command("git remote add origin https://github.com/" + Username + "/" + Repository + ".git");
            }
            else
            {
                Command("git remote add origin https://" + Token + "@github.com/" + Username + "/" + Repository + ".git");
            }
        }

        static void Add_All()
        {
            Command("git add .");
        }

        static void Commit()
        {
            Command("git commit -m \"Pushed via Git-Buddy\"");
        }

        static void Push()
        {
            Command("git push -u origin main");
        }

        static void Pull()
        {
            Command("git pull origin main");
        }
};