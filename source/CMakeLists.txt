# Build example
add_executable(example window.cpp glew.c example.cpp vec2.cpp mat2.cpp circle.cpp rectangle.cpp)
target_link_libraries(example glfw ${GLFW_LIBRARIES} m)

add_dependencies(example glfw ${COPY_BINARY})

# Build tests
add_executable(tests tests.cpp vec2.cpp mat2.cpp circle.cpp rectangle.cpp window.cpp glew.c)
target_link_libraries(tests glfw ${GLFW_LIBRARIES})

add_executable(Mei_Uhr window.cpp glew.c dsch_mei_uhr.cpp vec2.cpp mat2.cpp circle.cpp rectangle.cpp)
target_link_libraries(Mei_Uhr glfw ${GLFW_LIBRARIES} m)
add_dependencies(Mei_Uhr glfw ${COPY_BINARY})
