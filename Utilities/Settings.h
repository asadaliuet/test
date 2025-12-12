#pragma once

#include "Libraries.h"

class Settings
{
    public:

        static void Create_Default_OR_Update_Current(vector<int>& Setting)
        {
            ifstream Read_From_File("Settings.txt");

            // This creates a new settings file if it isn't present by default.
            if(!Read_From_File.is_open())
            {
                ofstream Create_File("Settings.txt");

                Create_File << "Auto Push Delay: " << 5 << endl;
                Create_File << "Instant Pull Enabled: " << 0 << endl;

                Create_File.close();

                Setting[0] = 5;
                Setting[1] = 1;
            }
            // This updates settings by reading settings file.
            else
            {
                string Single_Line_Data;
                int Data_Count = 0;

                while(getline(Read_From_File, Single_Line_Data))
                {
                    Single_Line_Data = Single_Line_Data.substr(Single_Line_Data.find(':') + 1);
                    Single_Line_Data.erase(0, Single_Line_Data.find_first_not_of(" "));
                    Setting[Data_Count] = stoi(Single_Line_Data);

                    Data_Count++;
                }
            }

            Read_From_File.close();
        }
};