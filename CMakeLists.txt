cmake_minimum_required(VERSION 3.16)

project(BlackJack VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER "MainWindow/mainwindow.h"
           "GlobalData/data.h")

set(CPP    "MainWindow/mainwindow.cpp"
           "GlobalData/data.cpp")

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appBlackJack
    main.cpp
)

qt_add_qml_module(appBlackJack
    URI BlackJack
    VERSION 1.0
    SOURCES
        ${HEADER}
        ${CPP}
    QML_FILES
        MainWindow/main.qml
)


include_directories("ConnectionManager/Manager")
include_directories("ConnectionManager/MainWindowConnection")

add_subdirectory(Layout)
add_subdirectory(ConnectionManager)
add_subdirectory(WindowsManager)



set_target_properties(appBlackJack PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

set(QML_IMPORT_PATH ${CMAKE_SOURCE_DIR}/ConnectionManager
    ${CMAKE_BINARY_DIR}/ConnectionManager CACHE STRING "" FORCE)

target_link_libraries(appBlackJack
    PRIVATE Qt6::Quick)
target_link_libraries(appBlackJack
    PRIVATE specific_layout_moduleplugin)
target_link_libraries(appBlackJack
    PRIVATE connection_managerplugin)
target_link_libraries(appBlackJack
    PRIVATE windows_managerplugin)

install(TARGETS appBlackJack
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
