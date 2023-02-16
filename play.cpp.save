#include "TXLib.h"


void play()
{
    HDC fon = txLoadImage ("tanks_fon.bmp");
    HDC levels = txLoadImage ("titrs.bmp");
    HDC tank1 = txLoadImage ("tanks_1.bmp");
    int x = 0;
    int y = 0;
    int level = 1;


    txSetFillColor(TX_BLACK);
    txRectangle(0,0,800,600);
    txSleep(500);
    txBitBlt (txDC(), 0, 0, 800, 600, levels);
    txSleep(500);
    txSetColor(TX_YELLOW);
    txSelectFont ("Comic Sans MS", 80);
    txTextOut(562, 255, "1");
    txSleep(500);


    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txBitBlt (txDC(), x, 0, 8000, 600, fon);
        txTransparentBlt (txDC(), 0, 343, 254, 134, tank1, 0, 0, TX_WHITE);
        if(GetAsyncKeyState('D'))
        {
            x = x-3;
        }
        if(GetAsyncKeyState('A'))
        {
            x = x+3;
        }
        txSleep(3);

















































































































    }

    txDeleteDC (fon);
    txDeleteDC (tank1);
    txDeleteDC (levels);
}
