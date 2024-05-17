#include "pch.h"
#include "../Build/Initialise.h"

//Checking build settings

class GameTests : public testing::Test {
protected:
    static void SetUpTestSuite() {
        //This is can be called before a test is run. 
    }

    static void TearDownTestSuite() {
        //This is can be called after a test is run. 
    }

public:
    // You can remove any or all of the following functions if their bodies would
    // be empty.
    GameTests() = default;
    ~GameTests() override = default;
   


    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
        
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).

    }

    // Class members declared here can be used by all tests in the test suite.
    //bool uniterestingTest(int a, int b) {
    //    if (std::abs(a - b) < 10) {
    //        return true;
    //    }
    //    else {
    //        return false;
    //    }
    //}
};


//Basic test
TEST(Test, TestName) {
    EXPECT_EQ(1, 2);
    EXPECT_GT(2, 1);
 }

//Test with just expect so should run through.
TEST(TestCaseName, TestName) {
    std::cout << "Running....." << std::endl;
    EXPECT_EQ(1, 1);
    std::cout << "Tests" << std::endl;
    EXPECT_TRUE(false);
}

//Test with assert so stops.
TEST(TestCaseName1, TestName) {
    std::cout << "Starting....." << std::endl;
    ASSERT_EQ(2, 1);
    std::cout << "Stopping....." << std::endl;
    EXPECT_TRUE(true);
    std::cout << "Finished....." << std::endl;
}
