#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include "functions.h"
#include "cheat.h"
using namespace std;

int main() {
    while(true){
        string choice;
        system("clear");
        cout<<"0.Exit\n1.Typeracer Cheat\n2.Monkeytype Cheat\n";
        cout<<"Your choice: ";
        getline(cin, choice);
        if(choice == "0"){
            cout<<"Exit\n";
            break;
        }else if(choice == "1"){
            while (true){
                int check;
                system("clear");
                cout<<"Typeracer Cheat\n";
                check = typeracerCheat();
                if(check == 0){
                    break;
                }
            }
        }else if(choice == "2"){
            while(true){
                int check;
                system("clear");
                cout<<"Typeracer Cheat\n";
                check = monkeytypeCheat();
                if(check == 0){
                    break;
                }
            }
        }
    }
    return 0;
}