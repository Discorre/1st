# CMake generated Testfile for 
# Source directory: C:/Users/Dom/vscodeproj/untitled/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_import
# Build directory: C:/Users/Dom/vscodeproj/untitled/cmake-build-debug/_deps/nlohmann_json-build/test/cmake_import
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cmake_import_configure "D:/Toolbox Library/CLion/bin/cmake/win/x64/bin/cmake.exe" "-G" "Ninja" "-A" "" "-DCMAKE_CXX_COMPILER=D:/Toolbox Library/CLion/bin/mingw/bin/g++.exe" "-Dnlohmann_json_DIR=C:/Users/Dom/vscodeproj/untitled/cmake-build-debug/_deps/nlohmann_json-build" "C:/Users/Dom/vscodeproj/untitled/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_import/project")
set_tests_properties(cmake_import_configure PROPERTIES  FIXTURES_SETUP "cmake_import" _BACKTRACE_TRIPLES "C:/Users/Dom/vscodeproj/untitled/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_import/CMakeLists.txt;1;add_test;C:/Users/Dom/vscodeproj/untitled/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_import/CMakeLists.txt;0;")
add_test(cmake_import_build "D:/Toolbox Library/CLion/bin/cmake/win/x64/bin/cmake.exe" "--build" ".")
set_tests_properties(cmake_import_build PROPERTIES  FIXTURES_REQUIRED "cmake_import" _BACKTRACE_TRIPLES "C:/Users/Dom/vscodeproj/untitled/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_import/CMakeLists.txt;9;add_test;C:/Users/Dom/vscodeproj/untitled/cmake-build-debug/_deps/nlohmann_json-src/test/cmake_import/CMakeLists.txt;0;")
