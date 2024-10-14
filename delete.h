#ifndef DELETE_H
#define DELETE_H

#include <string>
#include "include/MyVector.h"
#include "include/MyHashMap.h"

void ParsingDelete(const MyVector<std::string>& words, const std::string& filePath, const std::string& schemaName, const MyHashMap<std::string, MyVector<std::string>*>& jsonStructure);

#endif