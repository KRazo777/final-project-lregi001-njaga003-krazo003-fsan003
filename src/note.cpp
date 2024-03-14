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

void Note::setTitle(const string& newTitle) {
    this->title = newTitle;
}

void Note::setBody(const string& newBody) {
    this->body = newBody;
}

void Note::setLastEdit(){
    const auto now = std::chrono::system_clock::now();
    std::time_t edit_time = std::chrono::system_clock::to_time_t(now);
    lastEdit = std::ctime(&edit_time);
    //fix this, just had to add this so complier stopped complaining
};

void Note::printNote() { //output Note contents

    cout << setw(99) << setfill('-') << '-' << endl;
    cout << setw(0) << "Title: " << this->getTitle() << setw(43) << setfill(' ')<< "Last Edit: " << this->getLastEdit() << endl;
    cout << setw(99) << setfill('-') << '-' << endl;
    
    cout << this->getBody() << endl;
}