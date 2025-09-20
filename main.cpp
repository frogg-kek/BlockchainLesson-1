#include "header.h"
    

int main() {

    std::cout << std::endl;
    
    std::cout << "Sveiki atvykę į paprastą hash funkcijos generatorių!" << std::endl;
    
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
            std::cout << "Ar norite generuoti naujus failus? (1 - Taip, 2 - Ne): ";
            int naujiFailai;
            bool patikra = false;
            while (!patikra){
                std::cin >> naujiFailai;
                if(naujiFailai < 1 || naujiFailai > 2){
                    std::cout << "Klaida! Įveskite skaičių." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else {
                    patikra = true;
                }
            }
            if(naujiFailai == 1) GeneruotiFailus();

            else {
                std::cout << "Pasirinkite .txt failą, kurį norite užhashinti: " << std::endl;
                std::cout << "1 - Vieno_simobolio.txt" << std::endl;
                std::cout << "2 - >1000_simboliu.txt" << std::endl;
                std::cout << "3 - >1000_skirtingu_simboliu.txt" << std::endl;
                std::cout << "4 - failas_empty.txt" << std::endl;
            }

        bool patikra2 = false;
        while (!patikra2){
            std::cout<< "Jūsų pasirinkimas: ";
            std::cin >> variantas;
            if(variantas < 1 || variantas > 4){
                std::cout << "Klaida! Įveskite skaičių." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                patikra2 = true;
            }
        }

        switch(variantas){
            case 1 : tekstas = FailoSkaitymas("Vieno_simobolio.txt"); break;
            case 2 : tekstas = FailoSkaitymas(">1000_simboliu.txt"); break;
            case 3 : tekstas = FailoSkaitymas(">1000_skirtingu_simboliu.txt"); break;
            case 4 : tekstas = FailoSkaitymas("failas_empty.txt"); break;
        }
    }

    std::string hash = HashFunkcija(tekstas);
    std::cout << hash << std::endl;

    std::cout << std::endl;

    std::cout << "Ar norėtumėte patikrinti koalizijų atsiradimą? (1 - Taip, 2 - Ne): ";
    
    int koalicijosPasirinkimas;
    bool patikrinimas = false;

    while(!patikrinimas){
        std::cin >> koalicijosPasirinkimas;
        if(koalicijosPasirinkimas < 1 || koalicijosPasirinkimas > 2){
            std::cout << "Klaida! Įveskite skaičių." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            patikrinimas = true;
        }
    }

    switch(koalicijosPasirinkimas){
        case 1:
            size_t length;
            std::cout << "Įveskite simbolių kiekį, kurį norėtumėte sugeneruoti: ";
            std::cin >> length;
            KoalizijosPatikra(length);
            break;
        case 2:
            std::cout << "Programa baigė darbą." << std::endl;
            break;
    }

    std::cout << "Ar norėtumėte atlikti lavinos efekto testą (100k porų)? (1 - Taip, 2 - Ne): ";
    int lavinosPasirinkimas;
    bool patikrinimas2 = false;
    while(!patikrinimas2){
        std::cin >> lavinosPasirinkimas;
        if(lavinosPasirinkimas < 1 || lavinosPasirinkimas > 2){
            std::cout << "Klaida! Įveskite skaičių." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            patikrinimas2 = true;
        }
    }
    switch(lavinosPasirinkimas){
        case 1:
            TestuokLavinosEfekta(HashFunkcija);
            break;
        case 2:
            std::cout << "Programa baigė darbą." << std::endl;
            break;
    }

    return 0;
    // 904418064
    // 904418064

}
