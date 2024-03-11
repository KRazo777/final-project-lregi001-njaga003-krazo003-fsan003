#include <iostream>
#include <cctype> 
#include <limits>
#include "../include/folder.h"
#include "../include/note.h"
#include "../include/folderManager.h"
#include "../include/runMenus.h"
using namespace std;

void runFolderMenu(const string& userName){

    //RECIEVER VARIABLE IN CASE USER ENTERS MORE THAN ONE CHARACTER 
    string input;

    // user's choice when selecting menu options
    char userChoice;

    //user's choice when selecting a folder
    int userFolderNum;
    
    //user's input when entering the name of a folder
    string userFolderName;

    //manages the alteration and editing of folders (see folderManager class)
    FolderManager folderMenu;

    //user's chosen folder (used when opening a folder)
    Folder userFolder;

    cout << "Hello, " << userName << "!" << endl;

    while (true) { //this is where the breaks come back to
        cout << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
        cout << "New Folder (n)" << endl;
        cout << "Output Folders (u)" << endl;
        cout << "Delete Folder (d)" << endl;
        cout << "Edit Folder Title (e)" << endl;
        cout << "Open Folder (o)" << endl;
        cout << "Quit (q)" << endl;
        cout << "Enter your choice: ";
    
        cin.clear(); //clear cin, make sure no garbage input
        getline(cin, input);

        // Take the first character of the input so we can have one char variable to work with
        cout << endl;
        cout << "---------------------------------------------------------------------------------" << endl;

        // If input is empty or has more than one character, continue to the next iteration
        if (input.empty() || input.size() > 1) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        // Take the first character of the input
        userChoice = tolower(input[0]);

        //convert char to lowercase before check
        userChoice = tolower(userChoice); 

        // if input is not acceptable
        // still trying to fix issue where if something like "nFolder" is entered it will create folder named Folder
            if ( (userChoice != 'n') && (userChoice != 'u') && (userChoice != 'd') && (userChoice != 'e') && (userChoice != 'o') && (userChoice != 'q')) {
                cout << endl;
                cout << "Invalid choice. Please try again." << endl;
            } 
    // else, continue program
    else {
        switch (userChoice) {
            case 'n':
                cout << "Enter new folder name: ";
                cin.clear(); //clear cin, make sure no garbage input
                getline(cin, userFolderName);

                //statement checks to make sure userFolderName has at least one character in it 
                // so userFolderName is not able to be " " or "      "
                if(userFolderName.find_first_not_of(' ') == std::string::npos){
                    cout << "No file name entered. Folder Creation Canceled." << endl;
                    break;
                }

                folderMenu.createFolder(userFolderName);
                folderMenu.printFolders();
                break;
            case 'u':
                folderMenu.printFolders();
                break;
            case 'd':
                folderMenu.printFolders(); //this function prints out error and returns if empty

                //if folder is empty, printFolders() would have printed error message already
                if (folderMenu.folderIsEmpty()) {
                    break; 
                }

                //folder is not empty
                cout << "Enter number for the folder you want to delete: ";
                cin.clear(); //make sure there is no garbage input
                cin >> userFolderNum;

                // Make sure what they input is actually an existing number and that cin does not fail
                if (cin.fail() || userFolderNum < 1 || userFolderNum > folderMenu.getFolderSize()){
                    cout << "Invalid number. Deletion Canceled." << endl;
                    cin.clear();
                    // Ignore the incorrect input so it doesn't stay in cin on new while loop
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                folderMenu.deleteFolder(userFolderNum);
                // ignore the integer input so it doesn’t run on next while loop
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 'e':
                cout << "Editing folder title..." << endl;
                folderMenu.printFolders();
                cout << "Enter number for the folder name you want to edit: ";
                cin.clear();
                cin >> userFolderNum;
                if(cin.fail() || userFolderNum < 1 || userFolderNum > folderMenu.getFolderSize ()){
                    cout << "Invalid number. Cannot edit folder name." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;

                }
                folderMenu.renameFolder(userFolderNum);
                break;
            case 'o':

                folderMenu.printFolders(); //this function prints out error and returns if empty
                
                //if folder is empty, printFolders() would have printed error message already
                if (folderMenu.folderIsEmpty()) {
                    break; 
                }

                //folder is not empty
                cout << "Enter the number of the Folder you want to open: ";
                cin.clear(); //make sure there is no garbage input
                cin >> userFolderNum;

                // Make sure what they input is actually an existing number and that cin does not fail
                if (cin.fail() || userFolderNum < 1 || userFolderNum > folderMenu.getFolderSize()){
                    cout << "Invalid number. Opening Failed." << endl;
                    cin.clear();
                    // Ignore the incorrect input so it doesn't stay in cin on new while loop
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cin.ignore(); //clears userFolderNum left in input buffer to it doesn't affect later inputs

                userFolder = folderMenu.getFolder(userFolderNum - 1); //gets folder object stored at index

                cout << endl;

                cout << userFolder.getFolderName() << ":" << endl << endl;

                userFolder.printAllNoteTitles();

                cout << endl;

                runNotesMenu(userFolder);

                // ignore the integer input so it doesn’t run on next while loop
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 'q':
                cout << "Quitting program..." << endl;
                return;
            default:
                cout << endl;
                cout << "Invalid choice! Please try again." << endl;
        }
      }
    }

};

void runNotesMenu(Folder& folderToOpen) { //similar to folder menu but for notes

    //RECIEVER VARIABLE IN CASE USER ENTERS MORE THAN ONE CHARACTER 
    string input;

    // user's choice when selecting menu options
    char userChoiceNoteMenu;

    //user's name for their note
    string userNoteName;

    //the body of the user's note (aka the actual contents of the note itself)
    string userNoteBody;

    //last time user edited note
    string userLastTimeofEdit = "0"; //delete 0 later

    //the note object user created
    Note userNote;

    while (true) { //this is where the breaks come back to
        cout << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
        cout << "New Note (n)" << endl;
        cout << "Delete Note (d)" << endl;
        cout << "Add To Note (a)" << endl;
        cout << "Open Note (o)" << endl;
        cout << "Main Menu (m)" << endl;
        cout << "Quit (q)" << endl;
        cout << "Enter your choice: ";
    
        cin.clear(); //clear cin, make sure no garbage input
        getline(cin, input);

        // Take the first character of the input so we can have one char variable to work with
        cout << endl;
        cout << "---------------------------------------------------------------------------------" << endl;

        // If input is empty or has more than one character, continue to the next iteration
        if (input.empty() || input.size() > 1) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        // Take the first character of the input
        userChoiceNoteMenu = tolower(input[0]);

        //convert char to lowercase before check
        userChoiceNoteMenu = tolower(userChoiceNoteMenu); 

        // if input is not acceptable
        // still trying to fix issue where if something like "nFolder" is entered it will create folder named Folder
        if ((userChoiceNoteMenu != 'n') && (userChoiceNoteMenu != 'd') && (userChoiceNoteMenu != 'a') && (userChoiceNoteMenu != 'o') && (userChoiceNoteMenu != 'm') && (userChoiceNoteMenu != 'q')) {
            cout << endl;
            cout << "Invalid choice. Please try again." << endl;
        } 
        // else, continue program
        else {
            switch (userChoiceNoteMenu) {
                case 'n':
                    cout << "Enter title for new note: ";
                    cin.clear(); //clear cin, make sure no garbage input
                    getline(cin, userNoteName);

                    //statement checks to make sure userNoteName has at least one character in it 
                    // so userNoteName is not able to be " " or "      "
                    if(userNoteName.find_first_not_of(' ') == std::string::npos){
                        cout << "No name entered for note. Note Creation Canceled." << endl;
                        break;
                    }

                    //take in other inputs to create note

                    cout << "Enter the contents of your note. Type the tilde character (~) to end your note:" << endl;

                    getline(cin, userNoteBody, '~');

                    cin.ignore(); //so tilde '~' characther isn't left in input buffer

                    //statement checks to make sure userNoteBody has at least one character in it 
                    // so userNoteBody is not able to be " " or "      "
                    if(userNoteBody.find_first_not_of(' ') == std::string::npos){
                        cout << "No contents entered for note. Note Creation Canceled." << endl;
                        break;
                    }

                    cout << endl;   

                    //userLastTimeofEdit = (insert whatever algorthim find the time and then do smth like Int_to_str() function or smth);

                    userNote = Note(userNoteName, userNoteBody, userLastTimeofEdit);
                    userNote.printNote(); //executes after note is completed
                    break;
                case 'd':
                    folderToOpen.printAllNoteTitles();
                    break;
                case 'q':
                    cout << "Quitting program..." << endl;
                    return;
                default:
                    cout << endl;
                    cout << "Invalid choice! Please try again." << endl;
            }
        }
    }
}



void save(const string& infoFileName, FolderManager& listOfFolders) { //
    //put implementation here
}

