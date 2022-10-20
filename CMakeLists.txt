# CMakeList.txt: проект CMake для media_button; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("media_button")


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable (media_button "media_button.cpp" "media_button.h" "main.cpp")

set(CMAKE_PREFIX_PATH "F:\\Qt\\5.12.12\\msvc2017_64\\lib\\cmake")
find_package( Qt5 COMPONENTS
    Core
    Gui
    Widgets
    Multimedia
    MultimediaWidgets
REQUIRED)

target_link_libraries(media_button
Qt5::Core
Qt5::Gui
Qt5::Widgets
Qt5::MultimediaWidgets
Qt5::Multimedia)

