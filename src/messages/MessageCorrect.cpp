//
// Created by rafal on 14.09.17.
//

#include "MessageCorrect.h"
#include "../../AlgAndDataStructures/SpellCorrector.h"

MessageCorrect::MessageCorrect(TST::TernarySearchTree tst) {
    _tst = std::make_shared<TST::TernarySearchTree>(tst);
    _corrector = std::make_shared<SpellCorrector>(SpellCorrector(_tst));
    _corrector->readFileIntoTST();
}

std::string MessageCorrect::getMessage(std::string& message) {
    _corrector->correctWord(message);
    auto pq = _corrector->getWordsPQ();
    std::string correctedMessage{};
    while (!pq->empty()) {
        correctedMessage+=pq->top().text+"\n";
        //std::cout << pq->top().text << " czestosc " << pq->top().value << " distance " << pq->top().editDistance
        //          << std::endl;
        pq->pop();
    }
    std::cout<<correctedMessage<<" wiadomosc po korekcie";
    return correctedMessage;
}

//TST::TernarySearchTree tst;
//SpellCorrector corrector;
//corrector.readFileIntoTST(tst);
//std::string word{"MUZIK"};
//corrector.correctWord(word);
//auto pq = corrector.getWordsPQ();
//while(!pq->empty()) {
//     std::cout << pq->top().text << " czestosc "<< pq->top().value << " distance "<< pq->top().editDistance<<std::endl;
//    pq->pop();
//}