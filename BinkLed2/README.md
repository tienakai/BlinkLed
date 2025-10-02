# Dual LED Control with OneButton

## Mô tả
Dự án này sử dụng ESP32, hai LED và một nút bấm.  
Chỉ với một nút nhấn duy nhất, ta có thể điều khiển hai LED theo các cách sau:

- **Single click**: Bật/tắt LED đang được chọn (LED1 hoặc LED2).
- **Hold (>1s)**: Làm LED đang được chọn nhấp nháy (200ms/lần).
- **Double click**: Chuyển đổi LED được điều khiển (giữa LED1 và LED2).

## Phần cứng
- ESP32 DevKit
- LED1: LED tích hợp trên devboard
- LED2: LED gắn ngoài (ví dụ GPIO 23)
- Button: Nút nhấn nối vào GPIO (ví dụ GPIO 22)

## Thư viện sử dụng
- [OneButton](https://github.com/mathertel/OneButton)
- Thư viện `LED.h` (tự viết bởi https://github.com/TuanPhysics/PIO-Libraries-Usage-Demo/blob/main/OneButton_Lib_Demo/lib/LED/LED.h)

## Cách chạy
- Clone repo về:  
  ```bash
  git clone https://github.com/<username>/DualLedControl.git
