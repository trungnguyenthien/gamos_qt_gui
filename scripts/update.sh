cd /usr
rm -rf gamos_qt_gui
wget http://example.com/path/to/file.zip -O gamos_qt_gui.zip

git clone https://github.com/trungnguyenthien/gamos_qt_gui.git
cd gamos_qt_gui
bash _clean.sh
bash _build.sh