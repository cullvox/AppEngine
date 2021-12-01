
file(GLOB SRC_FILES "src/*.c")

add_library(cblas STATIC ${SRC_FILES})
target_include_directories(cblas PUBLIC include)