//
// Created by rafal on 14.09.17.
//

#include "MessageCorrect.h"
#include "../../AlgAndDataStructures/SpellCorrector.h"

MessageCorrect::MessageCorrect() : MAX_WORDS(10) {
    //_tst = std::make_shared<TST::TernarySearchTree>(tst);
    _corrector = std::make_shared<SpellCorrector>(SpellCorrector());
    _corrector->readFileIntoTST();
}

std::string MessageCorrect::getMessage(std::string& message) {
    _corrector->correctWord(message);
    auto pq = _corrector->getWordsPQ();
    std::string correctedMessage{};
    int i=0;
    while (!pq->empty() && i <= MAX_WORDS) {
        correctedMessage += pq->top().text + "\n";
        pq->pop();
        i++;
    }
    return correctedMessage;
}
