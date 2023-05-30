// ConsoleGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "ConsoleScreen.h"
#include "Player.h"
#include "Wall.h"

int main()
{
    ConsoleScreen Screen;
    bool launch = Screen.Init('*');

    Player MainPlayer;
    MainPlayer.SetPos({ Screen.XLine / 2, Screen.YLine / 2 });
    MainPlayer.SetActive(true);

    while (launch)
    {
        Screen.Update();
        Screen.Clear();
        Screen.SetPixel(MainPlayer.GetPos(), MainPlayer.ch);
        Screen.Print();
        std::cout << "남은 벽 갯수 : " << Screen.CountWall() << std::endl;
        if (0 != _kbhit()) 
        {
            MainPlayer.Input(&Screen);
        }
        Sleep(200);
    }
}