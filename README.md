Yêu cầu cấu hình:
- Ubuntu >= 20
- Máy đã được cài Gamos >= 6.0

Để cài công cụ `gamos_gui` cần thực hiện 2 bước sau:

## B1 - Cài đặt công cụ đi kèm
Bước này chỉ cần thực hiện 1 lần duy nhất, những lần nâng version sau của `gamos_gui` không cần chạy lại.
Mở Terminal thực hiện lệnh dưới đây:
```sh
wget -qO- https://raw.githubusercontent.com/trungnguyenthien/gamos_qt_gui/main/scripts/install.sh | sudo bash -s
```

## B2.1 - Cài đặt (Hoặc Update) Gamos_Gui

Xác định version sẽ cài hoặc update. Ví dụ, để cài gamos_gui `1.0.0` thì chạy lệnh dưới đây:
```sh
wget -qO- https://raw.githubusercontent.com/trungnguyenthien/gamos_qt_gui/main/scripts/update.sh | sudo bash -s -- "1.0.0"
```
Lưu ý, tham số "1.0.0" có thể thay đổi tùy theo version muốn cài.

## B2.2 - Start `gamos_gui`
Mở Terminal và thực hiện lệnh
```sh
gamos_gui
```
