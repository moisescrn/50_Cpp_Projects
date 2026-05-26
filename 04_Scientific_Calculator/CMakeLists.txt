cmake_minimum_required(VERSION 3.23)

project(Calculator)

add_executable(Calculator) # name of target

target_sources(Calculator
    PRIVATE
      src/main.cpp
)

target_link_libraries(Calculator
    PRIVATE
      INC
)


add_library(INC)

target_sources(INC
    PRIVATE
    src/Calculator.cpp

    PUBLIC
      FILE_SET HEADERS
      BASE_DIRS
        include
      FILES
      include/Calculator.h
)

