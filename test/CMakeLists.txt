add_executable(test_float test_float.cpp)
set_property(TARGET test_float PROPERTY CXX_STANDARD 11)
target_link_libraries(test_float PRIVATE deepc)

enable_testing()
add_test(NAME test_float COMMAND test_float)
