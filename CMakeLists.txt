cmake_minimum_required(VERSION 3.8)

set(APP_NAME "gamos_gui")
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

file(GLOB_RECURSE SOURCES "src/*.cpp" CONFIGURE_DEPEND)
file(GLOB_RECURSE HEADERS "src/*.h" CONFIGURE_DEPEND)
set(MOC_HEADERS
    "src/BMainWindow.h"
    "src/widget/BPhantomTab.h"
    "src/widget/BHStackWidget.h"
    "src/widget/BVStackWidget.h"
    "src/widget/BStyleLabel.h"
)
find_package(Coin COMPONENTS Coin4 REQUIRED)
find_package(SoQt COMPONENTS SoQt REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets Gui Qml REQUIRED)

qt5_wrap_cpp(MOC_FILES ${MOC_HEADERS})

add_executable(${APP_NAME}
    "main_app.cpp" ${SOURCES} ${HEADERS} ${MOC_FILES}
)

target_link_libraries(${APP_NAME} PRIVATE
    Coin::Coin
    SoQt::SoQt
    Qt5::Core
    Qt5::Gui
    Qt5::Qml
    Qt5::Widgets
)

set(CPACK_PACKAGE_NAME ${APP_NAME})
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_GENERATOR "ZIP") # Loại gói (có thể là ZIP, DEB, RPM, ...)
include(CPack)
install(TARGETS ${APP_NAME} DESTINATION bin)
install(FILES ${HEADERS} DESTINATION include)
