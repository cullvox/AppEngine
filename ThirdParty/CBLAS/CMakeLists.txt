
file(GLOB SRC_FILES "src/*.c")

add_library(CBLAS STATIC ${SRC_FILES})
target_include_directories(CBLAS PUBLIC include)