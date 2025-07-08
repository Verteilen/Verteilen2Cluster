cmake_minimum_required( VERSION 3.22 )

project(Vertelien2Cluster LANGUAGES CXX)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/ )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY obj/ )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY archive/ )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SQLite3 REQUIRED)

file(GLOB_RECURSE SRC
		src/**.h
		src/**.hpp
		src/**.c
		src/**.cpp
)

source_group(TREE src FILES ${SRC})
add_executable(Vertelien2Cluster ${SRC}
		src/model/Database.cpp
		src/model/Database.h
		src/model/Job.cpp
		src/model/Job.h)
target_link_libraries(Vertelien2Cluster PRIVATE
		SQLite::SQLite3
		"${CMAKE_HOME_DIRECTORY}/lib/Verteilen2Core/cmake-build-debug/archive/libVertelien2Core.a"
)
target_include_directories(Vertelien2Cluster PUBLIC
		"lib/sqlite3/include"
		"lib/Verteilen2Core/include"
)