//
// Created by rafal on 12.09.17.
//

#include <iostream>
#include "TernarySearchTree.h"


    //std::shared_ptr<TernarySearchTree::Node> TernarySearchTree::getRoot() {
    //    return (_root);
    //}

    const std::unique_ptr<TernarySearchTree::Node> &TernarySearchTree::getRoot() const {
        return _root;
    }

    void TernarySearchTree::setRoot(Node node) {
        _root = std::make_unique<Node>(std::move(node));
    }

    void TernarySearchTree::insert(const std::string& word, const  std::string& frequency) {
        _root = insert((_root), word, frequency, 0);
    }

    std::unique_ptr<TernarySearchTree::Node>
    TernarySearchTree::insert(std::unique_ptr<TernarySearchTree::Node> &node,
                              const std::string &word,const  std::string& frequency,const unsigned int pos) {
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
        return std::move(node);
    }

    bool TernarySearchTree::search(std::unique_ptr<TernarySearchTree::Node> node,
                                   const std::string &word, unsigned int pos) const {
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

    void TernarySearchTree::traverseTSTUtil(const std::unique_ptr<TernarySearchTree::Node>& root,
                                            char* buffer,const unsigned int depth) {
        if(root){
            traverseTSTUtil(root->_left, buffer, depth);
            buffer[depth] = root->_data;
            if (root->_isEnd) {
                buffer[depth+1] = '\0';
            }

            // Traverse the subtree using equal pointer (middle subtree)
            traverseTSTUtil(root->_equal, buffer, depth + 1);

            // Finally Traverse the right subtree
            traverseTSTUtil(root->_right, buffer, depth);
        }



    }




