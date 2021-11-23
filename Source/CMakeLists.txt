set (Sources "")

list(APPEND Sources
    "Array.cpp"
    "Vector.cpp")

add_library(AppEngine SHARED ${Sources})