qt_add_library(specific_layout_module STATIC)

qt_add_qml_module(specific_layout_module
   URI Layout
   VERSION 1.0
   QML_FILES
       GridLayoutUtil.qml
   )
