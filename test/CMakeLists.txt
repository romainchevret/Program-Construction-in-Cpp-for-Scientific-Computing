add_executable(main main.cpp)
add_executable(measure measure.cpp)

target_link_libraries(main domain)
target_link_libraries(measure domain)
