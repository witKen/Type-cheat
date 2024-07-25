#include <string>
using namespace std;

int typeracerCheat(float wpm){
    string texts;

    texts = getUserInput("1");
    if (texts.empty()) {
        return 0;
    }

    runOrDiscardScritp(texts, "1", wpm);
    return 0;

}

int monkeytypeCheat(float wpm){
    string texts, result;
    
    texts = getUserInput("2");

    if(texts.empty()){
        return 0;
    }

    result = extractLetters(texts);
    runOrDiscardScritp(result, "2", wpm);
    return 0;
}