#include "Utilities/Menus.h"
#include "Utilities/GitHub-Configuration.h"
#include "Utilities/Add-on.h"
#include "Utilities/Git-Installer.h"
#include "Utilities/Settings.h"

#include "Git-Auto-Sync/Automation.h"

int main()
{
    vector<int> Setting(2, -1);
    string Choice;

    Git_Installer::Ensure_Git_Installation();
    

    while(1)
    {
        Settings::Create_Default_OR_Update_Current(Setting);

        Menus::Main_Menu();
        cin >> Choice;

        if(Choice == "1")
        {
            while(1)
            {
                Menus::Push_And_Pull_Menu();
                cin >> Choice;

                if(Choice == "1")
                {
                    Automate::Push();
                    break;
                }
                else if(Choice == "2")
                {
                    break;
                }
                else
                {
                    Add_on::Invalid();
                    Add_on::Margin();
                }
            }
        }
        else if(Choice == "2")
        {
            Github_Configuration::Configure_Github
            (
                Github_Configuration::Take_GitHub_Credentials()
            );
        }
        else if(Choice == "3")
        {
            Menus::View_Settings(Setting);
            Add_on::Margin();
        }
        else if (Choice == "4")
        {
            break;
        }
        else
        {
            Add_on::Invalid();
            Add_on::Margin();
        }
    }
}