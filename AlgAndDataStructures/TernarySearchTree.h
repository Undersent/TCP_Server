//
// Created by rafal on 12.09.17.
//

#ifndef PROJECT_TERNARYSEARCHTREE_H
#define PROJECT_TERNARYSEARCHTREE_H

#include <string>
#include <memory>

namespace TST {
    class TernarySearchTree {
        struct Node {
            char _data;
            bool _isEnd = false;
            std::shared_ptr<Node> _left = nullptr;
            std::shared_ptr<Node> _right = nullptr;
            std::shared_ptr<Node> _equal = nullptr;
            int _frequency{};

            explicit Node(char data) : _data(data) {}
        };
        std::shared_ptr<Node> _root;
    public:
        TernarySearchTree() : _root(nullptr) {}
        //By non-const l-value reference
        explicit TernarySearchTree(std::shared_ptr<Node> &node) : _root((node)) {}

        std::shared_ptr<Node> getRoot();

        void setRoot(std::shared_ptr<Node> node);

        void insert(std::string word, unsigned int frequency);

        std::shared_ptr<Node> insert(std::shared_ptr<Node> node, std::string word, unsigned int frequency, unsigned int pos);

        bool search(std::shared_ptr<Node> node, std::string word, unsigned int pos) const;


    };
}

#endif //PROJECT_TERNARYSEARCHTREE_H
