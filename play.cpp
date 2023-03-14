#include "TXLib.h"


struct Play
{
    int x;
    int y;
    int xD;
    int yD;
    HDC player;
    HDC players;
    HDC dc;
};

struct fon1
{
    int x;
    int y;
    HDC fon;


};



void play()
{
    HDC levels = txLoadImage ("titrs.bmp");

    Play played = {24, 302, 0, 0, txLoadImage("mario.bmp"), txLoadImage("mario+s.bmp"), txLoadImage("D.bmp")};
    fon1 fonik = {0, 0, txLoadImage("fon1.bmp")};
    float i;
    float i2 = 0;
    int i3 = 21;
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

    while(txGetPixel(played.x, played.y) != RGB(34, 177, 76))
    {

        txBitBlt (txDC(), fonik.x, fonik.y, 4988, 1736, fonik.fon);

        if(GetAsyncKeyState(VK_SHIFT) and GetAsyncKeyState('S'))
        {
            txTransparentBlt (txDC(), played.x, played.y + 58, 61, 20, played.players, 0, 0, TX_WHITE);
        }
        else
        {
            txTransparentBlt (txDC(), played.x, played.y, 61, 78, played.player, 0, 0, TX_WHITE);
        }

        if(i2 > 0)
        {
            i2 -= 0.002;
            txSetFillColor(RGB(77, 113, 23));
            txSetColor(TX_YELLOW);
            txRectangle(played.x - 4, 411, played.x + 60, 430);
        }

        if(GetAsyncKeyState('D') and played.x <= 700 and txGetPixel(played.x + 61, played.y + 30) != RGB(77, 113, 23))
        {
            played.x = played.x+3;
        }
        if(GetAsyncKeyState('A') and txGetPixel(played.x, played.y + 30) != RGB(77, 113, 23) )
        {
            played.x = played.x-3;
        }

        if(txGetPixel(played.x - 2, played.y + 78) != RGB(77, 113, 23))
        {
            played.y = played.y + 6;
        }
        if(!GetAsyncKeyState(VK_SHIFT) and !GetAsyncKeyState('S'))
        {

            if(txGetPixel(played.x + 61, played.y ) == RGB(193, 226, 10) or txGetPixel(played.x - 2, played.y ) == RGB(193, 226, 10) or txGetPixel(played.x + 61, played.y + 78) == RGB(193, 226, 10) or txGetPixel(played.x - 2, played.y + 78) == RGB(193, 226, 10))
            {
                txSetFillColor(TX_RED);
                txRectangle(0, 0, 800, 600);

                played.x = 24;
                played.y = 302;
                fonik.x = 0;

                txSleep(200);




            }
        }


        if(GetAsyncKeyState(VK_SPACE) and txGetPixel(played.x - 2, played.y + 78)  == RGB(77, 113, 23))
        {
            i = 22;
            while(i != 1)
            {
                txBitBlt (txDC(), fonik.x, fonik.y, 4988, 1736, fonik.fon);

                txTransparentBlt (txDC(), played.x, played.y, 61, 78, played.player, 0, 0, TX_WHITE);

                played.y -=i;

                if(i2 > 0)
                {
                    i2 -= 0.002;
                    txSetFillColor(RGB(77, 113, 23));
                    txSetColor(TX_YELLOW);
                    txRectangle(played.x - 4, played.y + 78, played.x + 60, played.y + 100);
                }

                if( txGetPixel(played.x + 61, played.y + 78) != RGB(77, 113, 23) or txGetPixel(played.x - 2, played.y + 78) != RGB(77, 113, 23))
                {

                    played.y = played.y + 6;

                }

                if(GetAsyncKeyState('D') and played.x <= 700 and txGetPixel(played.x + 61, played.y + 30) != RGB(77, 113, 23))
                {
                    played.x = played.x+3;
                }

                if(GetAsyncKeyState('A') and txGetPixel(played.x, played.y + 30) != RGB(77, 113, 23))
                {
                    played.x = played.x-3;
                }

                if(!GetAsyncKeyState(VK_SHIFT) and !GetAsyncKeyState('S') and txGetPixel(played.x + 61, played.y ) == RGB(193, 226, 10) or txGetPixel(played.x - 2, played.y ) == RGB(193, 226, 10) or txGetPixel(played.x + 61, played.y + 78) == RGB(193, 226, 10) or txGetPixel(played.x - 2, played.y + 78) == RGB(193, 226, 10) )
                {
                    i2 = 0;
                    txSetFillColor(TX_RED);
                    txRectangle(0, 0, 800, 600);

                    played.x = 24;
                    played.y = 302;
                    fonik.x = 0;

                    txSleep(200);



                }

                i -=1;
                txSleep(5);
            }txBitBlt (txDC(), fonik.x, fonik.y, 4988, 1736, fonik.fon);
            txTransparentBlt (txDC(), played.x, played.y, 61, 78, played.player, 0, 0, TX_WHITE);
         }

        if(GetAsyncKeyState(VK_SHIFT) and GetAsyncKeyState('D') and !GetAsyncKeyState('S'))
        {
            played.xD = played.x - 10;
            played.yD = played.y - 30;
            while(played.yD > 0)
            {
                txBitBlt (txDC(), fonik.x, fonik.y, 4988, 1736, fonik.fon);
                txTransparentBlt (txDC(), played.xD, played.yD, 100, 61, played.dc, 0, 0, TX_WHITE);
                txTransparentBlt (txDC(), played.x, played.y, 61, 78, played.player, 0, 0, TX_WHITE);
                played.xD += 3;
                played.yD -= 3;

                if(txGetPixel(played.xD + 100, played.yD) == RGB(237, 28, 36) or txGetPixel(played.xD + 100, played.yD+ 10) == RGB(237, 28, 36))
                {
                    i2 = 1;
                    played.xD = 20;
                    played.yD = -10;
                }


                txSleep(2);

            }
        }



        if(txGetPixel(played.x + 61, played.y + 78) == RGB(63, 72, 204))
        {

            while(i3 != 1)
            {
                txBitBlt (txDC(), fonik.x, fonik.y, 4988, 1736, fonik.fon);
                txTransparentBlt (txDC(), played.x, played.y, 61, 78, played.player, 0, 0, TX_WHITE);
                played.x +=10;
                played.y -= i3;
                i3 -=1;
                txSleep(5);

            }
            for(int i = 0; i < 40; i++)
            {
                played.y = played.y + 6;
                played.x +=10;
                txBitBlt (txDC(), fonik.x, fonik.y, 4988, 1736, fonik.fon);
                txTransparentBlt (txDC(), played.x, played.y, 61, 78, played.player, 0, 0, TX_WHITE);
                txSleep(5);
                if(played.x + 61 > 699)
                {

                    for(int i = 0; i < 100; i += 1)
                    {
                        txBitBlt (txDC(), fonik.x, fonik.y, 4988, 1736, fonik.fon);
                        txTransparentBlt (txDC(), played.x, played.y, 61, 78, played.player, 0, 0, TX_WHITE);
                        txSetFillColor(RGB(77, 113, 23));
                        txSetColor(RGB(77, 113, 23));
                        txRectangle(played.x - 2, 411, played.x + 60, 430);
                        fonik.x -= 6;
                        played.x -= 6;
                        txSleep(1);
                    }
                }
            }
        }

        txSleep(5);

        if(played.x + 61 > 699)
        {

            for(int i = 0; i < 100; i += 1)
            {
                txBitBlt (txDC(), fonik.x, fonik.y, 4988, 1736, fonik.fon);
                txTransparentBlt (txDC(), played.x, played.y, 61, 78, played.player, 0, 0, TX_WHITE);
                txSetFillColor(RGB(77, 113, 23));
                txSetColor(RGB(77, 113, 23));
                txRectangle(played.x - 2, 411, played.x + 60, 430);
                fonik.x -= 6;
                played.x -= 6;
                txSleep(1);
            }
        }
    }






    /*
        txTransparentBlt (txDC(), 0, 343, 254, 134, tank1, 0, 0, TX_WHITE);
        if(GetAsyncKeyState('D'))
        {
            x = x-3;
        }
        if(GetAsyncKeyState('A'))
        {
            x = x+3;
        }  */
}
