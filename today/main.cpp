#include "TXLib.h"
#include <iostream>
#include <fstream>
#include <string>

int X_mouse = 0;
int Y_mouse = 0;
int p = 0;
std::string a = "";
HDC  menu = txLoadImage ("menu.bmp");
HDC  login = txLoadImage ("login.bmp");
HDC  ball = txLoadImage ("ball.bmp");

std::string line;



struct play
{
   int x;
   int y;
   HDC left;
   HDC right;
   HDC image;
   int vx;
   int vy;

};





void boll()
{
    txBitBlt (txDC(), 0, 0, 800, 600, ball);
    std::string prog1;
    std::ifstream in("morning.txt"); // �������� ���� ��� ������
    while(true)
    {
        if (in.is_open())
        {
            while (getline(in, prog1))
            {
                cout << prog1 << std::endl;
            }
        }

       //txTextOut (100, 100, prog1);

    }


}





int main()
{
  //  play player = {0, 0, };
    txCreateWindow(800, 600);



    std::ofstream out;          // ����� ��� ������
    out.open("parol.txt");

    if (out.is_open())
    {
        out << "FAS" << std::endl;
    }

    std::ofstream morning1;          // ����� ��� ������
    out.open("morning.txt");

    if (out.is_open())
    {
        out << "��������� ����" << std::endl;
    }

    txDisableAutoPause();

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        X_mouse = txMouseX();
        Y_mouse = txMouseY();

        txBitBlt (txDC(), 0, 0, 800, 600, menu);



        if(X_mouse > 100 and X_mouse < 325 and Y_mouse > 214 and Y_mouse < 269 and txMouseButtons() == 1)
        {
            a = "";
            p = 0;
            txBitBlt (txDC(), 0, 0, 800, 600, login);

            while(p==0)
            {



                if(GetAsyncKeyState('A'))
                {
                    a = a += 'A';
                }
                else if(GetAsyncKeyState('Q'))
                {
                    a = a += 'Q';
                }
                else if(GetAsyncKeyState('W'))
                {
                    a = a += 'W';
                }
                else if(GetAsyncKeyState('S'))
                {
                    a = a += 'S';
                }
                else if(GetAsyncKeyState('E'))
                {
                    a = a += 'E';
                }
                else if(GetAsyncKeyState('D'))
                {
                    a = a += 'D';
                }
                else if(GetAsyncKeyState('R'))
                {
                    a = a += 'R';
                }
                else if(GetAsyncKeyState('F'))
                {
                    a = a += 'F';
                }
                else if(GetAsyncKeyState('T'))
                {
                    a = a += 'T';
                }
                else if(GetAsyncKeyState('G'))
                {
                    a = a += 'G';
                }
                else if(GetAsyncKeyState('Y'))
                {
                    a = a += 'Y';
                }
                else if(GetAsyncKeyState('H'))
                {
                    a = a += 'H';
                }
                else if(GetAsyncKeyState('U'))
                {
                    a = a += 'U';
                }
                else if(GetAsyncKeyState('J'))
                {
                    a = a += 'J';
                }
                else if(GetAsyncKeyState('I'))
                {
                    a = a += 'I';
                }
                else if(GetAsyncKeyState('K'))
                {
                    a = a += 'K';
                }
                else if(GetAsyncKeyState('O'))
                {
                    a = a += 'O';
                }

                std::ifstream in("parol.txt"); // �������� ���� ��� ������
                if (in.is_open())
                {
                    while (getline(in, line))
                    {
                        if (line == a)
                        {
                            p=1;

                        }
                        cout << a << std::endl;
                    }
                }
                in.close();
                txSleep(500);

             }
         boll();
         }
    }






    txDeleteDC (menu);
    txDeleteDC (login);
    txDeleteDC (ball);





    txTextCursor (false);
    return 0;
}

