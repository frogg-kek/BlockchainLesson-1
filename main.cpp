#include "header.h"
    

int main() {

    std::cout << "Sveiki atvykę į paprastą hash funkcijos generatorių!" << std::endl;
    std::cout << "Jeigu programą paleidote pirmą kartą, spauskite - 1" << std::endl;
    std::cout << "Jeigu jau dirbote ir nenorite generuoti naujas reikšmes failams,  spauskite - 2" << std::endl;
    
    int generacija;
    std::cout << "Jūsų pasirinkimas: ";
    std::cin >> generacija;
    if(generacija == 1) GeneruotiFailus();

    std::cout << std::endl;

    std::cout << "Galite pradeti dirbti!" << std::endl;

    std::cout << std::endl;

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
