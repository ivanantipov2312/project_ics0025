cmake_minimum_required(VERSION 3.10)
project(ics0025_project)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(app
	src/main.cpp
	src/states/login_state.cpp
	src/states/main_state.cpp
	src/states/order_state.cpp
)
