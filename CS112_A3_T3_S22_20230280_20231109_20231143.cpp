/*
--> Name: CS112_A3_T3_S22_20230280_20231109_20231143.cpp
--> Purpose: A small program that make some photoshop edits on any image you want by only using its address,
             in this once there is a 5 different filters that are : graysale filter, black and white filter,
             invert image filter,

--> Author of (1, 4, 7, 10) filters: Fatema El-Zhraa Ahmed Mohamed El-Fiky.             (ID:20230280)         (Section : S22)
--> Email : fatmaelfeky922@gmail.com

--> Author of (2, 5, 8, 11) filters: Aly El-Deen Yasser Aly.                            (ID:20231109)         (Section : S22)
--> Email : aibakgaming747@gmail.com

--> Author of (3, 6, 9. 12) filters: Mohammed Atef Abd EL-Kader Bayomi.                 (ID:20231143)         (Section : S22)
--> Email : mohamed45452020@gmail.com
======================================================================================================================================================================= */
// Definging liberary
#include <bits/stdc++.h>
#include "Image_Class.h"
#include <fstream>
#define ll long long
using namespace std;

// Defining some functions
// To check the existence of image 
string validationpart1(string nameimage) {
    while (true){
        ifstream file_stream(nameimage);
        try {
            if (file_stream.is_open())
                break;
            else 
                throw std::runtime_error("File is not exist , pls enter again\n");
        }
        catch (const std::exception& e) {
            cout << "Please enter again a valid photo : ";
            getline(cin, nameimage);
        }
    }
    return nameimage;
}


// To check if the name of photo is valid and extension
string validationpart2(string nameOfSavedImage) {
    while (nameOfSavedImage.size() <= 4) {
        cout << "The name is too short enter again : ";
        getline(cin, nameOfSavedImage);
    }
    string extension = nameOfSavedImage.substr(nameOfSavedImage.size() - 4);

    while (extension != ".jpg" && extension != ".png" && extension != ".bmg" && extension != ".tga"){
        cout << "Please enter the name of the image with correct extension : ";
        getline(cin, nameOfSavedImage);
        while (nameOfSavedImage.size() <= 4) {
            cout << "The name is too short enter again : ";
            getline(cin, nameOfSavedImage);
        }
        extension = nameOfSavedImage.substr(nameOfSavedImage.size() - 4);
    }
    return nameOfSavedImage;
}


string savingWay(string originname){
    cout << "Do you like to save in new image or the same one?\n [1] Save in new image\n [2] Save in the same picture\nYour choice: ";
    string choice;
    getline(cin, choice);
    while (choice != "1" && choice != "2") {
        cout << "Enter a valid choice : ";
        getline(cin, choice);
    }
    string nameOfSavedImage;
    if (choice == "1") {
        cout << "The filename should end with the extension (.jpg or.png or.bmg or.tga)\n";
        cout << "Enter the name of the new image: ";
        getline(cin, nameOfSavedImage);
        nameOfSavedImage = validationpart2(nameOfSavedImage);
    }
    else
        nameOfSavedImage = originname;
    return nameOfSavedImage;
}

// ========================================================>> Filter 1: Grayscale Conversion <<======================================================== //

void grayscale_conversion(string nameimage) {
    cout << "\n# ===== Welcome to the Grayscale Filter ===== #\n";
    Image image(nameimage);

    // To get the degree of the gray colour
    for (int i = 0; i < image.width; i++){
        for (int j = 0; j < image.height; j++){
            int avg = 0;
            for (int k = 0; k < 3; k++)
                avg += image(i, j, k);

            avg = avg / 3;

            for (int k = 0; k < 3; k++)
                image(i, j, k) = avg;
        }
    }
    string saved = savingWay(nameimage);
    image.saveImage(saved);
    cout << endl << "Image saved in " << saved << " successfully!" << endl << endl;
}


// ========================================================>> Filter 2: Black and White <<============================================================ //
void black_and_white(string image_address) {
    cout << endl << "\n# ===== Welcome to Black and White Filter ===== #" << endl;
    Image image(image_address);

    // To make the dark point black and the light point white
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int average = 0;
            for (int k = 0; k < 3; k++)
                average += image(i, j, k);
            if (average / 3 > 124) {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
            else {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 0;
            }
        }
    }
    string saved = savingWay(image_address);
    image.saveImage(saved);

    cout << endl << "Image saved in " << saved << " successfully!" << endl << endl;
}


// ========================================================>> Filter 3: Invert Image <<=============================================================== //

void invert_image(string image_address) {
    cout << endl << "\n# ===== Welcome to Invert Image Filter ===== #" << endl;
    Image image(image_address);

    // For inverting the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }
    string saved = savingWay(image_address);
    image.saveImage(saved);
    system(saved.c_str());
    cout << "\nImage saved in " << saved << " successfully.\n" << endl;
}


// ========================================================>> Filter 4: Flip image <<================================================================ //
void Flip_image(string image_address) {
    string choice;

    while (true) {
        
        // To Check the menu choices
        while (true) {
            cout << "\n# ===== Welcome to Flip image Filter ===== #\n";
            cout << "How do you want to flip the image?\n [1] Horizontal flip.\n [2] Vertical flip.\n [3] Both flips \nEnter Your Choice:";
            getline(cin, choice);

            bool check = false;
            for (int i = 1; i <= 3; i++) {         // Checking of answer.
                if (choice == to_string(i)) {
                    check = true;
                    break;
                }
            }

            if (check)
                break;
            cout << "Invalid Choice. Try Again." << endl << endl;
        }
        Image image(image_address);

        // Vertical Flip
        if (choice == "2") {
            for (int i = 0; i < image.width; i++) {
                for (int j = 0; j < image.height / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        int v = image(i, j, k);
                        image(i, j, k) = image(i, image.height - j - 1, k);
                        image(i, image.height - j - 1, k) = v;
                    }
                }
            }
        }
        
        // Horizontal Flip
        else if (choice == "1") {
            for (int i = 0; i < image.width / 2; i++) {
                for (int j = 0; j < image.height; j++) {
                    for (int k = 0; k < 3; k++) {
                        int v = image(i, j, k);
                        image(i, j, k) = image(image.width - i, j, k);
                        image(image.width - i, j, k) = v;
                    }
                }
            }
        }

        // Both Flip
        else {
            for (int i = 0; i < image.width; i++) {
                for (int j = 0; j < image.height / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        int v = image(i, j, k);
                        image(i, j, k) = image(i, image.height - j - 1, k);
                        image(i, image.height - j - 1, k) = v;
                    }
                }
            }
            for (int i = 0; i < image.width / 2; i++) {
                for (int j = 0; j < image.height; j++) {
                    for (int k = 0; k < 3; k++) {
                        int v = image(i, j, k);
                        image(i, j, k) = image(image.width - i, j, k);
                        image(image.width - i, j, k) = v;
                    }
                }
            }
        }

        string saved = savingWay(image_address);
        image.saveImage(saved);

        cout << endl << "Image saved in " << saved << " successfully" << endl << endl;

        // To check if user wants to make another flip or not...
        cin.ignore(0, '\n');
        while (true) {
            cout << "Do you want to make another flip?\n [1] Yes\n [2] No\nYour choice :";
            string choice;
            getline(cin, choice);
            if (choice == "1")              // if yes
                break;
            else if (choice == "2")         // if no
                return;

            // If he enter an invalid choice
            cout << "Please choose a valid option " << endl;
        }
    }
}

// ========================================================>> Filter 5: Rotate Image <<======================================================== //

void rotate_image(string image_address) {
    
    cout << endl << "# ===== Welcome to Rotate Image Filter ===== #" << endl;
    Image image(image_address);
    Image image2(image.height, image.width);
    string choice;
    bool valid = false;

    // To check the menu choices
    while (true) {
        cout << "\nYou want to rotate this image clockwise by : .........\n";
        cout << " [1] 90.\n [2] 180.\n [3] 270.\nEnter Your Choice: ";
        getline(cin, choice);
        bool check = false;
        for (int i = 1; i <= 3; i++) {         // Checking of answer.
            if (choice == to_string(i)) {
                check = true;
                break;
            }
        }

        if (check)
            break;
        cout << "Invalid Choice. Try Again." << endl << endl;
    }

    // 90 Degree clockwise Rotations
    if (choice == "1") {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image2(image.height - j, i, k) = image(i, j, k);
                }
            }
        }
    }

    // 180 Degree clockwise Rotations
    else if (choice == "2"){
        for (int i = 0; i < image.width / 2; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < 3; k++) {
                    int v = image(i, j, k);
                    image(i, j, k) = image(image.width - i, j, k);
                    image(image.width - i, j, k) = v;
                }
            }
        }
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    int v = image(i, j, k);
                    image(i, j, k) = image(i, image.height - j - 1, k);
                    image(i, image.height - j - 1, k) = v;
                }
            }
        }
        valid = true;
    }

    // 270 Degree clockwise Rotations
    else if (choice == "3"){
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image2(j, i, k) = image(image.width - i, j, k);
                }
            }
        }
    }
    string saved = savingWay(image_address);
    if(valid)
        image.saveImage(saved);
    else
        image2.saveImage(saved);
    cout << "\nImage saved in " << saved << " successfully.\n" << endl;
}
// ===============================================================>> Main Application <<=============================================================== //

int main() {
    // Showing what program do.
    cout << "# ===== Welcome To Baby Photoshop Application ===== #" << endl;
    cout << "--> A small program that make some photoshop edits on any image you want by only using its address," << endl;
    cout << "    in this once there is a 5 different filters that are : grayscale filter, black and white filter," << endl;
    cout << "    invert image filter," << endl;
    cout << "===================================================================================================" << endl;
    string nameimage;
    cout << "the filename should end with the extension .jpg or.png or.bmg or.tga\n";
    cout << "please enter the photo : ";
    getline(cin, nameimage);
    nameimage = validationpart1(nameimage);

    // To keep the program running.
    while (true) {
        // Menu choice to check of it
        string choice_menu;
        while (true) {
            cout << "\nChoose One Of This Filters:-" << endl;
            cout << " [1] Grayscale Conversion.\n [2] Black and White.\n [3] Invert Image colours.\n [4] Flip Image.\n [5] Rotate Image.\n [6] Exit Application.\nEnter Your Choice:";
            getline(cin, choice_menu);

            bool check = false;
            for (int i = 1; i <= 6; i++) {         // Checking of answer.
                if (choice_menu == to_string(i)) {
                    check = true;
                    break;
                }
            }

            if (check)
                break;
            cout << "Invalid Choice. Try Again." << endl << endl;
        }

        // Gray scale filter
        if (choice_menu == "1") 
            grayscale_conversion(nameimage);

        // Black and White filter
        else if (choice_menu == "2")
            black_and_white(nameimage);

        // Invert Image filter
        else if (choice_menu == "3")
            invert_image(nameimage);

        // Flip filter
        else if (choice_menu == "4") 
            Flip_image(nameimage);

        // Rotate filter
        else if (choice_menu == "5") 
            rotate_image(nameimage);

        // To exit program
        else if (choice_menu == "6") {
            cout << endl << "# === Thanks For Using Our Application !! === #" << endl;
            break;
        }

        // Continue a menu to see if user wants to continue or exit the program.
        while (true) {
            cout << "Do You Want To Continue?\n [1] Yes.\n [2] No.\nEnter Your Choice: ";
            string choice;
            getline(cin, choice);

            if (choice == "1")              // If he wants to continue
                break;

            else if (choice == "2") {        // If he doesn't
                cout << endl << "# === Thanks For Using Our Application !! === #" << endl;
                return 0;
            }

            // If he entered an invalid choice
            cout << "Invalid Choice. Try Again." << endl;
        }

        // To see if a user wants to change a photo or not
        while (true) {
            cout << "Do You Want To Change Photo?\n [1] Yes.\n [2] No.\nEnter Your Choice: ";
            string choice1;
            getline(cin, choice1);

            if (choice1 == "1") {              // If he wants to
                cout << "the filename should end with the extension .jpg or.png or.bmg or.tga\n";
                cout << "please enter the photo\n";
                getline(cin, nameimage);
                nameimage = validationpart1(nameimage);
                break;
            }

            else if (choice1 == "2")          // If he doesn't
                break;

            // If he entered an invalid choice
            cout << "Invalid Choice. Try Again." << endl;
        }

    }
    return 0;
}
