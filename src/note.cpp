#include "../include/note.h"
#include <iostream>
#include <chrono>


//using namespace std::chrono;



//default constructor
Note::Note(){};


Note::Note(string titleName, string bodyText, string lastEditText): 
title(titleName), 
body(bodyText),
lastEdit(lastEditText)
{};


Note::~Note(){};


string Note::getTitle(){


    return ""; //fix this, just had to add this so complier stopped complaining
};


string Note::getBody(){
    return ""; //fix this, just had to add this so complier stopped complaining
};


void Note::setLastEdit(){
    const auto now = std::chrono::system_clock::now();
    std::time_t edit_time = std::chrono::system_clock::to_time_t(now);
    lastEdit = std::ctime(&edit_time);
    //fix this, just had to add this so complier stopped complaining
};


string Note::getLastEdit(){
    return lastEdit;
    //fix this, just had to add this so complier stopped complaining
};




void Note::renameTitle(const string& newName){
    title = newName;
    setLastEdit();
};


int Note::outputNote() {} //relies on opening "ListOfAllNotes.txt" and reading the note from it


int Note::writeNoteToFile() {
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