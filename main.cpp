#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

const int HASH_DYDIS = 32;

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
    

int main() {

    std::cout << "Pasirinkite ką norėtumete hashuoti:" << std::endl;
    std::cout << "1 - Įrašytą tekstą" << std::endl;
    std::cout << "2 - .txt failą" << std::endl;
    
    int choice;
    bool patikra = false;

    while (!patikra){
        std::cout<< "Jūsų pasirinkimas: ";
        std::cin >> choice;
        if(choice < 1 || choice > 2){
            std::cout << "Klaida! Įveskite skaičių." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            patikra = true;
        }
    }

    std::string tekstas;
    int variantas;
    switch(choice){
        case 1:
            std::cout << "Įveskite teksto kombinaciją, kuria norite užhashinti: ";
            std::cin >> tekstas;
            break;
        case 2:
            std::cout << "Pasirinkite .txt failą, kurį norite užhashinti: " << std::endl;
            std::cout << "1 - Vieno_simobolio.txt" << std::endl;
            std::cout << "2 - >1000_simboliu.txt" << std::endl;
            std::cout << "3 - >1000_skirtingu_simboliu.txt" << std::endl;


        bool patikra = false;
        while (!patikra){
            std::cout<< "Jūsų pasirinkimas: ";
            std::cin >> variantas;
            if(variantas < 1 || variantas > 3){
                std::cout << "Klaida! Įveskite skaičių." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                patikra = true;
            }
        }
        switch(variantas){
            case 1 : tekstas = FailoSkaitymas("Vieno_simobolio.txt"); break;
            case 2 : tekstas = FailoSkaitymas(">1000_simboliu.txt"); break;
            case 3 : tekstas = FailoSkaitymas(">1000_skirtingu_simboliu.txt"); break;
        }
    }
    std::string hash = HashFunkcija(tekstas);
    std::cout << hash << std::endl;

    
    return 0;
    // 904418064
    // 904418064

}