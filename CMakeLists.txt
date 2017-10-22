project (hello)

add_executable(hello Main.cpp Hello.cpp GlmTest.cpp GeomTest.cpp)

include_directories(external)

install(TARGETS hello DESTINATION hello/bin)
