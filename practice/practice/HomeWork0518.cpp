// HomeWork0518.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
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
        return ;

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
    // �ѱ� ���� �ʽ��ϴ�.
    {
        char Arr[100] = "312312321";
        // 3�� ���;� �մϴ�.
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