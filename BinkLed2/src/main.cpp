#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

// Khai báo 2 LED
LED led1(LED_PIN, LED_ACT);     // LED1 (built-in hoặc LED ngoài)
LED led2(LED2_PIN, LED2_ACT);   // LED2 (mắc thêm ngoài)

// Biến để theo dõi LED nào đang được điều khiển
LED* currentLed = &led1;  // mặc định điều khiển LED1

// Khai báo button
OneButton button(BTN_PIN, !BTN_ACT);

// Callback
void btnPush();
void btnHold();
void btnDouble();

void setup()
{
    led1.off();
    led2.off();

    // Gán callback cho button
    button.attachClick(btnPush);
    button.attachLongPressStart(btnHold);
    button.attachDoubleClick(btnDouble);
}

void loop()
{
    led1.loop();
    led2.loop();
    button.tick();
}

// Single click: bật/tắt LED đang chọn
void btnPush()
{
    currentLed->flip();
}

// Long press: LED đang chọn nhấp nháy 200ms
void btnHold()
{
    currentLed->blink(200);
}

// Double click: đổi sang LED khác
void btnDouble()
{
    if (currentLed == &led1)
        currentLed = &led2;
    else
        currentLed = &led1;
}
