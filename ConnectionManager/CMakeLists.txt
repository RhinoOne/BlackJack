qt_add_library(connection_manager STATIC)

target_link_libraries(connection_manager
    PRIVATE Qt6::Quick)

qt_add_qml_module(connection_manager
   URI ConnectionManager
   VERSION 1.0
   SOURCES
        Manager/connectionmanager.cpp
        Manager/connectionmanager.h
        MainWindowConnection/mwcreatorconnection.h
        MainWindowConnection/mwcreatorconnection.cpp
        Interface/connection.cpp
        Interface/connection.h
   )
