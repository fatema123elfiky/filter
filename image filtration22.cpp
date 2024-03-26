/*
-- > Name: CS112_A3_T3_S22_20230280_20231109_20231143.cpp
-- > Purpose: A small program that make some photoshop edits on any image you want by only using its address,
in this once there is a 5 different filters that are : graysale filter, black and white filter,
invert image filter,

-- > Author of(1, 4, 7, 10) filters: Fatema El - Zhraa Ahmed Mohamed El - Fiky.             (ID : 20230280)         (Section : S22)
-- > Email : fatmaelfeky922@gmail.com

-- > Author of(2, 5, 8, 11) filters: Aly El - Deen Yasser Aly.                            (ID : 20231109)         (Section : S22)
-- > Email : aibakgaming747@gmail.com

-- > Author of(3, 6, 9. 12) filters: Mohammed Atef Abd EL - Kader Bayomi.                 (ID : 20231143)         (Section : S22)
-- > Email : mohamed45452020@gmail.com
======================================================================================================================================================== */

#include <bits/stdc++.h>
#include<iostream>
#include <fstream>
#include "Image_Class.h"
#include<string>
#define ll long long
using namespace std;

// ========================================================>> Filter 1: Grayscale Conversion <<======================================================== //

int grayscale_conversion() {
    cout << "welcome to the grayscale filter\n";
    cout << "the filename should end with the extension .jpg or.png or.bmg or.tga\n";
    cout << "pls enter the name\n";
    string nameimage;
    getline(cin, nameimage);
    while (true)
    {
        ifstream file_stream(nameimage);
        try {
            if (file_stream.is_open()) {
                break;
            }
            else {
                throw std::runtime_error("File is not exist , pls enter again\n");
            }

        }
        catch (const std::exception& e) {
            cout << "pls enter again a valid name of photo\n";
            getline(cin, nameimage);

        }
    }

    Image image(nameimage);
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            int avg = 0;
            for (int k = 0; k < 3; k++)
            {
                avg += image(i, j, k);
            }
            avg = avg / 3;
            for (int k = 0; k < 3; k++)
            {
                image(i, j, k) = avg;
            }

        }

    }
    cout << "the filename should end with the extension .jpg or.png or.bmg or.tga\n";
    cout << "pls enter the name you want to save the image with\n";
    string nameOfSavedImage;
    getline(cin, nameOfSavedImage);
    while (nameOfSavedImage.size() <= 4) {
        cout << "the name is too short enter again\n";
        getline(cin, nameOfSavedImage);
    }
    string extension = nameOfSavedImage.substr(nameOfSavedImage.size() - 4);
    //cout << extension;//test
    while (extension != ".jpg" && extension != ".png" && extension != ".bmg" && extension != ".tga")
    {
        cout << "pls enter the name of the image with correct extension\n";
        getline(cin, nameOfSavedImage);
        while (nameOfSavedImage.size() <= 4) {
            cout << "the name is too short enter again\n";
            getline(cin, nameOfSavedImage);
        }
        extension = nameOfSavedImage.substr(nameOfSavedImage.size() - 4);
        //cout << extension;//test
    }
    image.saveImage(nameOfSavedImage);
    return 0;
}

// ========================================================>> Filter 2: Black and White <<============================================================ //
void black_and_white() {
    string image_address;
    cout << endl << "# ===== Welcome to Black and White Filter ===== #" << endl;
    cout << "Note enter the image with extension .jpg, .bmp, .png, .tga" << endl;
    cout << "Enter the address of the image you want to edit : ";
    cin >> image_address;

    Image image(image_address);

    for (int i = 0; i < image.width / 2; i++) {
        for (int j = 0; j < image.height / 2; j++) {
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
    cout << "Please, Enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> image_address;
    image.saveImage(image_address);

    cout << endl << "Image saved in " << image_address << " successfully." << endl << endl;
}

// ========================================================>> Filter 3: Invert Image <<=============================================================== //

int invert_image() {
    string image_address;
    cout << endl << "# ===== Welcome to Invert Image Filter ===== #" << endl;
    cout << "Please, Enter colored image name to turn to gray scale: ";
    cin >> image_address;
    string extension = image_address.substr(image_address.size() - 4, 4);
    if (extension == ".jpg" || extension == ".bmp" || extension == ".png" || extension == ".tga") {
        Image image(image_address);

        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = 255 - image(i, j, k);
                }
            }
        }

        while (true) {
            cout << "Please, Enter image name to store new image\n";
            cout << "and specify extension .jpg, .bmp, .png, .tga: ";
            cin >> image_address;
            extension = image_address.substr(image_address.size() - 4, 4);
            if (extension == ".jpg" || extension == ".bmp" || extension == ".png" || extension == ".tga") {
                image.saveImage(image_address);
                cout << "\nImage saved in " << image_address << " successfully.\n" << endl;
                break;
            }
            else { cout << "The image's extension is incorrect." << endl; }
        }
    }
    else { cout << "The image's extension is incorrect." << endl; }
    return 0;
}

// ========================================================>> Filter 4: Flip image <<================================================================ //
void Flip_image() {
    string choice;
    while (true) {
        cout << "\n# ===== Welcome to Flip image filter ===== #\n";
        cout << "How do you want to flip the image?\n [1] Horizontal flip.\n [2] Vertical flip.\nEnter Your Choice:";
        getline(cin, choice);

        bool check = false;
        for (int i = 1; i <= 2; i++) {         // Checking of answer.
            if (choice == to_string(i)) {
                check = true;
                break;
            }
        }

        if (check)
            break;
        cout << "Invalid Choice. Try Again." << endl << endl;
    }

    string image_address;
    cout << endl << "Note enter the image with extenction .jpg, .bmp, .png, .tga" << endl;
    cout << "Enter the address of the image you want to edit : ";
    cin >> image_address;

    Image image(image_address);

    if (choice == "2") {
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    int v = image(i, j, k);
                    image(i, j, k) = image(i, image.height - j, k);
                    image(i, image.height - j, k) = v;
                }
            }
        }
    }
    else {
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

    cout << "Please, Enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> image_address;
    image.saveImage(image_address);

    cout << endl << "Image saved in " << image_address << " successfully" << endl << endl;

}



// ========================================================>> Filter 5:  <<======================================================== //

// ========================================================>> Filter 6: Rotate Image <<======================================================== //

int rotate_image() {
    string image_address;
    cout << endl << "# ===== Welcome to Rotate Image Filter ===== #" << endl;
    cout << "Please, Enter colored image name to rotate it: ";
    cin >> image_address;
    string extension = image_address.substr(image_address.size() - 4, 4);
    if (extension == ".jpg" || extension == ".bmp" || extension == ".png" || extension == ".tga") {
        Image image(image_address);
        Image image2(image.height, image.width);
        string choice;
        while (true) {
            cout << "\nYou want to rotate this image clockwise by : .........\n";
            cout << " [1] 90.\n [2] 180.\n [3] 270.\nEnter Your Choice: ";
            cin >> choice;

            if (choice == "1") {
                for (int i = 0; i < image.width; ++i) {
                    for (int j = 0; j < image.height; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            image2(image.height - j, i, k) = image(i, j, k);
                        }
                    }
                }
                while (true) {
                    cout << "\nPlease, Enter image name to store new image\n";
                    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                    cin >> image_address;
                    extension = image_address.substr(image_address.size() - 4, 4);
                    if (extension == ".jpg" || extension == ".bmp" || extension == ".png" || extension == ".tga") {
                        image2.saveImage(image_address);
                        cout << "\nImage saved in " << image_address << " successfully.\n" << endl;
                        system(image_address.c_str());
                        break;
                    }
                    else { cout << "The image's extension is incorrect." << endl; }
                }
                break;
            }

            else if (choice == "2")
            {
                Image image2(image.width, image.height);
                for (int i = 0; i < image.width; ++i) {
                    for (int j = 0; j < image.height; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            image2(i, j, k) = image(image.width - i, image.height - j, k);
                        }
                    }
                }
                while (true) {
                    cout << "\nPlease, Enter image name to store new image\n";
                    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                    cin >> image_address;
                    extension = image_address.substr(image_address.size() - 4, 4);
                    if (extension == ".jpg" || extension == ".bmp" || extension == ".png" || extension == ".tga") {
                        image2.saveImage(image_address);
                        cout << "\nImage saved in " << image_address << " successfully.\n" << endl;
                        system(image_address.c_str());
                        break;
                    }
                    else { cout << "The image's extension is incorrect." << endl; }
                }
                break;
            }

            else if (choice == "3")
            {
                for (int i = 0; i < image.width; ++i) {
                    for (int j = 0; j < image.height; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            image2(j, i, k) = image(image.width - i, j, k);
                        }
                    }
                }
                while (true) {
                    cout << "\nPlease, Enter image name to store new image\n";
                    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                    cin >> image_address;
                    extension = image_address.substr(image_address.size() - 4, 4);
                    if (extension == ".jpg" || extension == ".bmp" || extension == ".png" || extension == ".tga") {
                        image2.saveImage(image_address);
                        cout << "\nImage saved in " << image_address << " successfully.\n" << endl;
                        system(image_address.c_str());
                        break;
                    }
                    else { cout << "The image's extension is incorrect." << endl; }
                }
                break;
            }
        }
    }
    else { cout << "The image's extension is incorrect." << endl; }
    return 0;
}

// ===============================================================>> Main Application <<=============================================================== //

int main() {
    // Showing what program do.
    cout << "# ===== Welcome To Baby Photoshop Application ===== #" << endl;
    cout << "--> A small program that make some photoshop edits on any image you want by only using its address," << endl;
    cout << "    in this once there is a 5 different filters that are : grayscale filter, black and white filter," << endl;
    cout << "    invert image filter," << endl;
    cout << "===================================================================================================" << endl;

    // To keep the program running.
    while (true) {
        string choice_menu;
        while (true) {
            // Menu choice to check of it
            cout << "Choose One Of This Filters:-" << endl;
            cout << " [1] Grayscale Conversion.\n [2] Black and White.\n [3] Invert Image colours.\n [4] Flip Image.\n [5] .\n [6] Rotate Image.\n [7] Exit Application.\nEnter Your Choice:";
            getline(cin, choice_menu);

            bool check = false;
            for (int i = 1; i <= 7; i++) {         // Checking of answer.
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
        if (choice_menu == "1") {
            grayscale_conversion();
        }

        // Black and White filter
        else if (choice_menu == "2") {
            black_and_white();
        }

        // Invert Image filter
        else if (choice_menu == "3") {
            invert_image();
        }

        // Flip filter
        else if (choice_menu == "4") {
            Flip_image();
        }

        //
        else if (choice_menu == "5") {

        }

        //
        else if (choice_menu == "6") {
            rotate_image();
        }

        // To exit program
        else if (choice_menu == "7") {
            cout << endl << "# === Thanks For Using Our Application !! === #" << endl;
            break;
        }


        cin.ignore(1, '\n');
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
            }

            else if (choice1 == "2") {        // If he doesn't
                break;
            }

            // If he entered an invalid choice
            cout << "Invalid Choice. Try Again." << endl;
        }

    }
    return 0;
}