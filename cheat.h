#include <string>
using namespace std;

int typeracerCheat(){
    string texts;

    texts = getUserInput();
    if (texts.empty()) {
        return 0;
    }
    runOrDiscardScritp(texts);
    return 1;

}

int monkeytypeCheat(){
    string texts, result;
    
    texts = getUserInput();

    if(texts.empty()){
        return 0;
    }

    result = extractLetters(texts);
    runOrDiscardScritp(result);
    return 1;
}