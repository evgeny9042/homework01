cmake_minimum_required(VERSION 3.2)

project(helloworld VERSION 0.0.2)

configure_file(version.h.in ${CMAKE_CURRENT_BINARY_DIR}/my_version.h)

add_executable(helloworld main.cpp)
add_library(mylibrary lib.cpp)

target_include_directories(mylibrary PRIVATE 
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(helloworld PRIVATE
    mylibrary
)

set_target_properties(helloworld PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

install(TARGETS helloworld RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT egavrilin90@gmail.com)

include(CPack)
