cmake_minimum_required(VERSION 2.8.11)

project(looplorer)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Qt5WebKit)
find_package(Qt5WebKitWidgets)

# Tell CMake to create the executable
add_executable(looplorer jquery.qrc main.cpp mainwindow.cpp)

# Use the Widgets module from Qt 5.
target_link_libraries(looplorer Qt5::Widgets Qt5::WebKit Qt5::WebKitWidgets)
