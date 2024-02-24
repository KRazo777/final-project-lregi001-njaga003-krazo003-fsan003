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
    return ""; //fix this, just had to add this so complier stopped complaining 
}; 

string Note::getBody(){
    return ""; //fix this, just had to add this so complier stopped complaining
}; 

string Note::getLastEdit(){
    return ""; //fix this, just had to add this so complier stopped complaining
};

void Note::renameTitle(){};