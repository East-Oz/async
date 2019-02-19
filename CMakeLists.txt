cmake_minimum_required( VERSION 3.2 )

project( async VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER} )

add_library( async SHARED async.cpp async.h libasync.cpp )
add_executable( test_async test_libasync.cpp )
target_link_libraries(test_async async)


set_target_properties( async PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

install( TARGETS test_async RUNTIME DESTINATION bin)
install( TARGETS async LIBRARY DESTINATION bin)

set( CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}" )
set( CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}" )
set( CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}" )

set( CPACK_GENERATOR DEB )

set( CPACK_PACKAGE_CONTACT surdukov@gmail.com )

set( CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON )

include( CPack )

