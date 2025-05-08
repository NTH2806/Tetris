# Tetris
# SDL2-Tetris-Game-INT2215-UET
### Video Demo https://youtu.be/aaAAf0G2KUw
## Table Of Contents <br />
* [Hướng dẫn cài đặt](#setup)
* [Mô tả chung](#info)
* [Các chức năng](#detail)
* [Kỹ thuật lập trình](#tech)
* [Các hướng đi trong tương lai](#future)
* [Kết luận](#summary)

* <a name="setup"/>
## 1. Hướng dẫn cài đặt
- Tải file game ở branch master <br />
- Để khởi động trò chơi, click minimi.exe hoặc ở terminal cd tới file project rồi chạy lệnh try cập file ./minimi hoặc ./minimi.exe. <br />

* <a name="info"/>
## 2. Mô tả chung <br />

### Giới thiệu
Tetris hay Xếp Hình (1984), trò chơi có 7 loại Khối Hình (Tetromino) I (thẳng đứng), J, L, O (vuông), S, T, Z ứng với 7 màu khác nhau. <br />

### Về Game Mechanics <br />
- Cấu tạo: Mỗi Khối Hình được cấu tạo từ 4 khối gạch vuông (Block). Các Khối Hình có thể xoay được các góc 90, 180, 270 độ. <br />
- Mục tiêu: Di chuyển các khối gạch đang rơi từ từ xuống trong kích thước hình chữ nhật 20 hàng x 10 cột (trên màn hình).  <br />
- Chỗ nào có gạch rồi thì không di chuyển được tới vị trí đó. <br />
- Người chơi xếp những khối hình sao cho khối hình lấp đầy 1 hàng ngang để ghi điểm và hàng ngang ấy sẽ biến mất và người chơi sẽ ghi điểm. <br />
- Người chơi thua cuộc khi Khối Hình tràn ra trên dòng khỏi Grid (Lưới). <br />

* <a name="detail"/>
## 3. Các chức năng
Để thoát game, nhấn ESC.<br />
### 1. Chức năng Play Single <br />
Chức năng cơ bản nhất của game. Chơi như trên mô tả ở help. <br />
- Bảng thông số: Lần lượt là Line (lưu trữ số dòng đã hoàn thành) và Score (điểm hiện tại).  <br />
Khi người chơi thua sẽ xuất hiện 1 bảng tổng sắp cho biết điểm số của người chơi và các kỷ lục trước. <br />

### 2. Chức năng Help <br />
Chứa thông tin cụ thể về trò chơi: 
- Cách chơi (Help) <br />
- Bản quyền (Copyright) <br />

* <a name="tech"/>
## 4. Kỹ thuật lập trình <br />
### Xây dựng trên nền tảng C++ và SDL2 bao gồm:<br />
- SDL_Mixer: Hỗ trợ xử lý âm thanh. <br />
- SDL_Ttf: Hỗ trợ xử lý fonts chữ. <br />
- Các thư viện mở rộng C++. <br />
- IDE VS Code. <br />

### Các kỹ thuật lập trình <br />
- Gồm tất cả các kỹ thuật cơ bản: <br />
- Biến (static, extern), vòng lặp, cấu trúc rẽ nhánh, mảng, chuỗi. <br />
- Con trỏ <br />
- Tách file giấu code.<br />
- Kỹ thuật duyệt mảng, sinh số ngẫu nhiên.<br />
- Các kỹ thuật, syntax của SDL.
- Kỹ thuật giải phóng bộ nhớ động. <br />

### Ứng dụng
- Thuật toán sinh Khối Hình ngẫu nhiên giảm tỷ lệ sinh 2 khối giống nhau liên tiếp. <br />
- Mỗi chức năng của game (Start, Setting, Help), mỗi Khối hình (Block) được xác định bằng 1 đối tượng (struct) riêng biệt.  <br />

- <a name="future"/>
## 5. Các hướng đi trong tương lai <br />
### Cải thiện lại các file,đặt lại tên biến cẩn thận dễ đọc hơn ,sửa lại code sao cho việc truy cập các file ảnh ,âm nhạc ,phông chữ ,.. có thể dễ dàng thay đổi cho người sử dụng code:<br />
- Thông nhất lại kiểu đặt tên biến. <br />
- Thu gọn lại các file chỉ hoạt động trong 1 vùng nhất định và hoạt động cùng nhau vào 1 file lớn để dễ quản lý hơn. <br />
- Đặt lại cách khai báo biến sao ở ngay đầu file bằng cách define nó để có thể dễ dàng thay đổi và điều chỉnh thành các file ảnh ,âm nhạc , phông chữ, .. khác. <br />
- Tối ưu lại phần kiểm tra điều kiện để giảm bớt các điều kiện thừa. <br />

### Chỉnh sửa lại phần Setting của game ,cải thiện bổ sung thêm chức năng cho Setting:<br />
- Thềm Music Volume, Thêm level, Thêm hai button reset chức năng về mặc định(do em để). <br />
- Thêm các giá trị ON - OFF cho Music. <br />
- Thêm level từ 1 đến 5 - các độ khó của game vào phần Level.<br />

* <a name="summary"/>
## 6. Kết luận
Game được viết do bản thân 100%, có sự học hỏi từ lazyfoo. <br />
### Việc hoàn thiện 1 dự án lập trình như thế này giúp em mở mang kiến thức rất nhiều.<br />
- Hiểu được mô hình phát triển 1 phần mềm kiểu thác nước: Phân tích, thiết kế, lập trình, kiểm thử, chuyển giao và bảo trì (forever). <br />
- Sử dụng thành thạo pointer, chia tách file,...<br />
- Cách dùng github.<br />
- Hình thành tư duy xử lý và giải quyết bài toán<br />
- Có thêm 1 cái nhìn tổng quan hơn về việc tạo 1 project. <br />

### Khuyết điểm <br />
- Code chưa được tối ưu hoàn toàn. <br />
- Các syntax và các file chưa được tinh gọn. <br />
- Một vài đoạn code làm mù mắt cho người đọc <br />
- Chưa hoàn thiện các chức năng cơ bản của game(thêm chỉnh âm ,chỉnh music ,...). <br />

Cuối cùng, em xin chân thành cảm ơn bố mẹ, các thầy cô và các bạn đã đồng hành cùng em trong suốt chặng đường qua để em có thể tạo nên một trò chơi thật tuyệt vời, thú vị nhưng có những phần còn thiếu sót và cần phải bổ sung. <br />
A Special Thanks To:<br />
- Cô Vương Thị Hải Yến.<br />
- Thầy Nguyễn Đức Hoàng Long.<br />
- Và các bạn lớp INT2215 11.<br />
## Em xin trân trọng cảm ơn thầy cô đã dành thời gian lắng nghe. <br />
