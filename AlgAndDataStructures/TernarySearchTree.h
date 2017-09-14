//
// Created by rafal on 12.09.17.
//

#ifndef PROJECT_TERNARYSEARCHTREE_H
#define PROJECT_TERNARYSEARCHTREE_H

#include <string>
#include <memory>


class SpellCorrector;
namespace TST {
    class TernarySearchTree {
    public :
        struct Node {
            friend class SpellCorrector;
            char _data;
            bool _isEnd = false;
            std::shared_ptr<Node> _left = nullptr;
            std::shared_ptr<Node> _right = nullptr;
            std::shared_ptr<Node> _equal = nullptr;
            std::string _frequency{};

            explicit Node(char data) : _data(data) {}
        };
        std::shared_ptr<Node> _root;

    public:
        friend class SpellCorrector;

        TernarySearchTree() : _root(nullptr){}

        //By non-const l-value reference
        explicit TernarySearchTree(std::shared_ptr<Node> &node) : _root((node)) {}

        //std::shared_ptr<Node> getRoot();
        const std::shared_ptr<Node> &getRoot() const;

        void setRoot(const std::shared_ptr<Node> &node);

        void insert(std::string& word, std::string& frequency);

        std::shared_ptr<Node> insert(std::shared_ptr<Node> &node, std::string &word, std::string frequency,
                                     unsigned int pos);

        bool search(std::shared_ptr<Node> node, std::string& word, unsigned int pos) const;

        void traverseTSTUtil(const std::shared_ptr<TernarySearchTree::Node>& root,
                             char* buffer, unsigned int depth = 0);


    };

}

#endif //PROJECT_TERNARYSEARCHTREE_H
