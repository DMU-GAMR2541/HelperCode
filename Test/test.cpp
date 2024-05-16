##include "pch.h"
#include "../Build/Initialise.h"


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
    sf::Vector2i v2_testOne = sf::Vector2i(0, 0);
    sf::Vector2i v2_testTwo = sf::Vector2i(10, 10);
    Player playerOne;
    Player playerTwo;


    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
        playerOne.setPosition(v2_testOne);
        playerTwo.setPosition(v2_testTwo);
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).

    }

    // Class members declared here can be used by all tests
    void setVector(sf::vector2f v2_set) {
        v2_testOne = v2_set;
    }
};

TEST_F(GameTests, collision) {
    std::cout << "Player one x = " << playerOne.getPosition().x << " " << "Player two = " << playerTwo.getPosition().x << std::endl
        EXPECT_EQ(playerOne.getPosition().x, playerTwo.getPosition().x);
}

TEST(TestCaseName, TestName) {
    std::cout << "Running....." << std::endl;
    EXPECT_EQ(1, 1);
    std::cout << "Tests" << std::endl;
    EXPECT_TRUE(false);
}

TEST(TestCaseName1, TestName) {
    std::cout << "Starting....." << std::endl;
    ASSERT_EQ(2, 1);
    std::cout << "Stopping....." << std::endl;
    EXPECT_TRUE(true);
    std::cout << "Finished....." << std::endl;
}

