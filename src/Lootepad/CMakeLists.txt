cmake_minimum_required(VERSION 2.8.11)

project(Lootepad)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Find the QtWidgets library
find_package(Qt5Widgets)
qt5_wrap_ui(UIS_HDRS mainwindow.ui)
qt5_add_resources(QRCS_CPPS rc.qrc)

# Tell CMake to create the helloworld executable
add_executable(lootepad main.cpp mainwindow.cpp texteditor.cpp textedittab.cpp ${UIS_HDRS} ${QRCS_CPPS})

# Use the Widgets module from Qt 5.
target_link_libraries(lootepad Qt5::Widgets)

INSTALL (TARGETS lootepad RUNTIME DESTINATION /usr/bin)
