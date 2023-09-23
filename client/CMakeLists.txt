cmake_minimum_required(VERSION 3.5)

project(client LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Gui Widgets Network REQUIRED)

include_directories(include)

file(GLOB SOURCES src/*.cpp src/*.ui)
file(GLOB HEADERS include/*.h)
set(RESOURCES res/resources.qrc)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    enable_language("RC")
    set(WIN32_RESOURCES res/resources.rc)
endif()

add_executable(client WIN32 ${SOURCES} ${HEADERS} ${RESOURCES} ${WIN32_RESOURCES})

target_link_libraries(client PRIVATE Qt6::Gui Qt6::Widgets Qt6::Network)
