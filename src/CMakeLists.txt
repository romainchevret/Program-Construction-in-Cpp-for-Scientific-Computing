add_library(point point.cpp)
add_library(domain domain.cpp)
add_library(newton newton.cpp)
add_library(bottomCurve bottomCurve.cpp)
add_library(straightline straightline.cpp)
add_library(equation_curve equation_curve.cpp)

target_link_libraries(domain bottomCurve straightline point)
target_link_libraries(newton point)
target_link_libraries(equation_curve newton point)
target_link_libraries(bottomCurve equation_curve)

file(GLOB SOURCES_FILES *.cpp)

add_library(${CMAKE_PROJECT_NAME} ${SOURCES_FILES})