#qmake -project -r
#qmake gamos_qt_gui.pro
cmake .
cmake --build .
./gamos_gui "images/lung20mm(source).wrl"