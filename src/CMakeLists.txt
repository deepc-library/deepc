add_library(deepc STATIC *.c)
target_include_directories(deepc PUBLIC ../include)
target_link_libraries(deepc PUBLIC m)
