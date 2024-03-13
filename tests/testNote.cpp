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
