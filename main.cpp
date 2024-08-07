#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <cmath>
#include <cstdlib>
#include "functions.h"
#include "cheat.h"
using namespace std;

float wpm_float = 300;

int main() {
    while(true){
        string choice;
        system("clear");
        cout<<"0. Exit\n1. Typeracer Cheat\n2. Monkeytype Cheat\n3. Change Speed (Current WPM: "<<wpm_float<<")\n";
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
                check = typeracerCheat(wpm_float);
                if(check == 0){
                    break;
                }
            }
        }else if(choice == "2"){
            while(true){
                int check;
                system("clear");
                cout<<"Monkeytype Cheat\n";
                check = monkeytypeCheat(wpm_float);
                if(check == 0){
                    break;
                }
            }
        }else if(choice == "3"){
            while(true){
                string wpm;
                system("clear");
                cout<<"Change Speed\n";     
                cout<<"Input WPM: ";
                getline(cin, wpm);

                try {
                    wpm_float = stof(wpm);
                    if (wpm_float < 1) {
                        wpm_float = 1;
                    }else if(wpm_float > 650){
                        wpm_float = 650;
                    }
                    cout << "WPM: " << wpm_float << endl;
                    break;
                } catch (const invalid_argument&) {
                    cout << "Invalid input. Please enter a valid number: ";    
                    cout << "Press any key to continue...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                } catch (const out_of_range&) {
                    cout << "Input value is out of range. Please enter a valid number: ";
                    cout << "Press any key to continue...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                            
            }
        }
    }
    return 0;
}