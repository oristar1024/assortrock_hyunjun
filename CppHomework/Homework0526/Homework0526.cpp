﻿// ConsoleGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "ConsoleScreen.h"
#include "Player.h"
#include "Wall.h"
#include <crtdbg.h>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    ConsoleScreen Screen;
    bool launch = Screen.Init('*');

    Player MainPlayer;
    MainPlayer.SetPos({ Screen.XLine / 2, Screen.YLine / 2 });
    MainPlayer.SetActive(true);
    {
        _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
        int* a = new int(10);
        a = new int(20);
        int b = 0;
    }

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