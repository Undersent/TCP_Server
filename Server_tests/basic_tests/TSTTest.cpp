//
// Created by rafal on 12.09.17.
//
#include <gtest/gtest.h>
#include "gtest/gtest.h"
#include "../../AlgAndDataStructures/TernarySearchTree.h"
#include "../../AlgAndDataStructures/TernarySearchTree.cpp"
#include "../../src/messages/MessageClient.h"


namespace TST {
    class TSTTest : public ::testing::Test {
    public:
        TernarySearchTree tst{};
        TSTTest() = default;
        virtual ~TSTTest()  = default;

        void SetUp() override{
        }

        void TearDown() override{
        }
    };


    TEST_F(TSTTest, insertElement) {
        std::string cat = "cat";
        std::string number123 = "123";
        std::string dog = "dog";
        std::string number421 = "421";
        std::string cattable = "cattable";

        tst.insert(cat,number123);
        tst.insert(dog, number123);
        tst.insert(cattable, number421);
        ASSERT_EQ(tst.getRoot()->_data,'c');
        ASSERT_EQ(tst.getRoot()->_equal->_equal->_data,'t');
        ASSERT_EQ(tst.getRoot()->_right->_data,'d');
        ASSERT_EQ(tst.getRoot()->_right->_equal->_data,'o');
        ASSERT_EQ(tst.getRoot()->_right->_equal->_equal->_data,'g');

    }

    TEST_F(TSTTest, traverseTest) {
        std::string cat = "cat";
        std::string number123 = "123";
        std::string dog = "dog";
        std::string number421 = "421";
        std::string cattable = "cattable";

        tst.insert(cat,number123);
        tst.insert(dog, number123);
        tst.insert(cattable, number421);
        char buffer[50];

        tst.traverseTSTUtil(tst.getRoot(),buffer);

    }


}