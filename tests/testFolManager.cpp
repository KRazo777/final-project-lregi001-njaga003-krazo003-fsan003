#include "../include/folder.h"
#include "../include/note.h"
#include "../include/folderManager.h"
#include "../include/runMenus.h"
#include "gtest/gtest.h"

// folderMenu tests should be written here
// Tests should be written here
TEST(folderManagerTests, testNoThrow) {
    EXPECT_NO_THROW( FolderManager example() );
}

// Initialize GTest
int mainTest2(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
