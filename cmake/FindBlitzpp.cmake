#
# this module look for blitz++ (http://www.oonumerics.org/blitz) support
# it will define the following values
#
# BLITZ_INCLUDE_DIR = where blitz/blitz.h can be found
#
# May want to define this but seldom required
# BLITZ_LIBRARY = where blitz library can be found (reserved)
#
#IF(EXISTS ${PROJECT_CMAKE}/BlitzppConfig.cmake)
#  INCLUDE(${PROJECT_CMAKE}/BlitzppConfig.cmake)
#ENDIF(EXISTS ${PROJECT_CMAKE}/BlitzppConfig.cmake)

#SET(BLITZ_PLATFORM_INCLUDE_DIR "")

IF(Blitzpp_INCLUDE_DIRS)
  FIND_PATH(BLITZ_INCLUDE_DIR blitz/blitz.h  ${Blitzpp_INCLUDE_DIRS})
ELSE(Blitzpp_INCLUDE_DIRS)
  FIND_PATH(BLITZ_INCLUDE_DIR blitz/blitz.h $ENV{BLITZ_HOME}/include ${QMC_INCLUDE_PATHS})


ENDIF(Blitzpp_INCLUDE_DIRS)

if(BLITZ_PLATFORM_INCLUDE_DIR)
  MESSAGE(STUTUS "Platform-dependent blitz header at ${BLITZ_PLATFORM_INCLUDE_DIR}")
endif(BLITZ_PLATFORM_INCLUDE_DIR)

IF(BLITZ_INCLUDE_DIR)
  SET(BLITZ_FOUND 1 CACHE BOOL "Found blitz++ library")
  IF(CMAKE_COMPILER_IS_GNUCXX)
    FIND_PATH(BLITZ_PLATFORM_INCLUDE_DIR blitz/gnu/bzconfig.h /usr/lib64/blitz/include $ENV{BLITZ_HOME}/include ${QMC_INCLUDE_PATHS})
  ENDIF(CMAKE_COMPILER_IS_GNUCXX)
  IF(INTEL_COMPILER)
    FIND_PATH(BLITZ_PLATFORM_INCLUDE_DIR blitz/intel/bzconfig.h $ENV{BLITZ_HOME}/include ${QMC_INCLUDE_PATHS})
  ENDIF(INTEL_COMPILER)
ELSE(BLITZ_INCLUDE_DIR)
  SET(BLITZ_FOUND 0 CACHE BOOL "Found blitz++ library")
ENDIF(BLITZ_INCLUDE_DIR)

MARK_AS_ADVANCED(
   BLITZ_INCLUDE_DIR
   BLITZ_PLATFORM_INCLUDE_DIR
   BLITZ_FOUND
)
