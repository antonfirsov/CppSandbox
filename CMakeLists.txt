
project (hello)

if (MSVC)
	add_definitions(" /arch:AVX2 /std:c++14")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	add_definitions(" -std=c++14")
endif()

add_executable(hello Main.cpp Hello.cpp GlmTest.cpp GeomTest.cpp ApproximateComparerTests.cpp)

include_directories(external)

install(TARGETS hello DESTINATION hello/bin)
