add_library(smu libsmu.cpp include/libsmu/libsmu.hpp)
target_include_directories(smu PRIVATE include/libsmu PUBLIC include)
