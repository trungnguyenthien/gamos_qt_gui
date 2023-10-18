#qmake -project -r
#qmake gamos_qt_gui.pro
cmake .
cmake --build .
cpack
./gamos_gui "images/lung20mm(source).wrl"