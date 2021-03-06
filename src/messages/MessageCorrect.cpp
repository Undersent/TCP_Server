//
// Created by rafal on 14.09.17.
//

#include "MessageCorrect.h"
#include "../../AlgAndDataStructures/SpellCorrector.h"

MessageCorrect::MessageCorrect() : MAX_WORDS(10) {
    //_tst = std::make_shared<TST::TernarySearchTree>(tst);
    _corrector = std::make_unique<SpellCorrector>(SpellCorrector{});
    _corrector->readFileIntoTST();

}

std::string MessageCorrect::getMessage(std::string& message) {
    prepareMessageToCheckInDictionary(message, 7);
    try {
        _corrector->correctWord(message);
    }catch(std::exception& e){ return e.what();}
    std::string correctedMessage{};
    int i=0;
    while (!_corrector->getWordsPQ()->empty() && i <= MAX_WORDS) {
        correctedMessage += _corrector->getWordsPQ()->top().text + "\t";
        _corrector->getWordsPQ()->pop();
        i++;
    }
    if (correctedMessage.empty()) {
        return std::string("cant find similar words");
    }else
    return correctedMessage;
}

void MessageCorrect::prepareMessageToCheckInDictionary(std::string &message,
                                                      unsigned int noOfDeletedChar) {
    std::cout<<message<<std::endl;
    if (!message.empty() && message.substr(0, 7) == "[check]") {
        message = message.substr(noOfDeletedChar);//to the end
        std::cout<<message<<std::endl;
        auto &f = std::use_facet<std::ctype<char>>(std::locale());
        f.toupper(const_cast<char *>(message.data()), message.data() + message.size());
    }
}