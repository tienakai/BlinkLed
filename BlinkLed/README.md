# Dự án: Điều khiển LED bằng nút nhấn với ESP32 và OneButton

## 1. Giới thiệu
Dự án này minh họa cách sử dụng **ESP32**, thư viện **OneButton** và lớp **LED tự xây dựng bởi https://github.com/TuanPhysics/PIO-Libraries-Usage-Demo/blob/main/OneButton_Lib_Demo/lib/LED/LED.h** để điều khiển LED thông qua nút nhấn.

Thay vì phải xử lý chống dội (debounce) và logic thủ công, ta dùng thư viện **OneButton** để:
- Phân biệt được **single click**, **double click**, **long press**,...
- Gắn callback cho từng loại sự kiện.

Trong dự án:
- **Single click**: bật/tắt LED.
- **Double click**: LED chuyển sang chế độ nhấp nháy.

## 2. Phần cứng
- ESP32 DevKit v1 (hoặc board ESP32 tương tự).
- 1 nút nhấn (push button).
- 1 điện trở kéo (pull-up/pull-down) nếu cần.
- 1 LED + điện trở hạn dòng (220Ω–330Ω).

### Sơ đồ kết nối (ví dụ):
- `BTN_PIN` → GPIO 0 (hoặc chân tùy chọn).
- `LED_PIN` → GPIO 2 (LED ngoài, hoặc LED on-board).
- GND chung.

## 3. Phần mềm
- **PlatformIO** .
- Thư viện:
  - [OneButton](https://github.com/mathertel/OneButton)
  - LED class (tự xây dựng, có sẵn trong `lib/LED`).

### Cấu trúc thư mục (PlatformIO)
## 4. Nguyên lý hoạt động
- Khi chương trình chạy, LED mặc định tắt.
- Mỗi lần **nhấn 1 lần** → LED **đảo trạng thái** (ON/OFF).
- Khi **nhấn đúp (double click)** → LED chuyển sang chế độ **nhấp nháy** với chu kỳ 200ms.
- Chức năng nhấp nháy được quản lý bởi `led.loop()` (non-blocking).