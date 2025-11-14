set(DEEPC_SRC float.c layer.c activations.c)

add_library(deepc STATIC ${DEEPC_SRC})
set_property(TARGET deepc PROPERTY C_STANDARD 99)

target_link_libraries(deepc PUBLIC m)
target_include_directories(deepc PUBLIC ../include)
