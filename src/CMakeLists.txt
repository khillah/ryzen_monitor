add_subdirectory(libsmu)
add_subdirectory(pm_tables)

add_executable(ryzen_monitor readinfo.c readinfo.h ryzen_monitor.c)
target_link_libraries(ryzen_monitor smu pm_tables)
