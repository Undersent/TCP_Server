//
// Created by rafal on 12.09.17.
//
#include "gtest/gtest.h"
#include "../../AlgAndDataStructures/TernarySearchTree.h"
#include "../../AlgAndDataStructures/TernarySearchTree.cpp"
#include "../../AlgAndDataStructures/TextTools.h"

namespace TST {
    class TSTTest : public ::testing::Test {

    };

    TEST_F(TSTTest, CreatingClass) {
        TST::TernarySearchTree tst;
        //ASSERT_EQ(rsa.GCD(36, 31752),36);
        //ASSERT_EQ(rsa.GCD(37, 31752),1);
    }

    TEST_F(TSTTest, insertElement) {
        TST::TernarySearchTree tst;
        tst.insert("cat","123");
        tst.insert("dog", "123");
        tst.insert("cattable", "421");
        ASSERT_EQ(tst.getRoot()->_data,'c');
        ASSERT_EQ(tst.getRoot()->_equal->_equal->_data,'t');
        ASSERT_EQ(tst.getRoot()->_right->_data,'d');
        ASSERT_EQ(tst.getRoot()->_right->_equal->_data,'o');
        ASSERT_EQ(tst.getRoot()->_right->_equal->_equal->_data,'g');

    }

    TEST_F(TSTTest, traverseTest) {
        TST::TernarySearchTree tst;
        tst.insert("cat","123");
        tst.insert("dog", "123");
        tst.insert("cattable", "421");
        char buffer[50];

        tst.traverseTSTUtil(tst.getRoot(),buffer);

    }

    TEST_F(TSTTest, getLevenshteinDistanceTest) {
        ASSERT_EQ(TSTTools::getLevensthienDistance("raiseyourhands", "raiseyouhands"),1);
        ASSERT_EQ(TSTTools::getLevensthienDistance("abc", "acc"),1);
        ASSERT_EQ(TSTTools::getLevensthienDistance("abc", "ac"),1);

    }
}