add_library(point point.cpp)
add_library(rectangle rectangle.cpp)
add_library(quadtree quadtree.cpp)

target_link_libraries(rectangle point)
target_link_libraries(quadtree rectangle point)

file(GLOB SOURCES_FILES *.cpp)

add_library(${CMAKE_PROJECT_NAME} ${SOURCES_FILES})