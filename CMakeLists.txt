cmake_minimum_required (VERSION 3.12)
project (AppEngine)

set (Sources "")

list(APPEND Sources
    "Source/Containers/Array.cpp"
    "Source/Containers/LinkedList.cpp"
    "Source/Containers/String.cpp"
	"Source/Vector.cpp")

add_library(AppEngine SHARED ${Sources})

target_include_directories(AppEngine PUBLIC "Include")