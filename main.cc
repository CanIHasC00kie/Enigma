#include <iostream>
#include <string>
#include "enigma.h"

// 3 Rotors
// {{0, 15 }, {1, 4 }, {2, 25 }, {3, 20 }, {4, 14 }, {5, 7 }, {6, 23 }, {7, 18 }, {8, 2 }, {9, 21 }, {10, 5 }, {11, 12 },
// {12, 19 }, {13, 1 }, {14, 6 }, {15, 11 }, {16, 17 }, {17, 8 }, {18, 13 }, {19, 16 }, {20, 9 }, {21, 22 }, {22, 0 }, {23, 24 }, {24, 3 }, {25, 10 }};

// {{0, 25 }, {1, 14 }, {2, 20 }, {3, 4 }, {4, 18 }, {5, 24 }, {6, 3 }, {7, 10 }, {8, 5 }, {9, 22 }, {10, 15 }, {11, 2 },
// {12, 8 }, {13, 16 }, {14, 23 }, {15, 7 }, {16, 12 }, {17, 21 }, {18, 1 }, {19, 11 }, {20, 6 }, {21, 13 }, {22, 9 }, {23, 17 }, {24, 0 }, {25, 19 }};

// {{0, 4 }, {1, 7 }, {2, 17 }, {3, 21 }, {4, 23 }, {5, 6 }, {6, 0 }, {7, 14 }, {8, 1 }, {9, 16 }, {10, 20 }, {11, 18 },
//  {12, 8 }, {13, 12 }, {14, 25 }, {15, 5 }, {16, 11 }, {17, 24 }, {18, 13 }, {19, 22 }, {20, 10 }, {21, 19 }, {22, 15 }, {23, 3 }, {24, 9 }, {25, 2 }};

int main()
{
    int rotor1[ALPHABET_LEHGTH][2] = {{1, 16}, {2, 5}, {3, 26}, {4, 21}, {5, 15}, {6, 8}, {7, 24}, {8, 19}, {9, 3}, {10, 22}, {11, 6}, {12, 13}, {13, 20}, {14, 2}, {15, 7}, {16, 12}, {17, 18}, {18, 9}, {19, 14}, {20, 17}, {21, 10}, {22, 23}, {23, 1}, {24, 25}, {25, 4}, {26, 11}};
    int rotor2[ALPHABET_LEHGTH][2] = {{1, 26}, {2, 15}, {3, 21}, {4, 5}, {5, 19}, {6, 25}, {7, 4}, {8, 11}, {9, 6}, {10, 23}, {11, 16}, {12, 3}, {13, 9}, {14, 17}, {15, 24}, {16, 8}, {17, 13}, {18, 22}, {19, 2}, {20, 12}, {21, 7}, {22, 14}, {23, 10}, {24, 18}, {25, 1}, {26, 20}};
    int rotor3[ALPHABET_LEHGTH][2] = {{1, 5}, {2, 8}, {3, 18}, {4, 22}, {5, 24}, {6, 7}, {7, 1}, {8, 15}, {9, 2}, {10, 17}, {11, 21}, {12, 19}, {13, 9}, {14, 13}, {15, 26}, {16, 6}, {17, 12}, {18, 25}, {19, 14}, {20, 23}, {21, 11}, {22, 20}, {23, 16}, {24, 4}, {25, 10}, {26, 3}};
    char cmd;
    std::cout << "Hello and welcome! My name is Thoralf. Enter e for encrypt, d for decrypt." << std::endl;

    Enigma thoralf(rotor1,
                            rotor2,
                            rotor3, 1, 1, 1);

    while (std::cin >> cmd)
    {

        if (cmd == 'e')
        {
            std::string message;
            char ciphertext;
            std::cout << "Please enter a message using only capital letters and spaces: " << std::endl;


            int ind = 1;
            
            
            while(std::getline(std::cin, message)){
                if (ind == 0) {
                    std::cout << "Ciphertext: ";
                }
                
                for(char &c : message){
                    if (c != ' '){
                        ciphertext=(thoralf.encrypt(c));
                        std::cout << ciphertext;
                    }
                    else if (c == ' '){
                        std::cout << " ";
                    }
                }
                if (ind == 0){
                    std::cout << std::endl;
                    std::cout << std::endl;
                }
                ind = 0;
                
            }
            // break;
        }

        else if (cmd == 'd'){
            std::string ciphertext;
            char message;
            std::cout << "Please enter a message using only capital letters and spaces: " << std::endl;


            int ind = 1;
            
            
            while(std::getline(std::cin, ciphertext)){
                if (ind == 0) {
                    std::cout << "Ciphertext: ";
                }
                
                for(char &c : ciphertext){
                    if (c != ' '){
                        message=(thoralf.encrypt(c));
                        std::cout << message;
                    }
                    else if (c == ' '){
                        std::cout << " ";
                    }
                }
                if (ind == 0){
                    std::cout << std::endl;
                    std::cout << std::endl;
                }
                ind = 0;
                
            }
            
        }
    }


    return 0;
}