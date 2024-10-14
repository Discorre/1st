//
// Created by Dom on 14.10.2024.
//

#ifndef INSERT_H
#define INSERT_H

#include <string>

#include "include/MyHashMap.h"
#include "include/MyVector.h"

void ParsingInsert(const MyVector<std::string>& words, const std::string& filePath, const std::string& schemaName, const int tuplesLimit, const MyHashMap<std::string, MyVector<std::string>*>& jsonStructure);




#endif //INSERT_H
