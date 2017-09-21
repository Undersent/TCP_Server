//
// Created by rafal on 14.09.17.
//

#ifndef PROJECT_MESSAGECORRECT_H
#define PROJECT_MESSAGECORRECT_H


#include "Message_I.h"
#include "../../AlgAndDataStructures/TernarySearchTree.h"
#include "../../AlgAndDataStructures/SpellCorrector.h"

class MessageCorrect : public Message_I{

    std::unique_ptr<SpellCorrector> _corrector;
    const unsigned int MAX_WORDS{10};

private:
    void prepareMessageToCheckInDictionary(std::string &message, unsigned int noOfDeletedChar);

public:
    MessageCorrect();
    std::string getMessage(std::string& message) override ;
    const std::string getName()const override {return "MessageCorrect";};


};


#endif //PROJECT_MESSAGECORRECT_H
