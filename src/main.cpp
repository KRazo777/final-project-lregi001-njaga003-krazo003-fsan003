#include <iostream>
#include <cctype> 
#include "folder.cpp"
#include "note.cpp"
#include "folderManager.cpp"
using namespace std;

void runFolderMenu(const string& userName){

    //RECIEVER VARIABLE IN CASE USER ENTERS MORE THAN ONE CHARACTER 
    string input;

    // user's choice when selecting menu options
    char userChoice;

    //user's choice when selecting a folder
    int userFolderNum;
    
    //user's input when entering the name of a folder
    string folderName;

    //manages the alteration and editing of folders (see folderManager class)
    FolderManager folderMenu;

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
                getline(cin, folderName);

                //statement checks to make sure folderName has at least one character in it 
                // so folderName is not able to be " " or "      "
                if(folderName.find_first_not_of(' ') == std::string::npos){
                    cout << "No file name entered. Folder Creation Canceled." << endl;
                    break;
                }

                folderMenu.createFolder(folderName);
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
                // Ignore the incorrect input so it doesn't stay in cin on new while loop
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
                cout << "Invalid choice! Please try again." << endl;
        }
      }
    }

};


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