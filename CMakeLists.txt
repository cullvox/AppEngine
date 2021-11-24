cmake_minimum_required (VERSION 3.12)
project (AppEngine)

# Build AppEngine
set (Sources "")
list(APPEND Sources
    "Source/Math/Vector.cpp"
    
    "Source/Containers/Array.cpp"
    "Source/Containers/LinkedList.cpp"
    "Source/Containers/String.cpp"
    
    "Source/Graphics/GraphicsDevice.cpp")

add_library(AppEngine STATIC ${Sources})

target_include_directories(AppEngine PUBLIC "Include")

# Build Examples
add_subdirectory(Examples)