# Picked and modified from: http://osdir.com/ml/kde-commits/2010-05/msg09988.html
# Another reference point: http://code.google.com/p/createtetzone/
# Locate the Google C++ Mocking Framework.

set (GMOCK_FOUND FALSE)
find_program(GMOCK-CONFIG_EXECUTABLE NAMES gmock-config PATHS)

if(GMOCK-CONFIG_EXECUTABLE)
	exec_program(${GMOCK-CONFIG_EXECUTABLE} ARGS --includedir OUTPUT_VARIABLE GOOGLEMOCK_INCLUDE_DIR)
	exec_program(${GMOCK-CONFIG_EXECUTABLE} ARGS --ldflags OUTPUT_VARIABLE GOOGLEMOCK_LDFLAGS)
	exec_program(${GMOCK-CONFIG_EXECUTABLE} ARGS --libs OUTPUT_VARIABLE GOOGLEMOCK_libs_tmp)
	set(GOOGLEMOCK_LIBRARIES ${GOOGLEMOCK_LDFLAGS} ${GOOGLEMOCK_libs_tmp})
endif()

if(GOOGLEMOCK_INCLUDE_DIR AND GOOGLEMOCK_LIBRARIES)
	set(GMOCK_FOUND TRUE)
endif()

if (NOT ${GMOCK_FOUND})
	message (FATAL_ERROR "GMOCK not found!")
endif ()
