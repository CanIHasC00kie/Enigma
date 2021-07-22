
const int PAIRINGS = 13;

struct Reflector{
    // we can change the reflect logic later to be more complex in wiring and pairings.
    public: 
    int reflect(int i){
        return 26 - i + 1;
        
    }
};