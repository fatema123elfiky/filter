/*
--> Name: CS112_A3_T3_S22_20230280_20231109_20231143.cpp
--> Purpose: A small program that make some photoshop edits on any image you want by only using its address, 
             in this once there is a 5 different filters that are : graysale filter, black and white filter,
             invert image filter,

--> Author of (1, 4, 7, 10) filters: Fatema El-Zhraa Ahmed Mohamed El-Fiky.             (ID:20230280)         (Section : S22)
--> Email :

--> Author of (2, 5, 8, 11) filters: Aly El-Deen Yasser Aly.                            (ID:20231109)         (Section : S22)
--> Email : aibakgaming747@gmail.com

--> Author of (3, 6, 9. 12) filters: Mohammed Atef Abd EL-Kader Bayomi.                 (ID:20231143)         (Section : S22)
--> Email : mohamed45452020@gmail.com
======================================================================================================================================================== */

#include <bits/stdc++.h>
#include "Image_Class.h"
#define ll long long
using namespace std;

// ========================================================>> Filter 1: Grayscale Conversion <<======================================================== //

int grayscale_conversion(){
    
}

// ========================================================>> Filter 2: Black and White <<============================================================ //

int black_and_white(){
    
}

// ========================================================>> Filter 3: Invert Image <<=============================================================== //

int invert_image(){
    
}

// ========================================================>> Filter 4:  <<======================================================== //



// ========================================================>> Filter 5:  <<======================================================== //


// ===============================================================>> Main Application <<=============================================================== //

int main(){
    // showing what program do
    cout << "# ===== Welcome To Photoshop Application ===== #" << endl;
    cout << "==> A small program that make some photoshop edits on any image you want by only using its address," << endl; 
    cout << "in this once there is a 5 different filters that are : graysale filter, black and white filter," << endl;
    cout << "invert image filter," << endl;
    cout << "===================================================================================================" << endl;
    
    // To keep the program running
    while (true){
        string choice_menu;
        while(true){
            // Menu choice to check of it 
            cout << "Choose One Of This Filters:-" << endl;
            cout << "[1] Grayscale Conversion.\n[2] Black and White.\n[3] Invert Image.\n[4] .\n[5] .\n[6] Exit Application.\nEnter Your Choice:";
            getline(cin, choice_menu);

            bool check = false;
            for(int i = 1; i <= 6; i++){         // checking of answer
                if(choice_menu != to_string(i)){
                    check = true;
                    break;
                }
            }

            if(!check)
                break;
            cout << "Invalid Choice. Try Again." << endl;
        }

        // Gray scale filter
        if (choice_menu == "1"){
            grayscale_conversion();
        }

        // Black and White filter
        else if (choice_menu == "2"){
            black_and_white();
        }

        // Invert Image filter
        else if (choice_menu == "3"){
            invert_image();
        }
        
        // 
        else if (choice_menu == "4"){
        }

        //
        else if (choice_menu == "5"){
        }

        // To exit program
        else if (choice_menu == "6"){
            cout << endl << "# === Thanks For Using Our Application !! === #" << endl;
            break;
        }

        // continue menu to see if user wants to continue or exit program
        while (true){
            cout << "Do You Want To Continue?\n[1] Yes\n[2] No\nYour choice : "; 
            string choice;
            getline(cin, choice_menu);
            
            if (choice == "1")              // If he wants to continue
                break;
            
            else if (choice == "2"){        // If he don't
                cout << endl << "# === Thanks For Using Our Application !! === #" << endl;
                return 0;
            }

            // If he entered a invalid choice
            cout << "Invalid Choice. Try Again." << endl;
        }

        // To see if user wants to change photo or not
        while(true) {
            cout << "Do You Want To Change Photo?\n[1] Yes\n[2] No\nYour choice : "; 
            string choice;
            getline(cin, choice_menu);
            
            if (choice == "1"){              // If he wants to
            }

            else if (choice == "2"){        // If he don't
                break;
            }

            // If he entered a invalid choice
            cout << "Invalid Choice. Try Again." << endl;
        }

    }
    return 0;
}
