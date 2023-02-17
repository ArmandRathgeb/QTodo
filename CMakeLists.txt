cmake_minimum_required(VERSION 3.25)
project(QTodo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(QTodo main.cpp qMainWindow.cpp qMainWindow.hpp qTaskWidget.cpp qTaskWidget.hpp)
target_link_libraries(QTodo
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

