// HomeWork0519.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//int ChCount = 0;
//while (_string[ChCount])
//{
//    ++ChCount;
//}

int ChCount(const char* const _string, const char Ch)
{
    if (_string == nullptr)
        return 0;

    int i = 0;
    int Count = 0;
    while (_string[i])
    {
        char c = _string[i];
        if (c == Ch)
            ++Count;
        ++i;
    }

    // for문을 돌리는건 당연한거야.

    // Ch와 같은 문자가 몇개들어있는지 세어서 리턴해주는 함수
    return Count;
}

void StrCopy(const char* const _Left, char* _Right)
{
    if (_Left == nullptr || _Right == nullptr)
        return;

    int i = 0;
    while (_Left[i])
    {
        _Right[i] = _Left[i];
        ++i;
    }
    _Right[i] = 0;
    return;
}

void TrimDelete(char* _string)
{
    if (_string == nullptr)
        return;

    char tmp[256] = {};
    int tmpCount = 0;
    int i = 0;
    while (_string[i])
    {
        if (_string[i] != ' ')
        {
            tmp[tmpCount] = _string[i];
            ++tmpCount;
        }
        ++i;
    }

    StrCopy(tmp, _string);

    return;
}




int DigitsCount(int _Number)
{
    if (_Number == 0)
        return 1;
    int Count = 0;
    while (_Number != 0) 
    {
        _Number /= 10;
        ++Count;
    }
    return Count;
}



// 가장 어려운 숙제
void NumberToString(int _Number, char* _Right)
{
    if (_Right == nullptr)
        return;

    int NumDigit = DigitsCount(_Number);
    int tmpNumArr[256] = {};
    bool isMinus = false;
    if (_Number < 0)
    {
        isMinus = true;
        _Number = -_Number;
    }

    for (int i = NumDigit - 1; i > -1; --i)
    {
        int num = _Number % 10;
        tmpNumArr[i] = num;
        _Number /= 10;
    }

    if (isMinus) 
    {
        _Right[0] = '-';
        for (int i = 0; i < NumDigit; ++i)
        {
            _Right[i+1] = tmpNumArr[i] + 48;
        }
    }
    else 
    {
        for (int i = 0; i < NumDigit; ++i)
        {
            _Right[i] = tmpNumArr[i] + 48;
        }
    }

    return;
}


int main()
{
    // 4가 리턴되어야 합니다.
    // 문자열의 마지막에 들어가는 0은 글자로 치지 않습니다.
    {
        int Result = ChCount("ab aaa ccc ddd eee", 'a');

        int a = 0;
    }

    {
        char Arr[256] = "aa  b  c dd ee";

        TrimDelete(Arr);

        // Arr "aabcddee"
        int a = 0;
    }

    {
        // 8이 리턴되게 만들어라.
        int Result = DigitsCount(1232145215);

        int a = 0;
    }

    {
        char ArrCopyText[256] = {};

        StrCopy("aaaa bbb ccc", ArrCopyText);

        int a = 0;
    }

    {
        char Result[256] = {};

        // Result = "312312";

        NumberToString(-321123, Result);

        int a = 0;
    }
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
