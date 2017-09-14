//
// Created by rafal on 13.09.17.
//
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "TernarySearchTree.h"
#include <cstdlib>
/*
namespace TSTTools{
    std::string fileName{"../AlgAndDataStructures/google-books-common-words.txt"};

    void readFileIntoTST(TST::TernarySearchTree& tst){
        std::string line;
        std::string word;
        //TODO RELATIVE PATH
        //std::ifstream file("/home/rafal/CLionProjects/TCP_Server/AlgAndDataStructures/common-words.txt");
        std::ifstream file("/home/rafal/CLionProjects/TCP_Server/AlgAndDataStructures/words.txt");
         if (file.is_open())
         {
             std::string tokens[2];
             unsigned int i{};
             while (getline(file, line, '\t')) {
                 if(i == 2){
                     tst.insert(tokens[0],tokens[1]);
                     i=0;
                 }
                 tokens[i] = line;
                 i++;
             }
             file.close();
         }
         else std::cerr << "Unable to open file";
    }

    size_t getLevensthienDistance(const std::string &s1, const std::string &s2) {
        const size_t m(s1.size());
        const size_t n(s2.size());

        if (m == 0) return n;
        if (n == 0) return m;

        auto *costs = new size_t[n + 1];

        for (size_t k = 0; k <= n; k++) costs[k] = k;

        size_t i = 0;
        //create "matrix" and then count "smallest route" in this matrix
        for (auto it1 = s1.begin(); it1 != s1.end(); ++it1, ++i) {
            costs[0] = i + 1;
            size_t corner = i;

            size_t j = 0;
            for (auto it2 = s2.begin(); it2 != s2.end(); ++it2, ++j) {
                size_t upper = costs[j + 1];
                if (*it1 == *it2) {
                    costs[j + 1] = corner;
                } else {
                    size_t t(upper < corner ? upper : corner);
                    costs[j + 1] = (costs[j] < t ? costs[j] : t) + 1;
                }

                corner = upper;
            }
        }
        size_t result = costs[n];
        delete[] costs;

        return result;
    }


    //input string-string to compare with.
    //TODO: MAKE THIS CODE A CLASS
    void TST::traverse(std::shared_ptr<TernarySearchTree::Node> &root, std::string str) {std::string inputString;
        if(root = nullptr) {
            return;
        }
        size_t editDistance = TSTTools::getLevensthienDistance(inputString, str+root->_data);
        //if distance is greater than our limit we can skip traversing this nodes <- power of tree
        if((str.length() < inputString.length()) &&
                TSTTools::getLevensthienDistance(str,inputString.substr(0,str.length()+1)) > EDIT_DISTANCE_LIMIT){
            return;
        } else if (str.length() > inputString.length() + EDIT_DISTANCE_LIMIT) {
            return;
        }else if (abs(str.length() - inputString.length()) <= EDIT_DISTANCE_LIMIT &&
                dis > EDIT_DISTANCE_LIMIT){
            return;
        }

        //use recursion to traverse the nodes to obtain words
        traverse(root->_left, str);
        if (root->_isEnd) {
            if(dis< EDIT_DISTANCE_LIMIT) {
                //TODO: add words to some container   words.insert((str+root.getData(), dis, root.getFrequency())
            }
        }
        traverse(root->_equal, str+root->_data);
        traverse(root->_right, str);
    }


}
*/

