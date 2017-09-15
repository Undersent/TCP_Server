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
    struct Word{
        std::string text;
        std::string value;
        size_t editDistance;
        bool operator<(const Word& rhs) const
        {
            if(editDistance > rhs.editDistance){
                return true;
            }
            else if (editDistance < rhs.editDistance) {
                return false;
            }else{
                return compareByValue(rhs);
            }
        }
        bool compareByValue(const Word& rhs) const
        {
            auto it = value.begin();
            auto it2 = rhs.value.begin();
            for( ; it != value.end(), it2 != rhs.value.end(); it++, it2++){
                if((*it - '0') < (*it2 - '0')){
                    return false;
                }
            }
        }
    };
    std::string _inputString{};
    const unsigned int _EDIT_DISTANCE_LIMIT = 3;
    std::shared_ptr<TST::TernarySearchTree> _tst;
    std::shared_ptr<std::priority_queue<Word>> _wordsPQ;
public:


    explicit SpellCorrector();

    void readFileIntoTST();

    size_t getLevenshteinDistance(const std::string &s1, const std::string &s2);

    void traverse(const std::shared_ptr<TST::TernarySearchTree::Node> &root, std::string str);

    std::shared_ptr<std::priority_queue<Word>> correctWord(std::string& strToCompare);

    void setInputString(const std::string &inputString);

    const std::shared_ptr<std::priority_queue<Word>> &getWordsPQ() const;


};




#endif //PROJECT_SPELLCORRECTOR_H
