//
// Created by Dom on 14.10.2024.
//

#ifndef SELECT_H
#define SELECT_H



#include <string>
#include "include/MyHashMap.h"
#include "include/MyVector.h"

void ParsingSelect(const MyVector<std::string>& words, const std::string& filePath,const std::string& schemaName, const MyHashMap<std::string, MyVector<std::string>*>& jsonStructure);

#endif
