cmake_minimum_required(VERSION 3.0)

project(Naca4DigitAirfoilGenerator LANGUAGES C)

add_executable(Naca4DigitAirfoilGenerator 
    main.c 
    generator.c
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Naca4DigitAirfoilGenerator m)