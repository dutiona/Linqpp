cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

# Standards C++14 requis.
set_property(GLOBAL PROPERTY CXX_STANDARD 14)
set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED ON)

project (Linqpp)

# Activer dossiers dans Visual
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Niveau d'avertissements 4 sous Windows.
if(MSVC)
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-long-long -pedantic")
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNOMINMAX")

set(
    source_files
	include/linqpp.hpp
)

source_group(
	"Headers"
	FILES
	include/linqpp.hpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Range-V3-VS2015/include)

add_library(Linqpp STATIC ${source_files})
set_target_properties(Linqpp PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(tests)

# add the install targets
install (FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/linqpp.hpp
         DESTINATION Linqpp)