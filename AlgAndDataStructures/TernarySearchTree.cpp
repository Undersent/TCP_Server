//
// Created by rafal on 12.09.17.
//

#include <iostream>
#include "TernarySearchTree.h"
namespace TST {

    std::unique_ptr<TernarySearchTree::Node> TernarySearchTree::getRoot() {
        return std::move(_root);
    }

    void TernarySearchTree::setRoot(std::unique_ptr<Node> node) {
        _root = std::move(node);
    }

    void TernarySearchTree::insert(std::string word, unsigned int frequency) {
        _root = insert(std::move(_root), word, frequency, 0);
    }

    std::unique_ptr<TernarySearchTree::Node>
    TernarySearchTree::insert(std::unique_ptr<TernarySearchTree::Node> node,
                              std::string word, unsigned int frequency, unsigned int pos) {
        if (node == nullptr) {
            if (word.length() <= pos) {
                return std::move(node);
            }

            node = std::make_unique<TernarySearchTree::Node>(TernarySearchTree::Node(word.at(pos)));
            if (pos + 1 == word.length()) {
                node->_isEnd = true;
                node->_frequency = frequency;
                return std::move(node);
            }
        }
        if(word.at(pos) < node->_data){
            node->_left = insert(std::move(node->_left), word, frequency, pos);
        } else if (word.at(pos) > node->_data) {
            node->_right = insert(std::move(node->_right), word, frequency, pos);
        }else{
            if (pos + 1 < word.length()) {
                node->_equal = insert(std::move(node->_equal), word, frequency, pos+1);
            } else {
                // end of the word
                node->_isEnd = true;
                node-> _frequency = frequency;
            }
        }
        return std::move(node);
    }

    bool TernarySearchTree::search(std::unique_ptr<TernarySearchTree::Node> node, std::string word, unsigned int pos) const {
        while (node != nullptr) {
            if (word.at(pos) < node->_data) {
                node = std::move(node->_left);
            } else if (word.at(pos) > node->_data) {
                node = std::move(node->_right);
            } else{
                if (node->_isEnd && pos == word.length() - 1) {
                    return true;
                }
                pos++;
                node = std::move(node->_equal);
            }
        }
        return false;
    }
}