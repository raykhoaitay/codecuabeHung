import os

def clean_cpp_executables():
    # Lấy thư mục hiện tại nơi bạn đặt file script này
    current_dir = os.getcwd()
    count = 0
    total_size = 0

    print(f"--- Đang quét các file .exe tại: {current_dir} ---")

    # Duyệt qua toàn bộ thư mục và thư mục con (Recursive)
    for root, dirs, files in os.walk(current_dir):
        for file in files:
            if file.endswith(".exe"):
                file_path = os.path.join(root, file)
                base_name = os.path.splitext(file)[0]
                cpp_file = base_name + ".cpp"

                # Kiểm tra xem có file .cpp tương ứng không để tránh xóa nhầm
                if cpp_file in files:
                    file_size = os.path.getsize(file_path)
                    try:
                        os.remove(file_path)
                        print(f"Đã xóa: {file} ({file_size / 1024:.1f} KB)")
                        count += 1
                        total_size += file_size
                    except Exception as e:
                        print(f"Lỗi khi xóa {file}: {e}")

    print("------------------------------------------")
    if count > 0:
        print(f"Xong! Đã dọn dẹp {count} file .exe.")
        print(f"Tổng dung lượng giải phóng: {total_size / (1024*1024):.2f} MB")
    else:
        print("Không tìm thấy file .exe nào có file .cpp đi kèm.")

if __name__ == "__main__":
    clean_cpp_executables()
    input("\nNhấn Enter để thoát...")