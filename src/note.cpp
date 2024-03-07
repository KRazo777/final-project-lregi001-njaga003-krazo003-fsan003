#include "../include/note.h"
#include <iostream>
#include <chrono>
#include <iomanip>

//using namespace std::chrono;

//default constructor
Note::Note(): title("Untitled Note"), body("Insert Note Content Here"), lastEdit("0") {};

Note::Note(string titleName, string bodyText, string lastEditText): title(titleName), body(bodyText), lastEdit(lastEditText) {};

Note::~Note(){};

string Note::getTitle(){
    return title; 
}; 

string Note::getBody(){
    return body; 
}; 

string Note::getLastEdit(){
    return lastEdit;
};

void Note::setLastEdit(){
    const auto now = std::chrono::system_clock::now();
    std::time_t edit_time = std::chrono::system_clock::to_time_t(now);
    lastEdit = std::ctime(&edit_time);
    //fix this, just had to add this so complier stopped complaining
};

void Note::renameTitle(const string& newName){
    title = newName;
    setLastEdit();
};

void Note::printNote() { //output Note contents

    cout << setw(99) << setfill('-') << '-' << endl;
    cout << setw(0) << "Title: " << this->getTitle() << setw(43) << setfill(' ')<< "Last Edit: " << this->getLastEdit() << endl;
    cout << setw(99) << setfill('-') << '-' << endl;
    
    cout << this->getBody() << endl;

    // cout << this->getTitle() << endl << endl;
    // cout << this->getBody() << endl << endl;
    // cout << "Last edited: " << this->getLastEdit() << endl << endl;
}

int Note::writeNoteToFile() { //THIS FUNCTION MAY BE DELETED IN THE FUTURE with some of this code being utilized in a "save" function
    ofstream writeFS;
    writeFS.open("ListOfAllNotes.txt");

    // Check if the file stream failed to open
    if (!writeFS.is_open()) {
        cerr << "Error: Failed to open the file ListOfAllNotes.txt" << endl;
        return 1; // Return an error code indicating failure
    }
   
    writeFS << "~BEGIN NOTE" << endl;
    writeFS << "note_title: " << this->getTitle() << endl;
    writeFS << "note_lastEditTime: " << this->getLastEdit() << endl;
    writeFS << "note_body: " << this->getBody() << endl;
    writeFS << "~END NOTE" << endl << endl;
   
    // After operations, check if the file stream encountered any errors
    if (writeFS.fail()) {
        cerr << "Error: File stream encountered an error while reading." << endl;
        return 1; // Return an error code indicating failure
    }

    writeFS.close();
    setLastEdit();

    return 0;
}