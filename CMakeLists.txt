cmake_minimum_required (VERSION 3.8)
 
set(APP_NAME "gamos_gui")

find_package (Coin COMPONENTS Coin4 REQUIRED)
find_package (SoQt COMPONENTS SoQt REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets Qml REQUIRED)
 
add_executable (${APP_NAME} 
"main_app.cpp"
)

target_link_libraries(${APP_NAME} PRIVATE 
Coin::Coin 
SoQt::SoQt
Qt5::Core
Qt5::Gui
Qt5::Qml
Qt5::Widgets
) 
