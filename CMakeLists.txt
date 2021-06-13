cmake_minimum_required(VERSION 3.0.0)
project(Enigma VERSION 0.1.0)

include(CTest)
enable_testing()

add_compile_options(-Wall -Wextra -Wpedantic)

add_library(
	EnigmaLib
	STATIC
	src/Enigma/src/PlugBoard.cpp
	src/Enigma/src/Rotor.cpp
	src/Enigma/src/Reflector.cpp
	src/Enigma/src/EnigmaMachine.cpp
	src/Enigma/src/utils.cpp
)
set_target_properties(EnigmaLib PROPERTIES PUBLIC_HEADER src/Enigma/headers/Plugboard.h)
set_target_properties(EnigmaLib PROPERTIES PUBLIC_HEADER src/Enigma/headers/Rotor.h)
set_target_properties(EnigmaLib PROPERTIES PUBLIC_HEADER src/Enigma/headers/Reflector.h)
set_target_properties(EnigmaLib PROPERTIES PUBLIC_HEADER src/Enigma/headers/EnigmaMachine.h)
set_target_properties(EnigmaLib PROPERTIES PUBLIC_HEADER src/Enigma/headers/config.h)
set_target_properties(EnigmaLib PROPERTIES PUBLIC_HEADER src/Enigma/headers/utils.h)
target_include_directories(EnigmaLib PUBLIC .)

# Can use this if you want to bundle everything together
add_executable(Enigma src/main.cpp)
target_link_libraries(Enigma EnigmaLib)
target_include_directories(Enigma PUBLIC .)
target_compile_features(Enigma PRIVATE cxx_std_17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

file(GLOB test_files "tests/test_*.cpp")

add_compile_options(-Wall -Wextra -Wpedantic -I ${CMAKE_SOURCE_DIR})

foreach(file ${test_files})
	string(REGEX REPLACE "(^.*/|\\.[^.]*$)" "" file_without_ext ${file})
	add_executable(${file_without_ext} ${file})
	target_link_libraries(${file_without_ext} EnigmaLib)
	target_compile_features(${file_without_ext} PRIVATE cxx_std_17)
	add_test(${file_without_ext} ${file_without_ext})
endforeach()
