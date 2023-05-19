// HomeWork0518.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int StringCount(char* _Arr)
{

    if (_Arr == nullptr)
        return 0;

    int i = 0;
    while (_Arr[i])
        ++i;

    return i;
}

void ChangeCh(char* _Arr, char _PrevCh, char _NextCh)
{
    if (_Arr == nullptr)
        return;

    int i = 0;
    while (_Arr[i])
    {
        if (_Arr[i] == _PrevCh)
            _Arr[i] = _NextCh;
        ++i;
    }

    return;
}

int main()
{
    // 한글 들어가지 않습니다.
    {
        char Arr[100] = "312312321";
        // 3이 나와야 합니다.
        int Result = StringCount(Arr);

        int a = 0;
    }

    {
        char Arr[100] = "aaa bbb ccc";
        // "aaa bbb ccc"; => "aaa bbb ddd";
        ChangeCh(Arr, 'c', 'd');

        int a = 0;
    }
}