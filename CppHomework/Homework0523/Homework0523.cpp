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
    int b;
};

//  [H][H][H][H][A][A][A][A] //  [T][T][T][T][][][][] // [t][t][t][t][][][][]
void TestFunction(Player _Newplayer, int _Test, int t, int a)
{
    // 이것도 확인해보세요.
    printf("%llu\n", (__int64)&_Newplayer.HP);
    printf("%llu\n", (__int64)&_Newplayer.ATT);
    printf("%llu\n", (__int64)&_Newplayer.b);
    printf("%llu\n", (__int64)&_Test);
    printf("%llu\n", (__int64)&t);
    printf("%llu\n", (__int64)&a);
}

int main()
{
    Test t = Test();
    Player NewPlayer = Player();
    t.Print();
    printf("\n\n");
    TestFunction(NewPlayer, 20, 30, 40);
}
