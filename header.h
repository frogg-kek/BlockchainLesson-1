#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>

const int HASH_DYDIS = 32;

std::string FailoSkaitymas(std::string failoPav);
std::string HashFunkcija(std::string tekstas);
void GeneruotiFailus();
std::string random_string_generatorius(int ilgis);
void KoalizijosPatikra(int length);
std::string Keitimas_vieno_simbolio(std::string& tekstas);
double diff_bits(const std::string& h1, const std::string& h2);
double diff_hex(const std::string& h1, const std::string& h2);
void TestuokLavinosEfekta(
    std::function<std::string(const std::string&)> HashFunkcija,
    size_t poru_skaicius = 100000,
    size_t ilgis = 32
);
void TestPuzzleFriendliness(const std::string& input, int zeroes_needed = 2, int max_iter = 100000);
void TestHiding(const std::string& input, int test_count = 1000, int salt_length = 16);


#endif
