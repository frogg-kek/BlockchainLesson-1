#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <random>

const int HASH_DYDIS = 32;

std::string FailoSkaitymas(std::string failoPav);
std::string HashFunkcija(std::string tekstas);
void GeneruotiFailus();
std::string random_string_generatorius(size_t ilgis);
void KoalizijosPatikra(size_t length);

#endif
