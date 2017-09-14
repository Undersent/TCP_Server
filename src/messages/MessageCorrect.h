//
// Created by rafal on 14.09.17.
//

#ifndef PROJECT_MESSAGECORRECT_H
#define PROJECT_MESSAGECORRECT_H


#include "Message_I.h"
#include "../../AlgAndDataStructures/TernarySearchTree.h"

class MessageCorrect : public Message_I{
    std::shared_ptr<SpellCorrector> _corrector;
    std::shared_ptr<TST::TernarySearchTree> _tst;
public:
    explicit MessageCorrect(TST::TernarySearchTree tst);
    std::string getMessage(std::string& message) override ;
};


#endif //PROJECT_MESSAGECORRECT_H
