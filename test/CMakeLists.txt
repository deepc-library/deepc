add_executable(float float.c)
target_link_libraries(float PRIVATE deepc)

add_executable(vector vector.c)
target_link_libraries(vector PRIVATE deepc)

enable_testing()
add_test(NAME test_float COMMAND float)
add_test(NAME test_vector COMMAND vector)
