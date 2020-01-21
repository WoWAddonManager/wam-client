cmake_minimum_required(VERSION 3.14)
project(wam)

set(Boost_USE_STATIC_RUNTIME OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Boost 1.71.0 COMPONENTS system filesystem regex REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(LibtorrentRasterbar REQUIRED)
find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)
find_package(Threads REQUIRED)


file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "include/*.h" "include/json.cpp" "include/json/*.h")
include_directories("include/" "include/json")

set_target_properties(Qt5::Core PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")

add_executable(wam ${SOURCE_FILES} ${UI_FILES})

target_include_directories(wam PRIVATE include ${Boost_INCLUDE_DIR} ${LIBMONGOCXX_INCLUDE_DIRS} ${LIBBSONCXX_INCLUDE_DIRS})
target_link_libraries(wam
    Threads::Threads
    Boost::regex
    Boost::system
    Boost::filesystem
    LibtorrentRasterbar::torrent-rasterbar
    Qt5::Widgets
    ${LIBMONGOCXX_LIBRARIES}
    ${LIBBSONCXX_LIBRARIES}
    ${Jsoncpp_LIBRARY}
)

