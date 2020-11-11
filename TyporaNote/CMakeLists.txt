# CMakeList.txt : CMake project for TyporaNote, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "current platform: Linux ")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "current platform: Windows")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(CMAKE_PREFIX_PATH ~/Qt5.14.0/5.14.0/clang_64)
    MESSAGE(STATUS "current platform: Darwin")
ELSE ()
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
SET(QT_USE_QTMAIN TRUE)

find_package(Qt5Widgets)  
find_package(Qt5Core)
find_package(Qt5Gui)

FILE(GLOB SRC_FILES "./*.cpp") 
FILE(GLOB HEAD_FILES "./*.h") 
FILE(GLOB UI_FILES "./*.ui")
FILE(GLOB RCC_FILES "./*.qrc")
 
qt5_wrap_ui(WRAP_FILES ${UI_FILES})

# find_package(Qt5 COMPONENTS Widgets REQUIRED)
 
source_group("Ui" FILES ${UI_FILES} ${WRAP_FILES} )

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEAD_FILES} ${RCC_FILES} ${WRAP_FILES})

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set_property(TARGET ${PROJECT_NAME} PROPERTY WIN32_EXECUTABLE true)
endif()

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui)

