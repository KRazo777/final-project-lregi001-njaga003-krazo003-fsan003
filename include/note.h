#ifndef __NOTE_H__
#define __NOTE_H__

#include <string>
#include <fstream>
using namespace std;

class Note {
    private:
        string title;
        string body;
        string lastEdit; // date - time (03-06-2024 - 12:36:23)

    public:
        Note();
        Note(string titleName, string body, string lastEdit);
        ~Note();

        string getTitle(); 
        string getBody(); 
        string getLastEdit();
        void renameTitle();
        void printNote();
        int writeNoteToFile();
};

#endif 