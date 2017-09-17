//
// Created by rafal on 14.09.17.
//

#include <zconf.h>
#include <sys/param.h>
#include "SpellCorrector.h"

SpellCorrector::SpellCorrector() {
    _tst = std::make_unique<TernarySearchTree>(TernarySearchTree{});
}

void SpellCorrector::readFileIntoTST() {
    std::string line{};
    std::string word{};
    //TODO RELATIVE PATH
    //std::ifstream file("../words.txt");
    //home/rafal/CLionProjects/TCP_Server/cmake-build-debug/src/network/TCP_Server
    std::ifstream file("/home/rafal/CLionProjects/TCP_Server/AlgAndDataStructures/words.txt");
    if (file.is_open()) {
        std::string tokens[2];
        unsigned int i{};
        while (getline(file, line, '\t')) {
            if (i == 2) {
                _tst->insert(tokens[0], tokens[1]);
                i = 0;
            }
            tokens[i] = line;
            i++;
        }
        file.close();
    } else std::cerr << "Unable to open file";
}


size_t SpellCorrector::computeLevenshteinDistance(const std::string &s1, const std::string &s2) const {
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

void SpellCorrector::traverse(const std::unique_ptr<TernarySearchTree::Node> &root, const std::string str) const {
    if (root == nullptr) {
        return;
    }
    size_t editDistance = computeLevenshteinDistance(_inputString, str + (root->_data));
    //if distance is greater than our limit we can skip traversing this nodes <- power of tree
    if ((str.length() < _inputString.length()) &&
        computeLevenshteinDistance(str, _inputString.substr(0, str.length() + 1)) > _EDIT_DISTANCE_LIMIT) {
        return;
    } else if (str.length() > _inputString.length() + _EDIT_DISTANCE_LIMIT) {
        return;
    } else if (abs(str.length() - _inputString.length()) <= _EDIT_DISTANCE_LIMIT &&
               editDistance > _EDIT_DISTANCE_LIMIT) {
        return;
    }

    //use recursion to traverse the nodes to obtain words
    traverse(root->_left, str);
    if (root->_isEnd) {
        if (editDistance < _EDIT_DISTANCE_LIMIT) {
            Word word{str + (root->_data), root->_frequency, editDistance};
            _wordsPQ->push(word);
        }
    }
    traverse(root->_equal, str + (root->_data));
    traverse(root->_right, str);
}

std::unique_ptr<std::priority_queue<SpellCorrector::Word>> &
SpellCorrector::correctWord(const std::string &strToCompare) {
    _wordsPQ = std::make_unique<std::priority_queue<Word>>(std::priority_queue<Word>{});

    if (strToCompare.empty()) {
        throw std::invalid_argument("received empty string");
    }
    _inputString = strToCompare;
    traverse(_tst->getRoot(), "");

    return _wordsPQ;
}

void SpellCorrector::setInputString(const std::string &inputString) {
    SpellCorrector::_inputString = inputString;
}

std::unique_ptr<std::priority_queue<SpellCorrector::Word>> &SpellCorrector::getWordsPQ() {
    return _wordsPQ;
}





