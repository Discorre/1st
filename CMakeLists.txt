cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json
        GIT_TAG v3.9.1  # Укажите нужную версию
)

FetchContent_MakeAvailable(nlohmann_json)

add_executable(untitled
        delete.cpp
        delete.h
        where.cpp
        where.h
        select.cpp
        select.h
        insert.cpp
        insert.h
        supportFiles.cpp
        supportFiles.h
        readJson.cpp
        readJson.h
        myDatabaseQuery.cpp
        include/MyVector.h
        include/MyHashMap.h
        include/MyHashCode.h)

target_link_libraries(untitled PRIVATE nlohmann_json::nlohmann_json)