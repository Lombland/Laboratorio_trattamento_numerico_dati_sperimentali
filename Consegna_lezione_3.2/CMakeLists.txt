find_package(ROOT REQUIRED COMPONENTS Hist Tree)

include(${ROOT_USE_FILE})

add_executable(myExecutable main.cpp)
target_link_libraries(myExecutable ${ROOT_LIBRARIES})
