
if (CMAKE_VERSION VERSION_LESS 2.8.3)
    message(FATAL_ERROR "Qt 5 requires at least CMake version 2.8.3")
endif()

get_filename_component(_qt5Ftp_install_prefix "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

# For backwards compatibility only. Use Qt5Ftp_VERSION instead.
set(Qt5Ftp_VERSION_STRING 5.0.0)

set(Qt5Ftp_LIBRARIES Qt5::Ftp)

macro(_qt5_Ftp_check_file_exists file)
    if(NOT EXISTS "${file}" )
        message(FATAL_ERROR "The imported target \"Qt5::Ftp\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
endmacro()


macro(_populate_Ftp_target_properties Configuration LIB_LOCATION IMPLIB_LOCATION)
    set_property(TARGET Qt5::Ftp APPEND PROPERTY IMPORTED_CONFIGURATIONS ${Configuration})

    set(imported_location "${_qt5Ftp_install_prefix}/lib/${LIB_LOCATION}")
    _qt5_Ftp_check_file_exists(${imported_location})
    set_target_properties(Qt5::Ftp PROPERTIES
        "INTERFACE_LINK_LIBRARIES" "${_Qt5Ftp_LIB_DEPENDENCIES}"
        "IMPORTED_LOCATION_${Configuration}" ${imported_location}
        # For backward compatibility with CMake < 2.8.12
        "IMPORTED_LINK_INTERFACE_LIBRARIES_${Configuration}" "${_Qt5Ftp_LIB_DEPENDENCIES}"
    )

endmacro()

if (NOT TARGET Qt5::Ftp)

    set(_Qt5Ftp_OWN_INCLUDE_DIRS "${_qt5Ftp_install_prefix}/include/" "${_qt5Ftp_install_prefix}/include/QtFtp")
    set(Qt5Ftp_PRIVATE_INCLUDE_DIRS "")

    foreach(_dir ${_Qt5Ftp_OWN_INCLUDE_DIRS})
        _qt5_Ftp_check_file_exists(${_dir})
    endforeach()

    # Only check existence of private includes if the Private component is
    # specified.
    list(FIND Qt5Ftp_FIND_COMPONENTS Private _check_private)
    if (NOT _check_private STREQUAL -1)
        foreach(_dir ${Qt5Ftp_PRIVATE_INCLUDE_DIRS})
            _qt5_Ftp_check_file_exists(${_dir})
        endforeach()
    endif()

    set(Qt5Ftp_INCLUDE_DIRS ${_Qt5Ftp_OWN_INCLUDE_DIRS})

    set(Qt5Ftp_DEFINITIONS -DQT_FTP_LIB)
    set(Qt5Ftp_COMPILE_DEFINITIONS QT_FTP_LIB)

    set(_Qt5Ftp_MODULE_DEPENDENCIES "Network;Core")

    set(_Qt5Ftp_FIND_DEPENDENCIES_REQUIRED)
    if (Qt5Ftp_FIND_REQUIRED)
        set(_Qt5Ftp_FIND_DEPENDENCIES_REQUIRED REQUIRED)
    endif()
    set(_Qt5Ftp_FIND_DEPENDENCIES_QUIET)
    if (Qt5Ftp_FIND_QUIETLY)
        set(_Qt5Ftp_DEPENDENCIES_FIND_QUIET QUIET)
    endif()
    set(_Qt5Ftp_FIND_VERSION_EXACT)
    if (Qt5Ftp_FIND_VERSION_EXACT)
        set(_Qt5Ftp_FIND_VERSION_EXACT EXACT)
    endif()

    set(Qt5Ftp_EXECUTABLE_COMPILE_FLAGS "")

    foreach(_module_dep ${_Qt5Ftp_MODULE_DEPENDENCIES})
        if (NOT Qt5${_module_dep}_FOUND)
            find_package(Qt5${_module_dep}
                5.0.0 ${_Qt5Ftp_FIND_VERSION_EXACT}
                ${_Qt5Ftp_DEPENDENCIES_FIND_QUIET}
                ${_Qt5Ftp_FIND_DEPENDENCIES_REQUIRED}
                PATHS "${CMAKE_CURRENT_LIST_DIR}/.." NO_DEFAULT_PATH
            )
        endif()

        if (NOT Qt5${_module_dep}_FOUND)
            set(Qt5Ftp_FOUND False)
            return()
        endif()

        list(APPEND Qt5Ftp_INCLUDE_DIRS "${Qt5${_module_dep}_INCLUDE_DIRS}")
        list(APPEND Qt5Ftp_PRIVATE_INCLUDE_DIRS "${Qt5${_module_dep}_PRIVATE_INCLUDE_DIRS}")
        list(APPEND Qt5Ftp_DEFINITIONS ${Qt5${_module_dep}_DEFINITIONS})
        list(APPEND Qt5Ftp_COMPILE_DEFINITIONS ${Qt5${_module_dep}_COMPILE_DEFINITIONS})
        list(APPEND Qt5Ftp_EXECUTABLE_COMPILE_FLAGS ${Qt5${_module_dep}_EXECUTABLE_COMPILE_FLAGS})
    endforeach()
    list(REMOVE_DUPLICATES Qt5Ftp_INCLUDE_DIRS)
    list(REMOVE_DUPLICATES Qt5Ftp_PRIVATE_INCLUDE_DIRS)
    list(REMOVE_DUPLICATES Qt5Ftp_DEFINITIONS)
    list(REMOVE_DUPLICATES Qt5Ftp_COMPILE_DEFINITIONS)
    list(REMOVE_DUPLICATES Qt5Ftp_EXECUTABLE_COMPILE_FLAGS)

    set(_Qt5Ftp_LIB_DEPENDENCIES "Qt5::Network;Qt5::Core")

    add_library(Qt5::Ftp STATIC IMPORTED)
    set_property(TARGET Qt5::Ftp PROPERTY IMPORTED_LINK_INTERFACE_LANGUAGES CXX)

    set_property(TARGET Qt5::Ftp PROPERTY
      INTERFACE_INCLUDE_DIRECTORIES ${_Qt5Ftp_OWN_INCLUDE_DIRS})
    set_property(TARGET Qt5::Ftp PROPERTY
      INTERFACE_COMPILE_DEFINITIONS QT_FTP_LIB)

    _populate_Ftp_target_properties(RELEASE "libQt5Ftp.a" "" )




    file(GLOB pluginTargets "${CMAKE_CURRENT_LIST_DIR}/Qt5Ftp_*Plugin.cmake")

    macro(_populate_Ftp_plugin_properties Plugin Configuration PLUGIN_LOCATION)
        set_property(TARGET Qt5::${Plugin} APPEND PROPERTY IMPORTED_CONFIGURATIONS ${Configuration})

        set(imported_location "${_qt5Ftp_install_prefix}/plugins/${PLUGIN_LOCATION}")
        _qt5_Ftp_check_file_exists(${imported_location})
        set_target_properties(Qt5::${Plugin} PROPERTIES
            "IMPORTED_LOCATION_${Configuration}" ${imported_location}
        )
    endmacro()

    if (pluginTargets)
        foreach(pluginTarget ${pluginTargets})
            include(${pluginTarget})
        endforeach()
    endif()




_qt5_Ftp_check_file_exists("${CMAKE_CURRENT_LIST_DIR}/Qt5FtpConfigVersion.cmake")

endif()
