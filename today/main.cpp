#include "TXLib.h"

int main()
{
    int X_mouse = 0;
    int Y_mouse = 0;
    int i = 0;

    HDC  menu = txLoadImage ("menu.bmp");
    HDC  login = txLoadImage ("login.bmp");

    txCreateWindow(800, 600);

    txDisableAutoPause();
    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        X_mouse = txMouseX();
        Y_mouse = txMouseY();

        txBitBlt (txDC(), 0, 0, 800, 600, menu);



        if(X_mouse > 100 and X_mouse < 325 and Y_mouse > 214 and Y_mouse < 269 and txMouseButtons() == 1)
        {

            txBitBlt (txDC(), 0, 0, 800, 600, login);
            while(!GetAsyncKeyState('Q') or !GetAsyncKeyState('W'))
            {

            }
        }


    }

    txDeleteDC (menu);
    txDeleteDC (login);





    txTextCursor (false);
    return 0;
}

