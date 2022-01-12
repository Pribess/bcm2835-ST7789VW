#include <bcm2835.h>
#include <st7789vw.h>
#include <render.h>

#include <VGA8x8.h>

static uint8_t buff[ST7789VW_WIDTH * ST7789VW_HEIGHT * 2] = {0x00};

int main(int argc, char **argv) {
    if (!bcm2835_init()) {
        return 1;
    }
    if (ST7789VW_Init()) {
        return 1;
    }
    
    ST7789VW_Draw(buff);
    for (int cnt = 0 ; cnt < HEIGHT ; cnt++) {
        Render_Pixel(buff, 100 + cnt, 100, RGB565(255, 255, 255));
    }
    for (int cnt = 0 ; 100 + cnt < HEIGHT ; cnt++) {
        Render_Pixel(buff, 100 + cnt, 101, RGB565(255, 255, 255));
    }
    Render_Char(buff, 'X', 0, 16, 90, 1, RGB565(255, 255, 255), VGA8x8, 8);
    Render_String(buff, "TEST", 0, 24, 90, 1, RGB565(255, 255, 255), VGA8x8, 8);
    ST7789VW_Draw(buff);
    return 0;
}
