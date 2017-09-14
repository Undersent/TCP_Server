//
// Created by rafal on 14.09.17.
//

#include "SpellCorrector.h"



void SpellCorrector::readFileIntoTST(TST::TernarySearchTree &tst) {
    std::string line;
    std::string word;
    _tst = std::shared_ptr<TST::TernarySearchTree>(&tst);
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


size_t SpellCorrector::getLevenshteinDistance(const std::string &s1, const std::string &s2) {
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

void SpellCorrector::traverse(const std::shared_ptr<TST::TernarySearchTree::Node> &root, std::string str) {
    if(root == nullptr) {
        return;
    }
    size_t editDistance = getLevenshteinDistance(_inputString, str + (root->_data));
    //if distance is greater than our limit we can skip traversing this nodes <- power of tree
    if((str.length() < _inputString.length()) &&
            getLevenshteinDistance(str, _inputString.substr(0, str.length() + 1)) > _EDIT_DISTANCE_LIMIT){
        return;
    } else if (str.length() > _inputString.length() + _EDIT_DISTANCE_LIMIT) {
        return;
    }else if (abs(str.length() - _inputString.length()) <= _EDIT_DISTANCE_LIMIT &&
            editDistance > _EDIT_DISTANCE_LIMIT){
        return;
    }

    //use recursion to traverse the nodes to obtain words
    traverse(root->_left, str);
    if (root->_isEnd) {
        if(editDistance < _EDIT_DISTANCE_LIMIT) {
            Word word;
            word.text = str+(root->_data);
            word.editDistance = editDistance;
            word.value = root->_frequency;
            _wordsPQ->push(word);
        }
    }
    traverse(root->_equal, str+(root->_data));
    traverse(root->_right, str);
}

std::shared_ptr<std::priority_queue<SpellCorrector::Word>> SpellCorrector::correctWord(std::string &strToCompare) {
    //std::shared_ptr<std::map<std::string, int>> map = std::make_shared(std::map<std::string, int>());
    _wordsPQ = std::make_shared<std::priority_queue<Word>>(std::priority_queue<Word>());
    if(strToCompare.empty()) {
        //TODO throw exception??????
    }
    _inputString = strToCompare;
    traverse(_tst->getRoot(), "");

    return _wordsPQ;
}

void SpellCorrector::setInputString(const std::string &inputString) {
    SpellCorrector::_inputString = inputString;
}

const std::shared_ptr<std::priority_queue<SpellCorrector::Word>> &SpellCorrector::getWordsPQ() const {
    return _wordsPQ;
}


