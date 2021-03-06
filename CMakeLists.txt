cmake_minimum_required( VERSION 2.8 )

project( VTK_HISTOGRAM )

find_package( VTK REQUIRED )
include( ${VTK_USE_FILE} )

if( CMAKE_COMPILER_IS_GNUCXX )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall" )

  set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb3" )

  set( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG -march=native -ffast-math" )
  #to test, the 'graphite' gcc 4.4 optimizations
  #set( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG
  #-march=native -ffast-math -floop-interchange -floop-strip-mine -floop-block" )

  set( CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} -g" )
  set( CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} -O" )
endif( CMAKE_COMPILER_IS_GNUCXX )

# where all the executables go
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY
  ${VTK_HISTOGRAM_BINARY_DIR}/bin )

include_directories( ${VTK_HISTOGRAM_SOURCE_DIR}/Code )

include(CTest)
if(BUILD_TESTING)
  enable_testing()
  add_subdirectory( Testing )
endif(BUILD_TESTING)

add_subdirectory( Code )
