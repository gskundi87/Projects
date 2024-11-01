cmake_minimum_required(VERSION 3.5)

project(myVector_v2 LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
<<<<<<< Updated upstream
set(SOURCES main.cpp myVector_v2.h)
add_executable(myVector_v2 ${SOURCES})
=======

add_executable(myVector_v2 main.cpp
    vector.h
)
>>>>>>> Stashed changes

install(TARGETS myVector_v2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
