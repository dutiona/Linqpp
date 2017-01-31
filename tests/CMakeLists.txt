set(
	source_files
	src/core.test.cpp
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../H2OFastTests/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

source_group(
	"Sources"
	FILES
	$(source_files)
)

add_executable(Tests ${source_files})
set_target_properties(Tests PROPERTIES LINKER_LANGUAGE CXX)