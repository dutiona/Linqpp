set(
	source_files_headers
	../include/linqpp.hpp
)

set(
	source_files_source
	src/core.test.cpp
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/Range-V3-VS2015/include
    ${CMAKE_CURRENT_SOURCE_DIR}/H2OFastTests/inc
	${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
	$(CMAKE_SOURCE_DIR)
)

# En-têtes externes de la bibliothèque.
source_group(
	"Headers"
	FILES
	$(source_files_headers)
)

source_group(
	"Sources"
	FILES
	$(source_files_source)
)

add_executable(Tests ${source_files_headers} ${source_files_source})
set_target_properties(Tests PROPERTIES LINKER_LANGUAGE CXX)