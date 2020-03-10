cmake_minimum_required(VERSION 3.13)
project(wam)


if (MSVC)
  add_definitions(-DBOOST_ASIO_DISABLE_CONCEPTS)
endif()

set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_STATIC_RUNTIME OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS "ui/")


find_package(Boost 1.71.0 COMPONENTS system filesystem regex REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(LibtorrentRasterbar REQUIRED)
find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)
find_package(Threads REQUIRED)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "include/*.h" "include/json/*.h")

include_directories("include/" "include/json")

set_target_properties(Qt5::Core PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")

add_executable(wam ${SOURCE_FILES} ${UI_FILES})

target_include_directories(wam PRIVATE include ${Boost_INCLUDE_DIR} )
target_link_libraries(wam
    Threads::Threads
    Boost::regex
    Boost::system
    Boost::filesystem
    LibtorrentRasterbar::torrent-rasterbar
    Qt5::Widgets
)

