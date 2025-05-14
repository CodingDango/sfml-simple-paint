cmake_minimum_required(VERSION 3.10)

project(SimpleSFMLPaintApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)

add_executable(main ./src/main.cpp)
     
find_package(SFML 2.6 COMPONENTS graphics audio system window REQUIRED)
target_link_libraries(main sfml-graphics sfml-audio sfml-system sfml-window)

target_include_directories(main PRIVATE ./includes)
     
target_compile_options(
    main PRIVATE 
    "-O0"
    "-Wall"
    "-ggdb"
    "-pedantic"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})