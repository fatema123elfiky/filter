/*
--> Name: CS112_A3_T3_S22_20230280_20231109_20231143.cpp
--> Purpose:

--> Author 2: Fatema El-Zhraa Ahmed Mohamed El-Fiky.             (ID:20230280)         (Section : S22)
--> Email :

--> Author 2: Aly El-Deen Yasser Aly.                            (ID:20231109)         (Section : S21)
--> Email : aibakgaming747@gmail.com

--> Author 3: Mohammed Atef Abd EL-Kader Bayomi.                 (ID:20231143)         (Section : S22)
--> Email : mohamed45452020@gmail.com
======================================================================================================================================================== */

#include <bits/stdc++.h>
#include "Image_Class.h"
#define ll long long
using namespace std;

// ========================================================>> Filter 1: Grayscale Conversion <<======================================================== //

int grayscale_conversion(){
    
}

// ========================================================>> Filter 2: Black and White <<======================================================== //

int black_and_white(){
    
}

// ========================================================>> Filter 3: Invert Image <<======================================================== //

int invert_image(){
    
}

// ========================================================>> Filter 4:  <<======================================================== //


// ========================================================>> Filter 5:  <<======================================================== //


// ===============================================================>> Main Application <<=============================================================== //

int main()
{
    cout << "# ===== Welcome To Baby Photoshop Application ===== #" << endl;
    while (true)
    {
        string choice_menu;
        cout << "Choose One Of This Filters:-" << endl;
        cout << " (1) Grayscale Conversion.\n (2) Black and White.\n (3) Invert Image.\n (4) .\n (5) .\n (6) Exit Application.\nEnter Your Choice:";
        cin >> choice_menu;
        if (choice_menu == "1")
        {
            grayscale_conversion();
        }
        else if (choice_menu == "2")
        {
            black_and_white();
        }
        else if (choice_menu == "3")
        {
            invert_image();
        }
        else if (choice_menu == "4")
        {

        }
        else if (choice_menu == "5")
        {

        }
        else if (choice_menu == "6")
        {
            cout << endl << "# === Thanks For Using Our Application !! === #" << endl;
            break;
        }
        else {cout << "Please enter a valid input." << endl << endl;}
    }
    return 0;
}
