add_library(pm_tables pm_tables.c include/pm_tables/pm_tables.h)
target_include_directories(pm_tables PRIVATE include/pm_tables PUBLIC include)
