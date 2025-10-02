#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

LED led(LED_PIN, LED_ACT);

// khai báo callback
void btnPush();
void btnDoubleClick();


OneButton button(BTN_PIN, !BTN_ACT);

void setup()
{
    led.off();

    // single click → bật/tắt LED
    button.attachClick(btnPush);

    // double click → LED nhấp nháy
    button.attachDoubleClick(btnDoubleClick);
}

void loop()
{
    led.loop();     
    button.tick();  
}

void btnPush()
{
    // single click
    led.flip();
}

void btnDoubleClick()
{
    // double click 
    led.blink(200);
}
