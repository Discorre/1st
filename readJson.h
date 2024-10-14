//
// Created by Dom on 14.10.2024.
//

#ifndef READJSON_H
#define READJSON_H


#include <string>


#include "include/MyHashMap.h"
#include "include/MyVector.h"

std::string ReadJsonFile(const std::string& fileName, const std::string& filePath, int& tuplesLimit, MyHashMap<std::string, MyVector<std::string>*>& jsonStructure);



#endif //READJSON_H
