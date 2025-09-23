#include "header.h"

std::string random_string_generatorius(int ilgis) {
    const std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> dis(0, chars.size() - 1);

    std::string randomStr;
    randomStr.reserve(ilgis);
    for (int i = 0; i < ilgis; ++i) {
        randomStr += chars[dis(generator)];
    }
    return randomStr;
}

void TestHiding(const std::string& input, int test_count, int salt_length) {
    std::vector<std::string> seen_hashes;

    for (int i = 0; i < test_count; ++i) {
        std::string salt = random_string_generatorius(salt_length);
        std::string combined = input + salt;
        std::string hash = HashFunkcija(combined);

        if (std::find(seen_hashes.begin(), seen_hashes.end(), hash) != seen_hashes.end()) {
            std::cout << "Pasikartojantis hash rastas: " << hash << std::endl;
            return;
        }
        
        seen_hashes.push_back(hash);
    }
    std::cout << "Hiding testas sėkmingas: hash reikšmės unikalios per " << test_count << " iteracijų." << std::endl;

}

void TestPuzzleFriendliness(const std::string& input, int zeroes_needed, int max_iter) {
    std::string salt = random_string_generatorius(16);

    for (int i = 0; i < max_iter; ++i) {
        std::string to_hash = input + salt + std::to_string(i);
        std::string hash = HashFunkcija(to_hash);

        bool match = true;
        for (int j = 0; j < zeroes_needed; ++j) {
            if (j >= int(hash.size()) || hash[j] != '0') {
                match = false;
                break;
            }
        }

        if (match) {
            std::cout << "Puzzle-friendliness rasta i = " << i << ", hash = " << hash << std::endl;
            return;
        }
    }
    std::cout << "Puzzle-friendliness neaptikta per " << max_iter << " iteracijų." << std::endl;
}


std::string Keitimas_vieno_simbolio(std::string& tekstas) {
    std::string naujas = tekstas;   
    std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<size_t> dis(0, chars.size() - 1);
    std::uniform_int_distribution<size_t> char_dis(0, tekstas.size() - 1);
    size_t pozicija = char_dis(gen);
    char naujas_simbolis;
    do {
        naujas_simbolis = chars[dis(gen)];
    } while (naujas_simbolis == tekstas[pozicija]);
    naujas[pozicija] = naujas_simbolis;
    return naujas;
}

double diff_bits(const std::string& h1, const std::string& h2) {
    int bit_diff = 0;
    for (size_t i = 0; i < h1.size(); ++i) {
        unsigned char c1 = h1[i], c2 = h2[i];
        for (int b = 0; b < 8; ++b)
            bit_diff += ((c1 >> b) & 1) != ((c2 >> b) & 1);
    }
    return bit_diff * 100.0 / (h1.size() * 8);
}

double diff_hex(const std::string& h1, const std::string& h2) {
    int diff = 0;
    for (size_t i = 0; i < h1.size(); ++i)
        diff += h1[i] != h2[i];
    return diff * 100.0 / h1.size();
}

void TestuokLavinosEfekta(
    std::function<std::string(const std::string&)> HashFunkcija, size_t poru_skaicius, size_t ilgis) {
    double bit_min = 100, bit_max = 0, bit_sum = 0;
    double hex_min = 100, hex_max = 0, hex_sum = 0;

    for (size_t i = 0; i < poru_skaicius; ++i) {
        std::string s1 = random_string_generatorius(ilgis);
        std::string s2 = Keitimas_vieno_simbolio(s1);

        std::string h1 = HashFunkcija(s1);
        std::string h2 = HashFunkcija(s2);

        double bit_d = diff_bits(h1, h2);
        double hex_d = diff_hex(h1, h2);

        bit_min = std::min(bit_min, bit_d);
        bit_max = std::max(bit_max, bit_d);
        bit_sum += bit_d;

        hex_min = std::min(hex_min, hex_d);
        hex_max = std::max(hex_max, hex_d);
        hex_sum += hex_d;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Bitu lygmenyje - Min: " << bit_min << "%, Max: " << bit_max << "%, Vidurkis: " << (bit_sum / poru_skaicius) << "%\n";
    std::cout << "Hex lygmenyje - Min: " << hex_min << "%, Max: " << hex_max << "%, Vidurkis: " << (hex_sum / poru_skaicius) << "%\n";
}

void KoalizijosPatikra(int length){
    int koaliziju_kiekis = 0;
    for(int i = 0; i < 100000; ++i){
        std::string randomStr1 = random_string_generatorius(length);
        std::string randomStr2 = random_string_generatorius(length);
        if(HashFunkcija(randomStr1) == HashFunkcija(randomStr2)){
            koaliziju_kiekis++;
        }
    }
    std::cout << "Koalizaciju kiekis " << length << " simboliu: " << koaliziju_kiekis << std::endl;
}

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

    for(int kartas = 0; kartas < 34; kartas++){
        for(int i = 0; i < HASH_DYDIS; i++){
            hash[i] ^= (hash[(i+7) % HASH_DYDIS] + hash[(i+13) % HASH_DYDIS]) ^ (i * 31);
            
            int pasukimai = (3 + kartas) % 8;
            hash[i] = (hash[i] << pasukimai) | (hash[i] >> (8 - pasukimai));
            hash[i] = (hash[i] * 31 + (kartas * 17)) & 255;
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
    
    
