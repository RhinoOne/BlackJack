cmake_minimum_required(VERSION 3.16)

project(BlackJack VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appBlackJack
    main.cpp
    Managers/windowsmanagers.h
    Managers/windowsmanagers.cpp
)

qt_add_qml_module(appBlackJack
    URI BlackJack
    VERSION 1.0
    QML_FILES main.qml 
)

add_subdirectory(Modules/SpecificLayout)


set_target_properties(appBlackJack PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appBlackJack
    PRIVATE Qt6::Quick)
target_link_libraries(appBlackJack
    PRIVATE specific_layout_moduleplugin)

set(QML_IMPORT_PATH ${CMAKE_SOURCE_DIR}/Modules
    ${CMAKE_BINARY_DIR}/Modules CACHE STRING "" FORCE)

install(TARGETS appBlackJack
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
