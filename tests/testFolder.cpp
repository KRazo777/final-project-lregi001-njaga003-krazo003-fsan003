#include "../include/folder.h"
#include "../include/note.h"
#include "../include/folderManager.h"
#include "../include/runMenus.h"
#include "gtest/gtest.h"


// Tests should be written here
TEST(folderTests, testNoThrow) {
    EXPECT_NO_THROW( Folder("exampleFolder") );
}

TEST(folderTests, testConstructor){
    EXPECT_NO_THROW(Folder testFolder1);
}


// Initialize GTest
int mainTest(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(folderTests, testGetFolderName) {

    Folder myFolder1("camelCaseName");
    Folder myFolder2("superLongFolderNameLikeTheOneIAmWritingCurrently");
    Folder myFolder3("Folder Name with Spaces");

    // b/c getFolder returns a FOLDER object, must get it's name to test if they are equal 
    EXPECT_EQ(myFolder1.getFolderName(), "camelCaseName"); //tests camel case format
    EXPECT_EQ(myFolder2.getFolderName(), "superLongFolderNameLikeTheOneIAmWritingCurrently"); //test long folder name
    EXPECT_EQ(myFolder3.getFolderName(), "Folder Name with Spaces"); //test folder nmae w/ spaces
    
}

TEST(folderTests, testAddNotetoFolder) {
    Folder myFolder("myFolder1");
    Note myNote1("myNote1", "- myNoteContents", "03-14-2024 - 2:10:23");

    myFolder.AddNotetoFolder(myNote1);

    EXPECT_EQ(myNote1.getTitle(), myFolder.getNote(0).getTitle());
    EXPECT_EQ(myNote1.getBody(),  myFolder.getNote(0).getBody());
    EXPECT_EQ(myNote1.getLastEdit(), myFolder.getNote(0).getLastEdit());

    Note myNote2("myNote2", "- myNoteContents", "03-14-2024 - 2:10:30");

    myFolder.AddNotetoFolder(myNote2);

    EXPECT_EQ(myNote2.getTitle(), myFolder.getNote(1).getTitle());
    EXPECT_EQ(myNote2.getBody(),  myFolder.getNote(1).getBody());
    EXPECT_EQ(myNote2.getLastEdit(), myFolder.getNote(1).getLastEdit());

    
    Note myNote3("myNote3", "- myNoteContents", "03-14-2024 - 2:10:31");

    myFolder.AddNotetoFolder(myNote3);

    EXPECT_EQ(myNote3.getTitle(), myFolder.getNote(2).getTitle());
    EXPECT_EQ(myNote3.getBody(),  myFolder.getNote(2).getBody());
    EXPECT_EQ(myNote3.getLastEdit(), myFolder.getNote(2).getLastEdit());
}

TEST(folderTests, testCreateNote) {

    Folder myFolder("myFolder");

    Note myNote1("myNote1", "- myNoteContents", "03-14-2024 - 2:10:23");
    myFolder.createNote("myNote1", "- myNoteContents", "03-14-2024 - 2:10:23");

    EXPECT_EQ(myNote1.getTitle(), myFolder.getNote(0).getTitle());
    EXPECT_EQ(myNote1.getBody(),  myFolder.getNote(0).getBody());
    EXPECT_EQ(myNote1.getLastEdit(), myFolder.getNote(0).getLastEdit());
    
    Note myNote2("myNote2", "- myNoteContents", "03-14-2024 - 2:10:30");
    myFolder.createNote("myNote2", "- myNoteContents", "03-14-2024 - 2:10:30");

    EXPECT_EQ(myNote2.getTitle(), myFolder.getNote(1).getTitle());
    EXPECT_EQ(myNote2.getBody(),  myFolder.getNote(1).getBody());
    EXPECT_EQ(myNote2.getLastEdit(), myFolder.getNote(1).getLastEdit());

    Note myNote3("myNote3", "- myNoteContents", "03-14-2024 - 2:10:31");
    myFolder.createNote("myNote3", "- myNoteContents", "03-14-2024 - 2:10:31");

    EXPECT_EQ(myNote3.getTitle(), myFolder.getNote(2).getTitle());
    EXPECT_EQ(myNote3.getBody(),  myFolder.getNote(2).getBody());
    EXPECT_EQ(myNote3.getLastEdit(), myFolder.getNote(2).getLastEdit());
    
 }

 TEST(folderTests, testSetFolderName) {
    
    Folder myFolder1("myFolder1");
    myFolder1.setFolderName("notMyFolder1");

    EXPECT_EQ(myFolder1.getFolderName(), "notMyFolder1");

    Folder myFolder2("myFolder2");
    myFolder2.setFolderName("notMyFolder2");

    EXPECT_EQ(myFolder2.getFolderName(), "notMyFolder2");

    Folder myFolder3("myFolder3");
    myFolder3.setFolderName("notMyFolder3");

    EXPECT_EQ(myFolder3.getFolderName(), "notMyFolder3");
 }

TEST(folderTests, testGetNote) {
    Folder myFolder("myFolder");
    myFolder.createNote("myNote1", "- myNoteContents", "03-14-2024 - 2:10:23");
    myFolder.createNote("myNote2", "- myNoteContents", "03-14-2024 - 2:10:30");
    myFolder.createNote("myNote3", "- myNoteContents", "03-14-2024 - 2:10:31");
   
    Note myNote1 = myFolder.getNote(0);
    Note myNote2 = myFolder.getNote(1);
    Note myNote3 = myFolder.getNote(2);

    EXPECT_EQ(myNote1.getTitle(), myFolder.getNote(0).getTitle());
    EXPECT_EQ(myNote1.getBody(),  myFolder.getNote(0).getBody());
    EXPECT_EQ(myNote1.getLastEdit(), myFolder.getNote(0).getLastEdit());

    EXPECT_EQ(myNote2.getTitle(), myFolder.getNote(1).getTitle());
    EXPECT_EQ(myNote2.getBody(),  myFolder.getNote(1).getBody());
    EXPECT_EQ(myNote2.getLastEdit(), myFolder.getNote(1).getLastEdit());

    EXPECT_EQ(myNote3.getTitle(), myFolder.getNote(2).getTitle());
    EXPECT_EQ(myNote3.getBody(),  myFolder.getNote(2).getBody());
    EXPECT_EQ(myNote3.getLastEdit(), myFolder.getNote(2).getLastEdit());
}
 
TEST(folderTests, testDeleteNote) {
    Folder myFolder("myFolder");
    myFolder.createNote("myNote1", "- myNoteContents", "03-14-2024 - 2:10:23");
    myFolder.createNote("myNote2", "- myNoteContentsCheese", "03-14-2024 - 2:10:30");
    myFolder.createNote("myNote3", "- myNoteContentsChocolate", "03-14-2024 - 2:10:31");
    myFolder.createNote("myNote4", "- myNoteContentsBread", "03-14-2024 - 2:10:32");
    myFolder.createNote("myNote5", "- myNoteContentsSalami", "03-14-2024 - 2:10:33");
   
    //current notes list goes 1->2->3->4->5
    myFolder.deleteNote("myNote3"); //deletes myNote(3)
    // should now be 1->2->4->5 (index 2 should be myNote4)
    EXPECT_EQ(myFolder.getNote(2).getTitle(), "myNote4");

    //current notes list: 1->2->4->5
    myFolder.deleteNote("myNote1"); //deletes myNote1
    // should now be 2->4->5 (index 0 should be myNote2)
    EXPECT_EQ(myFolder.getNote(0).getTitle(), "myNote2");

    //current notes list: 2->4->5
    myFolder.deleteNote("myNote4"); //deletes myNote4
    // should now be 2->5 (index 1 should be myNote5)
    EXPECT_EQ(myFolder.getNote(1).getTitle(), "myNote5");

    //current notes list: 2->5
    myFolder.deleteNote("myNote2"); //deletes first note
    // should just be myNote5 (index 0 should be myNote5)
    EXPECT_EQ(myFolder.getNote(0).getTitle(), "myNote5");
}

TEST(folderTests, testPrintAllNoteTitles) { //if not empty

    Folder myFolder("myFolder");
    myFolder.createNote("myNote1", "- myNoteContents", "03-14-2024 - 2:10:23");
    myFolder.createNote("myNote2", "- myNoteContentsCheese", "03-14-2024 - 2:10:30");
    
    std::stringstream capturedOutput;
    std::streambuf* originalOutput = std::cout.rdbuf(capturedOutput.rdbuf());

    // Call the function that prints to cout
    myFolder.printAllNoteTitles();

    // Restore standard output
    std::cout.rdbuf(originalOutput);

    // Check if the captured output matches the expected output
    std::string expectedOutput = "myFolder:\n\n1. myNote1\n2. myNote2\n";
    EXPECT_EQ(capturedOutput.str(), expectedOutput);
}
   

TEST(folderTests, testPrintAllNoteTitlesEmpty) {
    
    Folder myFolder("myFolder");
    
    std::stringstream capturedOutput;
    std::streambuf* originalOutput = std::cout.rdbuf(capturedOutput.rdbuf());

    // Call the function that prints to cout
    myFolder.printAllNoteTitles();

    // Restore standard output
    std::cout.rdbuf(originalOutput);

    // Check if the captured output matches the expected output
    std::string expectedOutput = "myFolder:\nNo notes have been created";
    EXPECT_EQ(capturedOutput.str(), expectedOutput);
}

TEST(folderTests, testGetFolderSize) {
    Folder myFolder("myFolder");

    EXPECT_EQ(myFolder.getFolderSize(), 0);

    myFolder.createNote("myNote1", "- myNoteContents", "03-14-2024 - 2:10:23");
    
    EXPECT_EQ(myFolder.getFolderSize(), 1);

    myFolder.createNote("myNote2", "- myNoteContentsCheese", "03-14-2024 - 2:10:30");

    EXPECT_EQ(myFolder.getFolderSize(), 2);
}

TEST(folderTests, testEmpty) {
    Folder myFolder("myFolder");

    EXPECT_TRUE(myFolder.empty());

    myFolder.createNote("myNote1", "- myNoteContents", "03-14-2024 - 2:10:23");

    EXPECT_FALSE(myFolder.empty());

    myFolder.createNote("myNote2", "- myNoteContentsCheese", "03-14-2024 - 2:10:30");

    EXPECT_FALSE(myFolder.empty());
}

TEST(folderTests, updateNote) {
    Folder myFolder("myFolder");
    Note myNote1("myNote1", "- myNoteContents", "03-14-2024 - 2:10:23");
    
    myFolder.createNote("myNote1", "- myNoteContents", "03-14-2024 - 2:10:23");
    myFolder.updateNote(0, myNote1);

    EXPECT_EQ(myNote1.getTitle(), myFolder.getNote(0).getTitle());
    EXPECT_EQ(myNote1.getBody(),  myFolder.getNote(0).getBody());
    EXPECT_EQ(myNote1.getLastEdit(), myFolder.getNote(0).getLastEdit());

    Note myNote2("myNote2", "- myNoteContentsCheese", "03-14-2024 - 2:10:30");
    
    myFolder.createNote("myNote2", "- myNoteContentsCheese", "03-14-2024 - 2:10:30");
    myFolder.updateNote(1, myNote2);

    EXPECT_EQ(myNote2.getTitle(), myFolder.getNote(1).getTitle());
    EXPECT_EQ(myNote2.getBody(),  myFolder.getNote(1).getBody());
    EXPECT_EQ(myNote2.getLastEdit(), myFolder.getNote(1).getLastEdit());
    
    Note myNote3("myNote3", "- myNoteContents", "03-14-2024 - 2:10:31");

    myFolder.createNote("myNote3", "- myNoteContents", "03-14-2024 - 2:10:31");
    myFolder.updateNote(2, myNote3);

    EXPECT_EQ(myNote3.getTitle(), myFolder.getNote(2).getTitle());
    EXPECT_EQ(myNote3.getBody(),  myFolder.getNote(2).getBody());
    EXPECT_EQ(myNote3.getLastEdit(), myFolder.getNote(2).getLastEdit());
}