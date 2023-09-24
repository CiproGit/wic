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
set(RESOURCES res/resources.qrc) # Set Qt resources

# Set Windows resources
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    enable_language("RC")
    set(WIN32_RESOURCES res/resources.rc)
endif()

# Set Mac OS resources
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(MACOSX_BUNDLE_ICON_FILE wic_client_icon.icns)
    set(MACOSX_RESOURCES res/wic_client_icon.icns)
    set_source_files_properties(${MACOSX_RESOURCES} PROPERTIES
	MACOSX_PACKAGE_LOCATION "Resources"
    )
endif()

add_executable(client ${SOURCES} ${HEADERS} ${RESOURCES} ${WIN32_RESOURCES} ${MACOSX_RESOURCES})

target_link_libraries(client PRIVATE Qt6::Gui Qt6::Widgets Qt6::Network)

set_target_properties(client PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
