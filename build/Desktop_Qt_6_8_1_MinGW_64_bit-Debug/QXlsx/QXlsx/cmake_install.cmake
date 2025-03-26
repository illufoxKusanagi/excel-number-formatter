# Install script for directory: F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/trainLoggerFormatter")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "E:/QtCreatorFixed/Tools/mingw1310_64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "F:/matkul/sem_6/AppProject/trainLoggerFormatter/build/Desktop_Qt_6_8_1_MinGW_64_bit-Debug/QXlsx/QXlsx/libQXlsxQt6.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QXlsxQt6" TYPE FILE FILES
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxabstractooxmlfile.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxabstractsheet.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxabstractsheet_p.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxcellformula.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxcell.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxcelllocation.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxcellrange.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxcellreference.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxchart.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxchartsheet.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxconditionalformatting.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxdatavalidation.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxdatetype.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxdocument.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxformat.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxglobal.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxrichstring.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxworkbook.h"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/QXlsx/QXlsx/header/xlsxworksheet.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("F:/matkul/sem_6/AppProject/trainLoggerFormatter/build/Desktop_Qt_6_8_1_MinGW_64_bit-Debug/QXlsx/QXlsx/CMakeFiles/QXlsx.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "devel" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/QXlsxQt6/QXlsxQt6Targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/QXlsxQt6/QXlsxQt6Targets.cmake"
         "F:/matkul/sem_6/AppProject/trainLoggerFormatter/build/Desktop_Qt_6_8_1_MinGW_64_bit-Debug/QXlsx/QXlsx/CMakeFiles/Export/5e1a71f991ec0867fe453527b0963803/QXlsxQt6Targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/QXlsxQt6/QXlsxQt6Targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/QXlsxQt6/QXlsxQt6Targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/QXlsxQt6" TYPE FILE FILES "F:/matkul/sem_6/AppProject/trainLoggerFormatter/build/Desktop_Qt_6_8_1_MinGW_64_bit-Debug/QXlsx/QXlsx/CMakeFiles/Export/5e1a71f991ec0867fe453527b0963803/QXlsxQt6Targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/QXlsxQt6" TYPE FILE FILES "F:/matkul/sem_6/AppProject/trainLoggerFormatter/build/Desktop_Qt_6_8_1_MinGW_64_bit-Debug/QXlsx/QXlsx/CMakeFiles/Export/5e1a71f991ec0867fe453527b0963803/QXlsxQt6Targets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/QXlsxQt6" TYPE FILE FILES
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/build/Desktop_Qt_6_8_1_MinGW_64_bit-Debug/QXlsx/QXlsx/QXlsxQt6Config.cmake"
    "F:/matkul/sem_6/AppProject/trainLoggerFormatter/build/Desktop_Qt_6_8_1_MinGW_64_bit-Debug/QXlsx/QXlsx/QXlsxQt6ConfigVersion.cmake"
    )
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "F:/matkul/sem_6/AppProject/trainLoggerFormatter/build/Desktop_Qt_6_8_1_MinGW_64_bit-Debug/QXlsx/QXlsx/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
