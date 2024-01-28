cmake_minimum_required(VERSION 3.5)

project(client VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON) # Add build directory to include path

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Widgets Network)

include_directories(include)

file(GLOB SOURCES src/*.cpp src/*.ui)
file(GLOB HEADERS include/*.h)
set(RESOURCES res/resources.qrc) # Set Qt resources

# Settings for Windows
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    add_compile_definitions(APP_NAME="${PROJECT_NAME}") # Name in Windows properties
    configure_file(version.rc.in version.rc) # Set VERSIONINFO file

    # Set Windows resources
    enable_language("RC")
    set(WIN32_RESOURCES res/resources.rc ${PROJECT_BINARY_DIR}/version.rc)
endif()

# Settings for Mac OS
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    # Set Mac OS resources
    set(MACOSX_BUNDLE_ICON_FILE wic_client_icon.icns)
    set(MACOSX_RESOURCES res/wic_client_icon.icns)
    set_source_files_properties(${MACOSX_RESOURCES} PROPERTIES
        MACOSX_PACKAGE_LOCATION "Resources"
    )

    add_compile_definitions(OUTSIDE_BUNDLE="/../../../") # Path outside the Mac OS bundle

    set(CMAKE_OSX_DEPLOYMENT_TARGET "11.0") # Set minimum target to Mac OS Big Sur
endif()

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${RESOURCES} ${WIN32_RESOURCES} ${MACOSX_RESOURCES})

configure_file(config.h.in config.h) # Set config header file

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Gui Qt6::Widgets Qt6::Network)

set(APPLICATION_NAME "WIC Client")

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME ${APPLICATION_NAME}
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
    MACOSX_BUNDLE_BUNDLE_NAME ${APPLICATION_NAME}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}
)
