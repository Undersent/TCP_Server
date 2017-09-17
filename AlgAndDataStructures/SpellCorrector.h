//
// Created by rafal on 14.09.17.
//

#ifndef PROJECT_SPELLCORRECTOR_H
#define PROJECT_SPELLCORRECTOR_H


#include "TernarySearchTree.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <queue>

class SpellCorrector {
public:
    struct Word {
        std::string text;
        std::string value;
        size_t editDistance;

        bool operator<(const Word &rhs) const {
            if (editDistance > rhs.editDistance) {
                return true;
            } else if (editDistance < rhs.editDistance) {
                return false;
            } else {
                return compareByValue(rhs);
            }
        }

        bool compareByValue(const Word &rhs) const {
            auto it = value.begin();
            auto it2 = rhs.value.begin();
            for (; it != value.end(), it2 != rhs.value.end(); it++, it2++) {
                if ((*it - '0') < (*it2 - '0')) {
                    return false;
                }
            }
        }
    };

    std::string _inputString{};
    const unsigned int _EDIT_DISTANCE_LIMIT = 3;
    std::unique_ptr<TernarySearchTree> _tst;
    std::unique_ptr<std::priority_queue<Word>> _wordsPQ;

public:


    SpellCorrector();

    void readFileIntoTST();

    size_t computeLevenshteinDistance(const std::string &s1, const std::string &s2) const;

    void traverse(const std::unique_ptr<TernarySearchTree::Node> &root, const std::string str) const;

    std::unique_ptr<std::priority_queue<Word>> &correctWord(const std::string &strToCompare);

    void setInputString(const std::string &inputString);

    std::unique_ptr<std::priority_queue<Word>> &getWordsPQ();


};


#endif //PROJECT_SPELLCORRECTOR_H
