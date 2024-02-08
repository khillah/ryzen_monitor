add_subdirectory(libsmu)
add_subdirectory(pm_tables)

add_executable(ryzen_monitor readinfo.cpp readinfo.hpp ryzen_monitor.cpp)
target_link_libraries(ryzen_monitor smu pm_tables)
