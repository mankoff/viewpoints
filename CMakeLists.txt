cmake_minimum_required(VERSION 2.8)
project(viewpoints)

set (CPACK_INSTALL_PREFIX "/usr")
set (${PROJECT_NAME}_VERSION_MAJOR 0)
set (${PROJECT_NAME}_VERSION_MINOR 1)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(FLTK REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GSL REQUIRED)
find_package(Blitzpp REQUIRED)
find_package(CFITSIO REQUIRED)
find_package(ROOT REQUIRED)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.46 COMPONENTS system serialization REQUIRED)

SET (CMAKE_C_FLAGS                "-std=c99 -pedantic -O0 -g3 -Wall -W -fPIC")
SET (CMAKE_C_FLAGS_DEBUG          "-std=c99 -pedantic -O0 -g3 -fPIC")
SET (CMAKE_C_FLAGS_MINSIZEREL     "-std=c99 -pedantic -Os -DNDEBUG -fPIC")
SET (CMAKE_C_FLAGS_RELEASE        "-std=c99 -pedantic -O3 -DNDEBUG -fPIC")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO "-std=c99 -pedantic -O2 -g2 -fPIC")

SET (CMAKE_CXX_FLAGS                "-std=c++11 -pedantic -O0 -g3 -Wall -Wextra -Wshadow -Wunused-variable -Wunused-parameter -Wunused-function -Wunused -Wno-system-headers -Wno-deprecated -Woverloaded-virtual -Wwrite-strings -fPIC")
SET (CMAKE_CXX_FLAGS_DEBUG          "-std=c++11 -pedantic -O0 -g3 -Wall -Wextra -Wshadow -Wunused-variable -Wunused-parameter -Wunused-function -Wunused -Wno-system-headers -Wno-deprecated -Woverloaded-virtual -Wwrite-strings -fPIC")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-std=c++11 -pedantic -Os -DNDEBUG -fPIC")
SET (CMAKE_CXX_FLAGS_RELEASE        "-std=c++11 -pedantic -O3 -DNDEBUG -fPIC")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-std=c++11 -pedantic -O2 -g2 -fPIC")

IF(APPLE)
	SET(CMAKE_CXX_LINK_FLAGS "-framework OpenGL -framework GLUT")
ENDIF(APPLE)


IF(NOT CMAKE_BUILD_TYPE)
	SET(CMAKE_BUILD_TYPE DEBUG
		CACHE STRING "Choose the type of build : NONE DEBUG RELEASE RELWITHDEBINFO MINSIZEREL."
    FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

message("* Current build type is  : * ${CMAKE_BUILD_TYPE} *")
message("** NONE                  : * ${CMAKE_CXX_FLAGS} *")
message("** DEBUG                 : * ${CMAKE_CXX_FLAGS_DEBUG} *")
message("** MINSIZEREL            : * ${CMAKE_CXX_FLAGS_MINSIZEREL} *")
message("** RELEASE               : * ${CMAKE_CXX_FLAGS_RELEASE} *")
message("** RELWITHDEBINFO        : * ${CMAKE_CXX_FLAGS_RELWITHDEBINFO} *")

#if(${CMAKE_BUILD_TYPE} MATCHES "NONE")
#  set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}")
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
#elseif (${CMAKE_BUILD_TYPE} MATCHES "DEBUG")
#  set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS_DEBUG}")
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}")
#elseif (${CMAKE_BUILD_TYPE} MATCHES "RELEASE")
#  set(CMAKE_C_FLAGS   "-g0 ${CMAKE_C_FLAGS_RELEASE}")
#  set(CMAKE_CXX_FLAGS "-g0 ${CMAKE_CXX_FLAGS_RELEASE}")
#elseif (${CMAKE_BUILD_TYPE} MATCHES "RELWITHDEBINFO")
#  set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS_RELWITHDEBINFO}")
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
#elseif (${CMAKE_BUILD_TYPE} MATCHES "MINSIZEREL")
#  set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS_MINSIZEREL}")
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_MINSIZEREL}")
#elseif ()
#  message("Build type: ${CMAKE_BUILD_TYPE} is not known; defaulting to DEBUG")
#  set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS_DEBUG}")
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}")
#endif()

#message("** C   FLAGS             : * ${CMAKE_C_FLAGS} *")
#message("** CXX FLAGS             : * ${CMAKE_CXX_FLAGS} *")

#configure_file (
#  "${PROJECT_SOURCE_DIR}/inc/config.h.in"
#  "${PROJECT_BINARY_DIR}/config.h"
#)

include_directories(${Blitz_INCLUDE_DIR}
                    ${GSL_INCLUDE_DIR}
                    ${Boost_INCLUDE_DIRS}
                    ${OPENGL_INCLUDE_DIRS}
                    ${GLUT_INCLUDE_DIRS}
                    ${CFITSIO_INCLUDE_DIR}
                    ${ROOT_INCLUDE_DIR})


include_directories(${PROJECT_SOURCE_DIR}/inc)
include_directories(${PROJECT_SOURCE_DIR}/fl_flews)
include_directories(${PROJECT_BINARY_DIR})

add_subdirectory(fl_flews)
add_subdirectory(src)




