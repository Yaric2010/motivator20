#include "TXLib.h"


struct Play
{
    int x;
    int y;
    HDC player;
    HDC players;
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

    Play played = {24, 302, txLoadImage("mario.bmp"), txLoadImage("mario+s.bmp")};
    fon1 fonik = {0, 0, txLoadImage("fon1.bmp")};
    float i;


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

        txTransparentBlt (txDC(), played.x, played.y, 61, 78, played.player, 0, 0, TX_WHITE);

        if(GetAsyncKeyState('D') and played.x < 700)
        {
            played.x = played.x+3;
        }
        if(GetAsyncKeyState('A'))
        {
            played.x = played.x-3;
        }

        if(txGetPixel(played.x + 61, played.y + 78) != RGB(77, 113, 23))
        {

            played.y = played.y + 6;

        }



        if(GetAsyncKeyState(VK_SPACE) and txGetPixel(played.x + 61, played.y + 78) == RGB(77, 113, 23))
        {
            i = 22;
            while(i != 1)
            {
                txBitBlt (txDC(), fonik.x, fonik.y, 4988, 1736, fonik.fon);

                txTransparentBlt (txDC(), played.x, played.y, 61, 78, played.player, 0, 0, TX_WHITE);

                played.y -=i;

                if(txGetPixel(played.x + 61, played.y + 78) != RGB(77, 113, 23))
                {

                    played.y = played.y + 6;

                }

                if(GetAsyncKeyState('D') and played.x < 700)
                {
                    played.x = played.x+3;
                }

                if(GetAsyncKeyState('A'))
                {
                    played.x = played.x-3;
                }


                i -=1;
                txSleep(5);
            }
         }
        txSleep(5);
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
