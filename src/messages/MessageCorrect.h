//
// Created by rafal on 14.09.17.
//

#ifndef PROJECT_MESSAGECORRECT_H
#define PROJECT_MESSAGECORRECT_H


#include "Message_I.h"
#include "../../AlgAndDataStructures/TernarySearchTree.h"

class MessageCorrect : public Message_I{

    std::shared_ptr<SpellCorrector> _corrector;
    const unsigned int MAX_WORDS{10};

public:
    MessageCorrect();
    std::string getMessage(std::string& message) override ;
};


#endif //PROJECT_MESSAGECORRECT_H
