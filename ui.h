#include <iostream>
#include <windows.h>
using namespace std;

void title() {
    cout<<"                              -:     KLEgram    :-                "<<endl<<endl;
}
void LOS() {
    cout<<"                 -----------                        ----------    "<<endl;
    cout<<"                |1. Signup  |                      |2. Login  |    "<<endl;
    cout<<"                 -----------                        ----------   "<<endl;
    cout<<"                               Enter choice : ";
}
void signup_page(){
    system("cls");
    cout<<endl;
    cout<<"--------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                           Signup  "<<endl;
    cout<<"--------------------------------------------------------------------------------------------"<<endl<<endl;
    cout<<"                 ----------               ----------              ----------         "<<endl;
    cout<<"                |1. Admin  |             |2. Editor |            |3. Viewer |        "<<endl;
    cout<<"                 ----------               ----------              ----------         "<<endl<<endl;
    cout<<"                                          Signup as : ";
}
//(Admin/Editor/Viewer)
void signedup() {
    cout<<"                                     Signup Successful"<<endl;
    cout<<"                                       Please Login"<<endl;
    Sleep(2000);
    system("cls");
}
void login_page(){
    system("cls");
    cout<<endl;
    cout<<"--------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                            Login  "<<endl;
    cout<<"--------------------------------------------------------------------------------------------"<<endl<<endl;
    cout<<"                 ----------               ----------              ----------         "<<endl;
    cout<<"                |1. Admin  |             |2. Editor |            |3. Viewer |        "<<endl;
    cout<<"                 ----------               ----------              ----------         "<<endl<<endl;
    cout<<"                                         Login as : ";
}
void Content_type_page() {
    system("cls");
    cout<<endl;
    cout<<"--------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                         Select Content Type  "<<endl;
    cout<<"--------------------------------------------------------------------------------------------"<<endl<<endl;
    cout<<"                 -------------               -----------              --------------         "<<endl;
    cout<<"                |1. BlogPost  |             |2. Article |            |3. Multimedia |        "<<endl;
    cout<<"                 -------------               -----------              --------------         "<<endl<<endl;
    cout<<"                                           Content type : ";
}
void logged_in(const string& username) {
    system("cls");
    // cout<<endl<<"                                     Login Successful"<<endl<<endl;
    cout<<endl<<endl<<"                                      Welcome "<<username<<endl;
    Sleep(2000);
    system("cls");
}

void Loading() {
    string loadChars = "|/-\\";
    int numCycles = 5; // Number of cycles for the loading animation
    int delay = 100;    // Delay in milliseconds between each frame

    for (int cycle = 0; cycle < numCycles; ++cycle) {
        for (char c : loadChars) {
            cout << "\rLoading... " << c << flush; // '\r' moves the cursor to the beginning of the line
            Sleep(delay);
        }
    }
    cout << "\rLoading... Done!   " << endl; // Clear the loading line after completion
    Sleep(500);
    system("cls");
}
void Logging_out() {
    string loadChars = "|/-\\";
    int numCycles = 5;
    int delay = 100;  

    for (int cycle = 0; cycle < numCycles; ++cycle) {
        for (char c : loadChars) {
            cout << "\rLogging out... " << c << flush; // '\r' moves the cursor to the beginning of the line
            Sleep(delay);
        }
    }
    // cout << "\rLoading... Done!   " << endl; // Clear the loading line after completion
    Sleep(500);
    system("cls");
}

void Clear() {
    Sleep(2000);
    system("cls");
}