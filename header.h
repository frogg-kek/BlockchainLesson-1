#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

const int HASH_DYDIS = 32;

std::string FailoSkaitymas(std::string failoPav);
std::string HashFunkcija(std::string tekstas);

#endif