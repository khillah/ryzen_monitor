set(TABLES
    pm_tables.cpp
    pm_table_0x240803_3950X.cpp
    pm_table_0x240903_3700X_3800X.cpp
    pm_table_0x380804_5900X.cpp
    pm_table_0x380805_5900X.cpp
    pm_table_0x380904_5600X.cpp
    pm_table_0x380905_5600X.cpp
    pm_table_0x400005_5700G.cpp
)

add_library(pm_tables macros.h ${TABLES} include/pm_tables/pm_tables.h)
target_include_directories(pm_tables PRIVATE include/pm_tables PUBLIC include)
