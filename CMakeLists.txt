cmake_minimum_required(VERSION 2.8)

project( Cpp2PyZmq )

find_package( OpenCV REQUIRED )
find_package( cppzmq )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( Cpp2PyZmq main.cpp )

target_link_libraries( 
    Cpp2PyZmq ${OpenCV_LIBS} cppzmq
)
