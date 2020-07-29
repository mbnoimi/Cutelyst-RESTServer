cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

file(GLOB_RECURSE SOURCES *.cpp *.h)
set(SOURCES ${SOURCES})

#add_library(ServerREST SHARED ${SOURCES})
add_executable(${PROJECT_NAME} ${SOURCES})

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)

find_package(Qt5 COMPONENTS Core Network REQUIRED)
find_package(Cutelyst2Qt5 COMPONENTS Core Wsgi REQUIRED)
target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Network
    Cutelyst::Core
    Cutelyst::WSGI
    )

