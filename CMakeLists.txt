project (hello)

add_executable(hello hello.cpp)

include_directories(external)

install(TARGETS hello DESTINATION hello/bin)
