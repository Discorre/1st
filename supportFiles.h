#ifndef SUPPORTFILES_H
#define SUPPORTFILES_H

#include <string>

#include "include/MyVector.h"

int Strlen(const std::string &str);
std::string Substr(const std::string &str, int start, int end);
MyVector<std::string>* Split(const std::string &str, char delim);
void BusyTable(const std::string& path, const std::string& fileName, const int rank);

#endif