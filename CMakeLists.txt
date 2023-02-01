cmake_minimum_required(VERSION 3.23)
project(FirstCourseProgramming)

set(CMAKE_CXX_STANDARD 14)
find_package(Boost 1.45.0 COMPONENTS program_options REQUIRED)

add_executable(FirstCourseProgramming
        #transport/Transport.cpp
        wordCount/word_count.cpp
        wordCount/utils.cpp)

include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(FirstCourseProgramming ${Boost_LIBRARIES})
