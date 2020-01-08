cmake_minimum_required(VERSION 3.14)
project(wam)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.71.0 COMPONENTS system filesystem regex REQUIRED)
find_package(libmongocxx REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(libbsoncxx REQUIRED)
find_package(LibtorrentRasterbar REQUIRED)
find_package(Threads REQUIRED)
#SET(CMAKE_PREFIX_PATH /home/jordan/Qt/5.12.6/gcc_64 ${CMAKE_PREFIX_PATH})

include_directories(include/json)



file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "include/*.h" "include/json.cpp" "include/json/*.h")

include_directories("include/")
set_target_properties(Qt5::Core PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")

add_executable(wam ${SOURCE_FILES})

target_include_directories(wam PRIVATE include ${Boost_INCLUDE_DIR} ${LIBMONGOCXX_INCLUDE_DIRS} ${LIBBSONCXX_INCLUDE_DIRS})
target_link_libraries(wam
    Threads::Threads
    Boost::regex
    Boost::system
    Boost::filesystem
    LibtorrentRasterbar::torrent-rasterbar
    Qt5::Widgets
    ${Boost_LIBRARIES}
    ${LIBMONGOCXX_LIBRARIES}
    ${LIBBSONCXX_LIBRARIES}
    ${Jsoncpp_LIBRARY}
)
file(GLOB_RECURSE UI_FILES "ui/*.ui")
set(QT_UIC_EXECUTABLE /usr/bin/uic)
qt5_wrap_ui(wam UI_FILES ${UI_FILES} "-o include")
