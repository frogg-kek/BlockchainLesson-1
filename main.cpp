#include "header.h"
    

int main() {
    
    bool kartoti = true;
    
    while(kartoti) {
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
            {
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
        break;
    }

    auto start = std::chrono::high_resolution_clock::now();
    std::string hash = HashFunkcija(tekstas);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Hash funkcijos generavimo laikas: " << duration.count() << " sek." << std::endl;
    std::cout << hash << std::endl;

    std::cout << std::endl;

    std::cout << "Ar norėtumėte atlikti papildomus testus (koalizijos, lavinos efekto, negrįžtamumo)? (1 - Taip, 2 - Ne): ";
    
    int papildomiTestai;
    bool patikrinimas = false;

    while(!patikrinimas){
        std::cin >> papildomiTestai;
        if(papildomiTestai < 1 || papildomiTestai > 2){
            std::cout << "Klaida! Įveskite skaičių." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            patikrinimas = true;
        }
    }

    if(papildomiTestai == 1) {
        std::cout << "Ar norėtumėte patikrinti koalizijų atsiradimą? (1 - Taip, 2 - Ne): ";
        
        int koalicijosPasirinkimas;
        bool patikrinimas2 = false;

        while(!patikrinimas2){
            std::cin >> koalicijosPasirinkimas;
            if(koalicijosPasirinkimas < 1 || koalicijosPasirinkimas > 2){
                std::cout << "Klaida! Įveskite skaičių." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                patikrinimas2 = true;
            }
        }

        switch(koalicijosPasirinkimas){
            case 1:
                {
                int length;
                std::cout << "Įveskite simbolių kiekį, kurį norėtumėte sugeneruoti: ";
                std::cin >> length;
                KoalizijosPatikra(length);
                }
                break;
            case 2:
                std::cout << "Koalizijų testas praleistas." << std::endl;
                break;
        }

        std::cout << "Ar norėtumėte atlikti lavinos efekto testą (100k porų)? (1 - Taip, 2 - Ne): ";
        int lavinosPasirinkimas;
        bool patikrinimas3 = false;
        while(!patikrinimas3){
            std::cin >> lavinosPasirinkimas;
            if(lavinosPasirinkimas < 1 || lavinosPasirinkimas > 2){
                std::cout << "Klaida! Įveskite skaičių." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                patikrinimas3 = true;
            }
        }
        switch(lavinosPasirinkimas){
            case 1:
                TestuokLavinosEfekta(HashFunkcija);
                break;
            case 2:
                std::cout << "Lavinos efekto testas praleistas." << std::endl;
                break;
        }

        std::cout << "Ar noretumete atlikti negriztamumo demonstracija? (1 - Taip, 2 - Ne): ";
        int negriztamumoPasirinkimas;
        bool patikrinimas4 = false;
        while(!patikrinimas4){
            std::cin >> negriztamumoPasirinkimas;
            if(negriztamumoPasirinkimas < 1 || negriztamumoPasirinkimas > 2){
                std::cout << "Klaida! Įveskite skaičių." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                patikrinimas4 = true;
            }
        }
        switch(negriztamumoPasirinkimas){
            case 1:
                {
                std::string inputas;
                std::cout << "Įveskite norimą tekstą: ";
                std::cin >> inputas;
                TestHiding(inputas);
                TestPuzzleFriendliness(inputas);
                }
                break;
            case 2:
                std::cout << "Negrįžtamumo testas praleistas." << std::endl;
                break;
        }
    }
    
    // Klausti ar nori kartoti programą
    std::cout << "Ar norėtumėte kartoti programą su kitu tekstu/failu? (1 - Taip, 2 - Ne): ";
    int kartojimosPasirinkimas;
    bool patikrinimas5 = false;
    while(!patikrinimas5){
        std::cin >> kartojimosPasirinkimas;
        if(kartojimosPasirinkimas < 1 || kartojimosPasirinkimas > 2){
            std::cout << "Klaida! Įveskite skaičių." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            patikrinimas5 = true;
        }
    }
    
    if(kartojimosPasirinkimas == 2) {
        kartoti = false;
        std::cout << "Programa baigė darbą." << std::endl;
    }
    
    } // End of main while loop

    return 0;
}
