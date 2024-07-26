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

string getUserInput(string cheatType){
    string texts;
    // cout << "(Enter to return)\n1.Enter input from console\n2.Get input from file\nYour choice: ";
    // getline(cin, choice);

    if (cheatType == "1") {
        cout << "Input: ";
        getline(cin, texts);
    } else if (cheatType == "2") {
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

void runOrDiscardScritp(string texts, string cheatType, float wpm){
    string script, choice;

    // int alphbt = 0, k = 0, space = 1;

    // for(size_t i = 0; i < texts.length(); i++){
    //     if(texts[i] != ' '){
    //         alphbt++;
    //         k++;
    //     }else if(texts[i] == ' ' && k != 0){
    //         space ++;
    //     } 
    // }

    // float avg_word = float(alphbt/space);

    float cps = (wpm * 5) / 60;
    
    cout<<cps<<endl;
    if (cps < 25) {
        cps = 1000 / float(cps * 1.2);  
        cout<<cps<<endl;
    } else {
        cps = 1000 / (cps * 2); 
        cout<<cps<<endl; 
    }

    cps = round(cps);

    script = "Set wshShell = WScript.CreateObject(\"WScript.Shell\")\n";

    if(cps < 5){
        cps = 5;
    }

    int con_cps = int(cps);


    int randCounter = (rand() % (50 - 1)) + 50;
    int count = 0;

    for (size_t i = 0; i < texts.length(); i++) {
        if (cheatType == "1"){   
            int random = (rand() % (con_cps + 50 - con_cps + 1)) + con_cps;
            if (randCounter == count){
                size_t tmp = i;
                if(i > 2){
                    tmp = i - 2;
                }
                script = script + "wshShell.SendKeys \"{" + texts[tmp] + "}\"\n";
                script = script + "WScript.Sleep " + to_string(random) + "\n";
                script = script + "wshShell.SendKeys \"{BACKSPACE}\"\n";
                script = script + "WScript.Sleep " + to_string(random) + "\n";
                script = script + "wshShell.SendKeys \"{" + texts[i] + "}\"\n";
                script = script + "WScript.Sleep " + to_string(random) + "\n";
                randCounter = (rand() % (200 - 1)) + 200;
                count = 0;
            }else{
                script = script + "wshShell.SendKeys \"{" + texts[i] + "}\"\n";
                script = script + "WScript.Sleep " + to_string(random) + "\n";
                count ++;
            }
        }else{
            script = script + "wshShell.SendKeys \"{" + texts[i] + "}\"\n";
            script = script + "WScript.Sleep " + to_string(con_cps) + "\n";
        }
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

