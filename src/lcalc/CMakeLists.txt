cmake_minimum_required(VERSION 2.8.11)

project(lcalc)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

# Tell CMake to create the helloworld executable
add_executable(lcalc button.cpp calculator.cpp main.cpp history.cpp)

# Use the Widgets module from Qt 5.
target_link_libraries(lcalc Qt5::Widgets)

INSTALL (TARGETS lcalc RUNTIME DESTINATION /usr/bin)
