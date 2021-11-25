cmake_minimum_required (VERSION 3.12)
project (AppEngine)

# Build Third Party libraries
add_subdirectory ("ThirdParty")

# Build AppEngine
set (Sources "")
list (APPEND Sources
    "Source/Math/Vector.cpp"
    "Source/Math/Matrix.cpp"
    
    "Source/Containers/Array.cpp"
    "Source/Containers/LinkedList.cpp"
    "Source/Containers/String.cpp"
    
    "Source/Graphics/GraphicsDevice.cpp")

add_library (AppEngine STATIC ${Sources})

target_include_directories (AppEngine PUBLIC "Include")
target_link_libraries (AppEngine CBLAS)

# Build Examples
add_subdirectory (Examples)