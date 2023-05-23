// HomeWork0523.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Test
{
    // 100
    int A;
    // ?????
    __int64 B;
    char C;
    char D;
    short E; // 2바이트 정수입니다.
    int F;
public:
    void Print()
    {
        printf("%llu\n", sizeof(*this));
        printf("%llu\n", (__int64)&A);
        printf("%llu\n", (__int64)&B);
        printf("%llu\n", (__int64)&C);
        printf("%llu\n", (__int64)&D);
        printf("%llu\n", (__int64)&E);
        printf("%llu\n", (__int64)&F);
        //[A][A][A][A][][][][] [B][B][B][B][B][B][B][B] [C][D][E][E][F][F][F][F]
    }
};

// 1 2 4 8

class Player
{
public:
    int HP;
    int ATT;
};

//  [H][H][H][H][A][A][A][A] //  [T][T][T][T][][][][]
void TestFunction(Player _Newplayer, int _Test)
{
    // 이것도 확인해보세요.
    printf("%llu\n", (__int64)&_Newplayer.HP);
    printf("%llu\n", (__int64)&_Newplayer.ATT);
    printf("%llu\n", (__int64)&_Test);

}

int main()
{
    Test t = Test();
    Player NewPlayer = Player();
    t.Print();
    printf("\n\n");
    TestFunction(NewPlayer, 20);
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
