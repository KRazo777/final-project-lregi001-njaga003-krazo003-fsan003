#include <iostream>
#include "../include/folder.h"
#include "../include/note.h"
#include "../include/folderManager.h"

using namespace std;


int main(){
    //initial run
    string userName;
    
    cout << "Enter your username: ";
    cin >> userName;

    cout << "Hello " << userName << "!" << endl;    

    Folder h("nidhi");

    return 0;
}