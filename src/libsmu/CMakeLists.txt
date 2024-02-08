add_library(smu libsmu.c include/libsmu/libsmu.h)
target_include_directories(smu PRIVATE include/libsmu PUBLIC include)
