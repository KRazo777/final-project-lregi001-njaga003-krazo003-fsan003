#include "../include/folder.h"
#include "../include/note.h"
#include "../include/folderManager.h"
#include "../include/runMenus.h"
#include "gtest/gtest.h"


// Note tests should be written here
TEST(noteTests, testNoThrow) {
    EXPECT_NO_THROW( Note(
    "ExampleNoteTitle", 
    "This is the body of my note\n This is the second line. \n This is the third line", 
    "0") );
}

// Initialize GTest
int mainTest3(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(noteTests, testThatNoteEdit) {
    Note newNote("nameOfNote", "", "0");
    newNote.setLastEdit();
    EXPECT_FALSE(newNote.getLastEdit() == "0");
}

TEST(noteTests, testSetLastEdit1){
    Note testingNote;
    EXPECT_NO_THROW(testingNote.setLastEdit());
}

TEST(noteTests, testSetLastEdit2){
    Note testingNote;
    testingNote.setLastEdit();
    cout<<testingNote.getLastEdit();
    //check date and time in tests
    ASSERT_NO_THROW(testingNote.getLastEdit());

}

TEST(noteTests, testSetLastEdit3){
    //with defined constructor
    Note testingNote("note", "body", "0");
    testingNote.setLastEdit();
    cout<<testingNote.getLastEdit();
    //check date and time in tests
    ASSERT_NO_THROW(testingNote.getLastEdit());
}

TEST(noteTests, testSetBody){
    Note testingNote("note", "this is the body", "0");
    EXPECT_NO_THROW(testingNote.setBody("changed body"));
}

TEST(noteTests, testSetBodyChange){
    Note testingNote("note", "this is the body", "0");
    testingNote.setBody("changed body");
    EXPECT_EQ("changed body", testingNote.getBody());
}

TEST(noteTests, testSetBodyToNothing){
    Note testingNote("note", "this is the body", "0");
    testingNote.setBody("");
    EXPECT_EQ("", testingNote.getBody());
}

TEST(noteTests, setTitle){
    //case 1
    Note testingNote1("note", "this is the body", "0");
    EXPECT_NO_THROW(testingNote1.setTitle("changed title"));

    //case 2
    Note testingNote2("note", "this is the body", "0");
    testingNote2.setTitle("changed title");
    EXPECT_EQ("changed title", testingNote2.getTitle());

    //case 3 (using default constructor)
    Note testingNote3;
    testingNote3.setTitle("note");
    EXPECT_EQ("note", testingNote3.getTitle());

}









