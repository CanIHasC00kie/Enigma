#include <iostream>


const char ALPHABET_LEHGTH = 26;

// 3 Rotors
// {{0, 15 }, {1, 4 }, {2, 25 }, {3, 20 }, {4, 14 }, {5, 7 }, {6, 23 }, {7, 18 }, {8, 2 }, {9, 21 }, {10, 5 }, {11, 12 }, {12, 19 }, {13, 1 }, {14, 6 }, {15, 11 }, {16, 17 }, {17, 8 }, {18, 13 }, {19, 16 }, {20, 9 }, {21, 22 }, {22, 0 }, {23, 24 }, {24, 3 }, {25, 10 }};
// {{0, 25 }, {1, 14 }, {2, 20 }, {3, 4 }, {4, 18 }, {5, 24 }, {6, 3 }, {7, 10 }, {8, 5 }, {9, 22 }, {10, 15 }, {11, 2 }, {12, 8 }, {13, 16 }, {14, 23 }, {15, 7 }, {16, 12 }, {17, 21 }, {18, 1 }, {19, 11 }, {20, 6 }, {21, 13 }, {22, 9 }, {23, 17 }, {24, 0 }, {25, 19 }};
// {{0, 4 }, {1, 7 }, {2, 17 }, {3, 21 }, {4, 23 }, {5, 6 }, {6, 0 }, {7, 14 }, {8, 1 }, {9, 16 }, {10, 20 }, {11, 18 }, {12, 8 }, {13, 12 }, {14, 25 }, {15, 5 }, {16, 11 }, {17, 24 }, {18, 13 }, {19, 22 }, {20, 10 }, {21, 19 }, {22, 15 }, {23, 3 }, {24, 9 }, {25, 2 }};
class Rotor{
    public: 
    int **rotor;
    int rp;

    Rotor( int rotor[ALPHABET_LEHGTH][2], int rp){
        // borrow heap memory
        this->rotor = new int *[ALPHABET_LEHGTH];
        for( int i = 0; i < ALPHABET_LEHGTH; ++i){
            this->rotor[i] = new int[2]; 
        }
        // initialize the borrowed array.
        for(int i = 0; i < ALPHABET_LEHGTH; ++i){
            for(int j = 0; j < 2; ++j){
                this->rotor[i][j] = rotor[i][j];
            }
        }
        this->rp = rp;
    }

    ~Rotor(){
        for(int i = 0; i < ALPHABET_LEHGTH; ++i){
            delete [] this->rotor[i];
        }
        delete this->rotor;
    }

    

    void revolve()
    {
        ++this->rp;
        // revolves upward.
        int first_elem0 = this->rotor[0][0];
        int first_elem1 = this->rotor[0][1];
        for (int i = 0; i < ALPHABET_LEHGTH; ++i)
        {
            if (i == ALPHABET_LEHGTH - 1)
            {
                this->rotor[i][0] = first_elem0;
                this->rotor[i][1] = first_elem1;
            }
            else if (i != ALPHABET_LEHGTH - 1)
            {
                this->rotor[i][1] = this->rotor[i + 1][1];
                this->rotor[i][0] = this->rotor[i + 1][0];
            }
        }
    }

    void print_rotor()
    {
        for (int i = 0; i < ALPHABET_LEHGTH; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                std::cout << this->rotor[i][j] << ", ";
            }
            std::cout << std::endl;
        }
    }
    // fwd is true if we are going forward, false if backward in the wiring system.
    // wiring spits out the exit index for the current rotor, and the entry index for the next rotor.
    int wiring( int to_match, int fwd ){
        for(int i =0; i < ALPHABET_LEHGTH; ++i){
            if (this->rotor[i][fwd] == to_match){
                return i; // our exit index
            }
        }
        std::cout << "Ahh crap, we didn't get a successful match." << std::endl;
        return 0; // if this doesn't work.
    }
};