#include "header.h"

std::string FailoSkaitymas(std::string failoPav){
    
    std::ifstream failas(failoPav);
    std::stringstream buffer;
    buffer << failas.rdbuf();
    return buffer.str();
}

std::string HashFunkcija(std::string tekstas){
    
    unsigned char hash[HASH_DYDIS] = {0};

    for(int i = 0; i<tekstas.size(); i++){
        hash[i % HASH_DYDIS] ^= tekstas[i];
        
        if(tekstas[i] % 2 == 0){
            hash[i*7 % HASH_DYDIS] += 2;
        }
        else {
            hash[i*7 % HASH_DYDIS] += 3;
        }

        if(hash[i % HASH_DYDIS] > 128){
            hash[i % HASH_DYDIS] = 255 - hash[i % HASH_DYDIS];
        }

        if(i % 5 == 0){
            hash[(i*13) % HASH_DYDIS]+= (tekstas[i] % 2) + 1;
        }

        unsigned char temp = hash[i % HASH_DYDIS] >> 4;
        hash[i % HASH_DYDIS] = (hash[i % HASH_DYDIS] << 4) | temp;
    }

    std::stringstream rez;
    for(int i = 0; i < HASH_DYDIS; i++){
        rez << (int)hash[i];
    } 
    return rez.str(); 
}
    
    