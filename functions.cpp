#include "header.h"

void GeneruotiFailus(){

    std::ofstream fileA("Vieno_simobolio.txt");
    fileA << 'a';
    fileA.close();

    const int size = 1001;
    const std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, chars.size() - 1);

    std::string randomStr;
    randomStr.reserve(size);
    for (int i = 0; i < size; ++i) {
        randomStr += chars[dis(gen)];
    }

    std::ofstream fileRandom(">1000_simboliu.txt");
    fileRandom << randomStr;
    fileRandom.close();

  
    std::string randomStr2 = randomStr;
    randomStr2[size / 2] = 'X';


    std::ofstream fileDiffB(">1000_skirtingu_simboliu.txt");
    fileDiffB << randomStr2;
    fileDiffB.close();

    std::ofstream fileEmpty("failas_empty.txt");
    fileEmpty.close();

}

std::string FailoSkaitymas(std::string failoPav){
    
    std::ifstream failas(failoPav);
    std::stringstream buffer;
    buffer << failas.rdbuf();
    return buffer.str();
}

std::string HashFunkcija(std::string tekstas){
    
    unsigned char hash[HASH_DYDIS] = {0};

    for(int i = 0; i<(int)tekstas.size(); i++){
        hash[i % HASH_DYDIS] ^= tekstas[i];
        
        if(tekstas[i] % 2 == 0){
            hash[i*3 % HASH_DYDIS] += 2;
        }
        if(tekstas[i] % 3 == 0){
            hash[i*2 % HASH_DYDIS] += 3;
        }
        else {
            hash[i*5 % HASH_DYDIS] += 4;
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

    for(int kartas = 0; kartas < 8; kartas++){
        for(int i = 0; i < HASH_DYDIS; i++){
            hash[i] ^= (hash[(i+7) % HASH_DYDIS] + hash[(i+13) % HASH_DYDIS]) ^ (i * 31);
            
            int pasukimai = (3 + kartas) % 8;
            hash[i] = (hash[i] << pasukimai) | (hash[i] >> (8 - pasukimai));
            hash[i] = (hash[i] * 31 + (kartas * 17)) & 0xFF;
        }
    }
    

    char hexmap[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    std::string out;
    out.reserve(HASH_DYDIS * 2);

    
    for(int i = 0; i < HASH_DYDIS; i++){
        unsigned char c = hash[i];
        out.push_back(hexmap[c >> 4]);
        out.push_back(hexmap[c & 0x0F]);
    }

    return out; 
}
    
    
