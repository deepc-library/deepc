add_executable(test_float test_float.cpp)
set_property(TARGET test_float PROPERTY CXX_STANDARD 11)
target_link_libraries(test_float PRIVATE deepc)

add_executable(test_activations test_activations.cpp)
set_property(TARGET test_activations PROPERTY CXX_STANDARD 11)
target_link_libraries(test_activations PRIVATE deepc m)

add_executable(test_layer test_layer.cpp)
set_property(TARGET test_layer PROPERTY CXX_STANDARD 11)
target_link_libraries(test_layer PRIVATE deepc)

enable_testing()
add_test(NAME test_float COMMAND test_float)
add_test(NAME test_activations COMMAND test_activations)
add_test(NAME test_layer COMMAND test_layer)
