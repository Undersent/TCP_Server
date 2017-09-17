//
// Created by rafal on 12.09.17.
//

#ifndef PROJECT_TERNARYSEARCHTREE_H
#define PROJECT_TERNARYSEARCHTREE_H

#include <string>
#include <memory>
#include <gtest/gtest_prod.h>


class TernarySearchTree {

    struct Node {

        char _data;
        bool _isEnd = false;
        std::unique_ptr<Node> _left = nullptr;
        std::unique_ptr<Node> _right = nullptr;
        std::unique_ptr<Node> _equal = nullptr;
        std::string _frequency{};

        explicit Node(char data) : _data(data) {}
    };

    std::unique_ptr<Node> _root{nullptr};

public:
    friend class SpellCorrector;

    TernarySearchTree() = default;

    //By non-const l-value reference
    explicit TernarySearchTree(std::unique_ptr<Node> node) : _root(std::move(node)) {}

    void insert(const std::string &word, const std::string &frequency);

    std::unique_ptr<Node> insert(std::unique_ptr<Node> &node,const  std::string &word,const
                                 std::string& frequency,
                                 const unsigned int pos);

    bool search(std::unique_ptr<Node> node,const  std::string &word, unsigned int pos) const;

    void traverseTSTUtil(const std::unique_ptr<TernarySearchTree::Node> &root,
                         char *buffer,const unsigned int depth = 0);

    const std::unique_ptr<Node> &getRoot() const;

    void setRoot(Node node);

};


#endif //PROJECT_TERNARYSEARCHTREE_H
