//
// Created by rafal on 12.09.17.
//

#include <iostream>
#include "TernarySearchTree.h"
namespace TST {

    std::shared_ptr<TernarySearchTree::Node> TernarySearchTree::getRoot() {
        return (_root);
    }

    void TernarySearchTree::setRoot(std::shared_ptr<Node> node) {
        _root = (node);
    }

    void TernarySearchTree::insert(std::string word, unsigned int frequency) {
        _root = insert((_root), word, frequency, 0);
    }

    std::shared_ptr<TernarySearchTree::Node>
    TernarySearchTree::insert(std::shared_ptr<TernarySearchTree::Node> node,
                              std::string word, unsigned int frequency, unsigned int pos) {
        if (node == nullptr) {
            if (word.length() <= pos) {
                return (node);
            }

            node = std::make_unique<TernarySearchTree::Node>(TernarySearchTree::Node(word.at(pos)));
            if (pos + 1 == word.length()) {
                node->_isEnd = true;
                node->_frequency = frequency;
                return (node);
            }
        }
        if(word.at(pos) < node->_data){
            node->_left = insert((node->_left), word, frequency, pos);
        } else if (word.at(pos) > node->_data) {
            node->_right = insert((node->_right), word, frequency, pos);
        }else{
            if (pos + 1 < word.length()) {
                node->_equal = insert((node->_equal), word, frequency, pos+1);
            } else {
                // end of the word
                node->_isEnd = true;
                node-> _frequency = frequency;
            }
        }
        return (node);
    }

    bool TernarySearchTree::search(std::shared_ptr<TernarySearchTree::Node> node, std::string word, unsigned int pos) const {
        while (node != nullptr) {
            if (word.at(pos) < node->_data) {
                node = (node->_left);
            } else if (word.at(pos) > node->_data) {
                node = (node->_right);
            } else{
                if (node->_isEnd && pos == word.length() - 1) {
                    return true;
                }
                pos++;
                node = (node->_equal);
            }
        }
        return false;
    }
}