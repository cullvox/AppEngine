add_subdirectory ("cblas")
add_subdirectory ("glfw-3.3.5") 
add_subdirectory ("glad")
add_subdirectory ("fmt-8.0.1")
# GLFW may be removed as a dependency at some point
# It may become a good idea to implement platform windows in AppEngine

set (APPENGINE_REQUIRED_LIBRARY_NAMES "CBLAS, glad, glfw-3.3.5")