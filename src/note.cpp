#include "../include/note.h"

//default constructor
Note::Note(){};

Note::Note(string titleName, string bodyText, string lastEditText): 
title(titleName), 
body(bodyText),
lastEdit(lastEditText)
{};

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

void Note::renameTitle(){}; //FIXME: implement

void Note::printNote() { //output Note contents)
    cout << this->getTitle() << endl << endl;
    cout << this->getBody() << endl << endl;
    cout << "Last edited: " << this->getLastEdit() << endl << endl;
}

int Note::writeNoteToFile() { //REMOVE WHEN SAVE FUNCTION IS IMPLEMENTED
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

    return 0;
}