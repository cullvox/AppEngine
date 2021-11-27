add_subdirectory ("CBLAS")
add_subdirectory ("glfw-3.3.5") 
# GLFW may be removed as a dependency at some point
# It may become a good idea to implement platform windows in AppEngine

set (APPENGINE_REQUIRED_LIBRARY_NAMES "CBLAS, glfw-3.3.5")