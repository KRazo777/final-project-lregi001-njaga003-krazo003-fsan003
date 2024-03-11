#include "../include/folder.h"
#include "../include/note.h"
#include "../include/folderManager.h"
#include "../include/runMenus.h"
#include "gtest/gtest.h"

// Tests should be written here
TEST(folderTests, testNoThrow) {
    EXPECT_NO_THROW( Folder("exampleFolder") );
}

// Initialize GTest
int mainTest(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
