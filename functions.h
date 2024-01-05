using namespace std;

void save(string script) {
    ofstream file("script.vbs");
    if (file.is_open()) {
        file << script;
        file.close();
    }
}

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z');
}

string extractLetters(string texts) {
    string result;
    bool insideTag = false;

    for (size_t i = 0; i < texts.length(); i++) {
        if (texts[i] == '<') {
            insideTag = false;
        } else if (texts[i] == '>') {
            insideTag = true;
        } else if (insideTag && isLetter(texts[i])) {
            result += texts[i];
        } else if (texts[i] == 'v') {
            string check;
            for (size_t j = i; j < (i + 2); j++) {
                check += texts[j];
            }
            if (check == "v>") {
                result += ' ';
            }
        } 
    }
    return result;
}

string getUserInput(){
    string choice, texts;
    cout << "(Enter to return)\n1.Enter input from console\n2.Get input from file\nYour choice: ";
    getline(cin, choice);

    if (choice == "1") {
        cout << "Input: ";
        getline(cin, texts);
    } else if (choice == "2") {
        string filePath = "input.txt";
        ifstream inputFile(filePath);
        if (!inputFile) {
            cout << "Failed to open the input file." << endl;
            system("pause");
        }
        // Read the entire contents of the file into 'texts'
        texts.assign((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));
        inputFile.close();
    }
    return texts;
}

void runOrDiscardScritp(string texts){
    string script, choice;
    script = "Set wshShell = WScript.CreateObject(\"WScript.Shell\")\n";
    for (size_t i = 0; i < texts.length(); i++) {
        script = script + "wshShell.SendKeys \"{" + texts[i] + "}\"\n";
        script += "WScript.Sleep 2\n";
    }

    cout << "1.Run\n2.Discard\nYour choice: ";
    getline(cin, choice);
    if (choice == "1") {
        cout << "Running script in\n";
        save(script);
        for (int i = 3; i >= 0; i--) {
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << i << endl;
        }
        system("script.vbs");
        cout << "Press any key to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    } else {
        return;
    }
}

