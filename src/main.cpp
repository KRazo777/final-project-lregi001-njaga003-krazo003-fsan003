#include <iostream>
#include <cctype> 
#include "folder.cpp"
#include "note.cpp"
#include "folderManager.cpp"
using namespace std;

void runFolderMenu(const string& userName){
    // user's choice when selecting menu options
    char userChoice;

    //user's choice when selecting a folder
    int userFolderNum;
    
    //user's input when entering the name of a folder
    string folderName;

    //manages the alteration and editing of folders (see folderManager class)
    FolderManager folderMenu;

    cout << "Hello, " << userName << "!" << endl;

    while (true) {
        cout << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
        cout << "New Folder (n)" << endl;
        cout << "Output Folders (u)" << endl;
        cout << "Delete Folder (d)" << endl;
        cout << "Edit Folder Title (e)" << endl;
        cout << "Open Folder (o)" << endl;
        cout << "Quit (q)" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;
        cout << endl;
        cout << "---------------------------------------------------------------------------------" << endl;

        userChoice = tolower(userChoice); //convert char to lowercase before check

        // if input is not acceptable
        // still trying to fix issue where if something like "nFolder" is entered it will create folder named Folder
        // for right now, only works to prevent input like 'm' or 'p'
            if ( (userChoice != 'n') && (userChoice != 'u') && (userChoice != 'd') && (userChoice != 'e') && (userChoice != 'o') && (userChoice != 'q')) {
                cout << endl;
                cout << "Invalid choice. Please try again." << endl;
                cin.clear();
            } 
    // else, continue program
    else {
        switch (userChoice) {
            case 'n':
                cout << "Enter new folder name: ";
                cin >> folderName;
                folderMenu.createFolder(folderName);
                folderMenu.printFolders();
                break;
            case 'u':
                folderMenu.printFolders();
                break;
            case 'd':
                folderMenu.printFolders();

                //if folder is empty, printFolders() would have printed error message already
                if (folderMenu.folderIsEmpty()) {
                    break;
                }
                cout << "Enter number for the folder you want to delete: ";
                cin >> userFolderNum;
                folderMenu.deleteFolder(userFolderNum);
                break;
            case 'e':
                cout << "Editing folder title..." << endl;
                break;
            case 'o':
                cout << "Opening folder..." << endl;
                break;
            case 'q':
                cout << "Quitting program..." << endl;
                return;
            default:
                cout << endl;
                cout << "Invalid choice. Please try again." << endl;
        }
      }
    }

};


int main(){
    //initial run
    string userName;
    
    cout << "Enter your username: ";
    cin >> userName;   

    runFolderMenu(userName);

    return 0;
}