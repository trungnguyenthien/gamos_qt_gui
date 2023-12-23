# Hàm để thêm một đường dẫn mới vào PATH
add_to_path_if_not_exists() {
    local new_path='/usr/gamos_qt_gui/dist'

    # Hàm phụ để thêm new_path vào file cấu hình
    update_path_in_file() {
        local file="$1"
        echo "Checking and updating $file"

        # Kiểm tra xem file có tồn tại không
        if [ -f "$file" ]; then
            # Kiểm tra xem new_path đã có trong file chưa
            if ! grep -q "$new_path" "$file"; then
                # Nếu chưa có, thêm vào cuối file
                echo "export PATH=\$PATH:$new_path" >> "$file"
            fi
        else
            echo "$file does not exist."
        fi
    }

    # Kiểm tra xem new_path đã có trong PATH chưa
    if [[ ":$PATH:" != *":$new_path:"* ]]; then
        # Nếu chưa, thêm vào các file cấu hình
        update_path_in_file "/home/root/.bashrc"
        update_path_in_file "/home/root/.bash_profile"
        update_path_in_file "/home/root/.profile"
    else
        echo "The path $new_path is already in PATH."
    fi
}

cd /usr
add_to_path_if_not_exists
rm -rf gamos_qt_gui.zip
rm -rf gamos_qt_gui
wget https://github.com/trungnguyenthien/gamos_qt_gui/archive/refs/tags/$1.zip -O gamos_qt_gui.zip
unzip gamos_qt_gui.zip
rm -rf gamos_qt_gui.zip
mv -f gamos_qt_gui-$1 gamos_qt_gui
cd gamos_qt_gui
bash _clean.sh
bash _build.sh
