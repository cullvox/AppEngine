cmake_minimum_required (VERSION 3.12)
project (AppEngine)

# Build Required Third Party libraries
set (APPENGINE_REQUIRED_LIBRARY_NAMES "")

add_subdirectory ("ThirdParty")

# Find Required libraries

# Find not required libraries
set (APPENGINE_OPENGL ON)
set (APPENGINE_VULKAN OFF)


    # OpenGL
    
    # Vulkan
    find_package(Vulkan REQUIRED)

    if (Vulkan_FOUND)
        set (APPENGINE_VULKAN ON)
    endif ()

set(APPENGINE_BUILD_TEST ON)

# Describe current build configuration
message ("[ AppEngine Configuration ] Building required third party libraries: CBLAS, glad, glfw-3.3.5")
    
    if (APPENGINE_OPENGL)
        message ("[ AppEngine Configuration ] Found OpenGL!")
    endif ()

    if (APPENGINE_VULKAN)
        message ("[ AppEngine Configuration ] Found Vulkan!")
    endif ()

# Build AppEngine
set (Sources "")
list (APPEND Sources
    "Source/Math/Vector.cpp"
    "Source/Math/Matrix.cpp"
    
    "Source/Containers/Array.cpp"
    "Source/Containers/LinkedList.cpp"
    "Source/Containers/String.cpp"
    
    "Source/Graphics/GraphicsDevice.cpp"
    "Source/Graphics/GLFW/WindowGLFW.cpp")

if (APPENGINE_OPENGL)
    list (APPEND Sources
        "Source/Graphics/OpenGL/GraphicsDeviceOpenGL.cpp"
        "Source/Graphics/OpenGL/WindowGLFWOpenGL.cpp"
        "Source/Graphics/OpenGL/VertexBufferOpenGL.cpp")
endif()

add_library (AppEngine STATIC ${Sources})
target_include_directories (AppEngine PUBLIC "Include")

# Link required thirdparty libraries
target_link_libraries (AppEngine CBLAS glfw)

# Link found required libraries

# Link found not required libraries
if (APPENGINE_OPENGL)
    target_link_libraries (AppEngine glad)
endif ()

if (APPENGINE_VULKAN)
    target_link_libraries (AppEngine ${Vulkan_LIBRARY})
    target_include_directories (AppEngine PUBLIC ${Vulkan_INCLUDE_DIR})
endif()

# Add compile definitions
if (APPENGINE_OPENGL)
    target_compile_definitions(AppEngine PUBLIC "APPENGINE_OPENGL")
endif()

if (APPENGINE_VULKAN)
    target_compile_definitions(AppEngine PUBLIC "APPENGINE_VULKAN")
endif()

if (APPENGINE_BUILD_TEST)
    target_compile_definitions(AppEngine PUBLIC "APPENGINE_BUILD_TEST")
endif()

# Build Examples
add_subdirectory (Examples)