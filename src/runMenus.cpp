#include <string>
#include <vector>
#include<sstream>
#include <fstream>
#include <iostream>
#include <cctype> 
#include <limits>
#include "../include/folder.h"
#include "../include/note.h"
#include "../include/folderManager.h"
#include "../include/runMenus.h"
using namespace std;

void runFolderMenu(const string& userName, istream& cin){

    //RECIEVER VARIABLE IN CASE USER ENTERS MORE THAN ONE CHARACTER 
    string input;

    // user's choice when selecting menu options
    char userChoice;

    //user's choice when selecting a folder
    int userFolderNum;
    
    //user's input when entering the name of a folder
    string userFolderName;

    //user's input when entering the new name of a folder
    string newFolderName;

    //manages the alteration and editing of folders (see folderManager class)
    FolderManager folderMenu;

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
                if (folderMenu.isEmpty()) {
                    break; 
                }

                cout << endl;

                //folder is not empty
                cout << "Enter number for the folder you want to delete: ";
                cin.clear(); //make sure there is no garbage input
                cin >> userFolderNum;

                cout << endl;

                // Make sure what they input is actually an existing number and that cin does not fail
                if (cin.fail() || userFolderNum < 1 || userFolderNum > folderMenu.getListOfFoldersSize()){
                    cout << "\nInvalid number. Deletion Canceled." << endl;
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
                //if folder is empty, should not be able to edit any folder titles
                if (folderMenu.isEmpty()) {
                    cout << "No folders have been created." << endl;
                    break; 
                }

                cout << "Editing folder title..." << endl;
                folderMenu.printFolders();
                cout << "Enter number for the folder name you want to edit: ";
                cin.clear();
                cin >> userFolderNum;
                if(cin.fail() || userFolderNum < 1 || userFolderNum > folderMenu.getListOfFoldersSize()){
                    cout << "\nInvalid number. Cannot edit folder name." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;

                }
                folderMenu.renameFolder(userFolderNum, cin);

                cout << endl;
                cout << "Folder #" << userFolderNum << " succesfully updated." << endl;
                folderMenu.printFolders();
                
                break;
            case 'o':

                folderMenu.printFolders(); //this function prints out error and returns if empty
                
                //if folder is empty, printFolders() would have printed error message already
                if (folderMenu.isEmpty()) {
                    break; 
                }

                //folder is not empty
                cout << "Enter the number of the Folder you want to open: ";
                cin.clear(); //make sure there is no garbage input
                cin >> userFolderNum;

                // Make sure what they input is actually an existing number and that cin does not fail
                if (cin.fail() || userFolderNum < 1 || userFolderNum > folderMenu.getListOfFoldersSize()){
                    cout << endl;
                    cout << "Invalid number. Opening Failed." << endl;
                    cin.clear();
                    // Ignore the incorrect input so it doesn't stay in cin on new while loop
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cin.ignore(); //clears userFolderNum left in input buffer to it doesn't affect later inputs

                userFolder = folderMenu.getFolder(userFolderNum - 1); //gets folder object stored at index

                cout << endl;

                userFolder.printAllNoteTitles(); //this will also print the "folderName: "

                cout << endl;

                runNotesMenu(userFolder); //when using notes menu is done, return statement comes here

                folderMenu.updateFolder(userFolderNum - 1, userFolder);

                break;
            case 'q':
                cout << "Quitting program..." << endl;
                //put save function here
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

    //user's choice when selecting a note
    int userNoteNum;

    //user's additions in the note's function
    string userNoteAdditions;

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

                    userNote = Note(userNoteName, userNoteBody, userLastTimeofEdit);
                    userNote.setLastEdit();
                    userNote.printNote(); //executes after note is completed
                    folderToOpen.AddNotetoFolder(userNote); //adds note object into folder object
                    break;
                case 'd':

                    if (folderToOpen.empty()) // If folder is empty don't allow deletion.
                    {
                        cout << "Folder is empty! Note deletion cancelled." << endl;
                        break;
                    }

                    cout << "Choose a note to delete:" << endl << endl;
                    folderToOpen.printAllNoteTitles();
                    cout << endl;
                    
                    cout << "Select the number of the note you want to delete: ";
                    cin.clear(); //make sure there is no garbage input
                    cin >> userNoteNum;

                    // Make sure what they input is actually an existing number and that cin does not fail
                    if (cin.fail() || userNoteNum < 1 || userNoteNum > folderToOpen.getFolderSize()) {
                        cout << endl;
                        cout << "Invalid number. Opening Failed." << endl;
                        cin.clear();
                        // Ignore the incorrect input so it doesn't stay in cin on new while loop
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }

                    cin.ignore(); // Clear buffer for future use

                    cout << endl << folderToOpen.getNote(userNoteNum - 1).getTitle() << " was successfully deleted." << endl;
                    folderToOpen.deleteNote(folderToOpen.getNote(userNoteNum - 1).getTitle());

                    break;
                case 'a': //add to note

                    if (folderToOpen.empty()) // If folder is empty don't allow adding to notes.
                    {
                        cout << "Folder is empty! No notes to add to." << endl;
                        break;
                    }

                    cout << "Choose a note to add to:" << endl << endl;
                    folderToOpen.printAllNoteTitles();
                    
                    cout << "Select the number of the note you want to add to: ";
                    cin.clear(); //make sure there is no garbage input
                    cin >> userNoteNum;
                    cout << endl;

                    // Make sure what they input is actually an existing number and that cin does not fail
                    if (cin.fail() || userNoteNum < 1 || userNoteNum > folderToOpen.getFolderSize()) {
                        cout << endl;
                        cout << "Invalid number. Opening Failed." << endl;
                        cin.clear();
                        // Ignore the incorrect input so it doesn't stay in cin on new while loop
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }

                    cin.ignore(); //clears userNoteNum left in input buffer to it doesn't affect later inputs

                    cout << "Current Note Contents: " << endl << endl;

                    userNote = folderToOpen.getNote(userNoteNum - 1); //gets folder object stored at index
                    userNote.printNote();

                    cout << "Enter any additional content to your note. Type the tilde character (~) to end your additions: " << endl;
                    getline(cin, userNoteAdditions, '~');

                    //statement checks to make sure userNoteBody has at least one character in it 
                    // so userNoteBody is not able to be " " or "      "
                    if(userNoteAdditions.empty() || userNoteAdditions.find_first_not_of(' ') == std::string::npos){
                        cout << "No addtional contents entered for note. Note Additions Canceled." << endl;
                        break;
                    }

                    userNote.setBody(userNote.getBody() + userNoteAdditions);

                    userNote.setLastEdit();

                    folderToOpen.updateNote(userNoteNum - 1, userNote);

                    cin.ignore(); //so tilde '~' characther isn't left in input buffer

                    cout << endl;   

                    cout << "Updated Note Contents: " << endl << endl;

                    userNote.printNote();
                    break;
                case 'o':

                    if (folderToOpen.empty()) // If folder is empty don't allow deletion.
                    {
                        cout << "Folder is empty! No notes have been created." << endl;
                        break;
                    }

                    folderToOpen.printAllNoteTitles();

                    cout << "Enter the number of the note you want to open: ";
                    cin.clear(); //make sure there is no garbage input
                    cin >> userNoteNum;

                    // Make sure what they input is actually an existing number and that cin does not fail
                    if (cin.fail() || userNoteNum < 1 || userNoteNum > folderToOpen.getFolderSize()) {
                        cout << endl;
                        cout << "Invalid number. Opening Failed." << endl;
                        cin.clear();
                        // Ignore the incorrect input so it doesn't stay in cin on new while loop
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }

                    cin.ignore(); //clears userNoteNum left in input buffer to it doesn't affect later inputs

                    userNote = folderToOpen.getNote(userNoteNum - 1); //gets folder object stored at index

                    userNote.printNote();
                    break;
                case 'm':
                    cout << "Returning to folder menu..." << endl;
                    return;
                default:
                    cout << endl;
                    cout << "Invalid choice! Please try again." << endl;
            }
        }
    }
}

void load (ifstream& readFile, string& userName, FolderManager &listOfFolders){
    //initialize index for later use
    int index = -1;
    string nameOfNote;
    string noteBody;
    string lastEditOfNote;


    if (readFile.is_open()) {
        string inputFromFile;
        string substr;


        //get username
        getline(readFile, inputFromFile);
        inputFromFile.erase(0, 10);
        userName = inputFromFile;


        //read file till end of file reached
        while (!readFile.eof()) {
       
            getline(readFile, inputFromFile);
            if(inputFromFile == "*_BEGIN FOLDER_*"){


                getline(readFile, inputFromFile);
                if(inputFromFile.substr(0, 12) == "folder_name:"){
                inputFromFile.erase(0, 13);
                listOfFolders.createFolder(inputFromFile);
                //increment when new file added
                index++;
                }


                getline(readFile, inputFromFile);
                getline(readFile, inputFromFile);


                while(inputFromFile == "~_BEGIN NOTE_~"){
                    getline(readFile, inputFromFile);
                    if(inputFromFile.substr(0, 11) == "note_title:"){
                        inputFromFile.erase(0, 12);
                        nameOfNote = inputFromFile;
                    }


                    getline(readFile, inputFromFile, '~' );
                    if(inputFromFile.substr(0, 10) == "note_body:"){
                        inputFromFile.erase(0, 11);
                        noteBody = inputFromFile;
               
                    }
                    getline(readFile, inputFromFile);
                    if(inputFromFile.substr(0,20) == "note_last_edit_time:"){
                        inputFromFile.erase(0,21);
                        lastEditOfNote = inputFromFile;
                    }
                   
                   
                    listOfFolders.getFolder(index).createNote(nameOfNote, noteBody, lastEditOfNote);
                    getline(readFile, inputFromFile);
                    getline(readFile, inputFromFile);
                    getline(readFile, inputFromFile);
                }
            }
          }
        }


    else{
        cout<<"File was unable to open";
        return;
    }


    readFile.close();


}


void clearFileContents(const string& filename) {
    // Open the file in truncation mode to clear its contents
    ofstream clearFS(filename, ofstream::trunc);


    // Check if the file was opened successfully
    if (!clearFS.is_open()) {
        cerr << "Error: Failed to open file " << filename << "during clearing operation." << endl;
        return;
    }


    // Close the file
    clearFS.close();
}


void save(string& userName, string& infoFileName, FolderManager& listOfFolders) {


    clearFileContents(infoFileName); //clears file to prepare for writing or rewriting data


    ofstream writeFS;
    writeFS.open(infoFileName);


    // Check if the file stream failed to open
    if (!writeFS.is_open()) {
        cerr << "Error: Failed to open the file " << infoFileName << "." << endl;
        return; // Return an error code indicating failure
    }
   
    writeFS << "username: " << userName << endl << endl;


    for (unsigned i = 0; i < listOfFolders.getListOfFoldersSize(); ++i) {
       
        Folder currListOfNotes = listOfFolders.getFolder(i);
       
        writeFS << "folder_name: " << currListOfNotes.getFolderName() << endl;


        writeFS << endl << endl;
       
        for (unsigned j = 0; j < currListOfNotes.getFolderSize(); ++j) {
            Note currNote = currListOfNotes.getNote(j);


            writeFS << "~_BEGIN NOTE_~" << endl;
            writeFS << "note_title: " << currNote.getTitle() << endl;
            writeFS << "note_body: " << currNote.getBody() << endl;
            writeFS << "~note_last_edit_time: " << currNote.getLastEdit() << endl;
            writeFS << "~_END NOTE_~" << endl << endl;
        }


        writeFS << "*_END FOLDER_*" << endl << endl;
    }
   
    writeFS << "*_*END_OF_ALL_DATA*_*";
   
    // After operations, check if the file stream encountered any errors
    if (writeFS.fail()) {
        cerr << "Error: File stream encountered an error while reading." << endl;
        return; // Return an error code indicating failure
    }


    writeFS.close();


}
