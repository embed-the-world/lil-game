
cmake_minimum_required(VERSION 3.28)
project(simpleGame
	VERSION 0.0.1
	DESCRIPTION "simple game project"
	LANGUAGES CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# GIT get SFML
include(FetchContent)
FetchContent_Declare(SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG 3.0.2
	GIT_SHALLOW ON
	EXCLUDE_FROM_ALL
	SYSTEM)
FetchContent_MakeAvailable(SFML)

# add libraries
add_subdirectory(composer)
add_subdirectory(menu)

# add executable
add_executable(main main.cpp)

# linker
target_link_libraries(main PRIVATE composer_lib)
