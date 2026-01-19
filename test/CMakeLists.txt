add_executable(TestDenseLayer TestDenseLayer.cpp)
set_property(TARGET TestDenseLayer PROPERTY CXX_STANDARD 11)
target_link_libraries(TestDenseLayer PRIVATE deepc)

enable_testing()
add_test(NAME TestDenseLayer COMMAND TestDenseLayer)