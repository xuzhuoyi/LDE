cmake_minimum_required(VERSION 2.8.11)

project(ldecc)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)
qt5_wrap_ui(UIS_HDRS descc.ui gencc.ui lancc.ui ldecc.ui safcc.ui)
qt5_add_resources(QRCS_CPPS ldeccrc.qrc)

# Tell CMake to create the helloworld executable
add_executable(ldecc descc.cpp gencc.cpp lancc.cpp ldecc.cpp main.cpp safcc.cpp ${UIS_HDRS} ${QRCS_CPPS})

# Use the Widgets module from Qt 5.
target_link_libraries(ldecc Qt5::Widgets)

INSTALL (TARGETS ldecc RUNTIME DESTINATION /usr/bin)
