
project (hello)

if (MSVC)
	add_definitions(" /arch:AVX2")
endif()

add_executable(hello Main.cpp Hello.cpp GlmTest.cpp GeomTest.cpp ApproximateComparerTests.cpp)

include_directories(external)

install(TARGETS hello DESTINATION hello/bin)
