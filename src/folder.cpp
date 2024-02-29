#include "../include/folder.h"

Folder::Folder(const string& name): folderName(name) {};
Folder::~Folder(){};


void Folder::createNote(const string& name){};
void Folder::deleteNote(const string& name){};
void Folder::addContentToNote(const string& noteName){};
void Folder::printNote(const string& name)
{
    unsigned notePos = 0;

    for (notePos = 0; notePos < notes.size(); notePos++) // Locate note to be displayed in the note vector
    {
        if (notes.at(notePos).getTitle() == name) // Note with matching title found
        {
            break;
        }
    }

    // Now print out note to terminal for viewing

    cout << setw(99) << setfill('-') << '-' << endl;
    cout << setw(0) << "Title: " << notes.at(notePos).getTitle() << "     Last Edit: " << notes.at(notePos).getLastEdit() << endl;
    cout << setw(50) << setfill('-') << "BODY";
    cout << setw(49) << setfill('-') << "-" << endl;
    
    cout << notes.at(notePos).getBody() << endl;
};

bool Folder::noteExists(const string& name){
    return false; //fix this, just had to add this so complier stopped complaining
};


void Folder::setFolderName(const string& name){
    folderName = name;

}
const string& Folder::getFolderName(){
    return folderName;
};

