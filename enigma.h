
#include "rotor.h"
#include "reflector.h"

const char ALPHABET[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


class Enigma
{

    Rotor r1;
    Rotor r2;
    Rotor r3;
    Reflector ref;
    public:

    Enigma(int rot1[ALPHABET_LEHGTH][2], int rot2[ALPHABET_LEHGTH][2], int rot3[ALPHABET_LEHGTH][2], int rp1, int rp2, int rp3) : r1(rot1, rp1), r2(rot2, rp2), r3(rot3, rp3), ref() {}
     
    char encrypt(char m){
        r1.revolve();
        if (r1.rp % ALPHABET_LEHGTH == 0 ){
            r2.revolve();
        }
        if(r2.rp % ALPHABET_LEHGTH == 0){
            r3.revolve();
        }
        int fwd = ref.reflect( r3.wiring(r3.rotor[r2.wiring(r2.rotor[r1.wiring( (int)(m - 64), 1 )][0], 1)][0], 1) + 1);
        int bwd = r1.rotor[r1.wiring( r1.rotor[r2.wiring(r2.rotor[r3.wiring(r3.rotor[(fwd-1)][1], 0)][1], 0)][1], 0)][0];
        char ciphertext = (char) (bwd + 64);
        return ciphertext;
    }

    char decrypt(char c){
        r1.revolve();
        if (r1.rp % ALPHABET_LEHGTH == 0 ){
            r2.revolve();
        }
        if(r2.rp % ALPHABET_LEHGTH == 0){
            r3.revolve();
        }
        int fwd = ref.reflect( r3.wiring(r3.rotor[r2.wiring(r2.rotor[r1.wiring( (int)(c - 64), 1 )][0], 1)][0], 1) + 1);
        int bwd = r1.rotor[r1.wiring( r1.rotor[r2.wiring(r2.rotor[r3.wiring(   r3.rotor[(fwd-1)][1], 0)][1], 0)][1], 0)][0];
        char message = (char) (bwd + 64);
        return message;
    }
};