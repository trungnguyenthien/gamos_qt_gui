#!/bin/bash

# Kiểm tra xem có đủ tham số
if [ $# -eq 0 ]; then
    echo "Usage: $0 directory_path"
    exit 1
fi

# Thư mục cha (được truyền qua tham số đầu tiên)
parent_directory="$1"

# Xác nhận xóa tất cả thư mục con
read -p "Bạn có chắc chắn muốn xóa tất cả thư mục con trong '$parent_directory'? (y/n): " confirm
if [ "$confirm" == "y" ]; then
    # Xóa tất cả thư mục con trong thư mục cha
    find "$parent_directory" -mindepth 1 -type d -exec rm -r {} \;
    echo "Đã xóa thành công tất cả thư mục con trong '$parent_directory'."
else
    echo "Hủy bỏ xóa."
fi
