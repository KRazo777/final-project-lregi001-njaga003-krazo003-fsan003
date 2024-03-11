#include <iostream>
#include "../include/folder.h"
#include "../include/note.h"
#include "../include/folderManager.h"
#include "../include/runMenus.h"
#include <cctype> 
#include <limits>
using namespace std;


int main(){
    //initial run
    string userName;
    
    
    cout << "Enter your username: ";
    getline(cin, userName);

    //makes sure user enters a non-empty string that isn't just whitepsace
    while(userName.find_first_not_of(' ') == std::string::npos){
       cout << "No username entered. Please Try again" << endl;
       cout << "Enter your username: ";
       getline(cin, userName);
    }

    runFolderMenu(userName);



    return 0;
}