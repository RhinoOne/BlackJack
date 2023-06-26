qt_add_library(windows_manager STATIC)

target_link_libraries(windows_manager
    PRIVATE Qt6::Quick)
qt_add_qml_module(windows_manager
    URI WindowsManager
    VERSION 1.0
    SOURCES
    windowsmanager.cpp
    windowsmanager.h
)
