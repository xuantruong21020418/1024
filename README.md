# 1024

# Mô tả về trò chơi
Sử dụng các phím điều hướng để di chuyển các khối ghép thành số to nhất có thể! Game kết thúc khi không còn di chuyển nào khả thi.
# Hướng dẫn tải và cài đặt
Tải thư mục về máy (Download Zip hoặc dùng Git clone), mở thư mục Release rồi chạy file 1024.exe
# Ý tưởng
Tạo ra một mảng 2 chiều lưu toàn bộ tiến trình trò chơi, ứng với mỗi giá trị của phần tử sẽ được in ra khối màu khác nhau
Sử dụng các phím mũi tên để di chuyển các khối số.
Tính điểm dựa trên tổng tất cả các số hiện có trên bàn chơi.

# Các chức năng đã cài đặt

1. Hiển thị màn chơi mới (Click chuột vào nút New Game)
  Demo: https://youtube.com/shorts/btlZKALRipY
2. Di chuyển khối số ghép thành số lớn hơn
  Demo: https://youtube.com/shorts/D6JfUElYJ3A
3. Game kết thúc khi không còn di chuyển khả thi, hiển thị Game Over và bắt đầu trò chơi mới
  Demo: https://youtube.com/shorts/kUYdfaG31m0
  
# Các kỹ thuật lập trình đã sử dụng

1. Con trỏ (Xử lý các biến, hàm của thư viện SDL)
2. Mảng, vector, c string (Xử lý dữ liệu của game)
3. Class (Xử lý, quản lý các hàm của game chính)
4. Đồ hoạ (sử dụng các thư viện SDL2, SDL2_mixer, SDL2_ttf)

# Những điều rút ra và hướng phát triển tiếp theo

1. Học được nhiều hơn về cách cài đặt và sử dụng một thư viện cho một ngôn ngữ lập trình, giúp việc lập trình trở nên dễ dàng hơn
2. Học được cách quản lý bộ nhớ và xử lý rò rỉ bộ nhớ
3. Hướng phát triển tiếp theo :
  - Hiện tại, mỗi khi vẽ bàn chơi ra màn hình, phải vẽ lại toàn bộ các ô, điều này gây giảm hiệu suất game, khiến CPU phải hoạt động nhiều hơn
  - Hướng khắc phục: tạo ra texture riêng cho từng giá trị 2, 4, 8, 16... một lần duy nhất, sau đó chỉ cần render ra màn hình texture đó
  - Thêm animation khi di chuyển các khối số
  - Thêm hiệu ứng khi di chuột vào nút new game
  - Thêm High Score
