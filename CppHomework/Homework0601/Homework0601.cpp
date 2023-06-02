// List.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <list>
#include <vector>
#include <assert.h>

// 1. Push_front를 만들어보세요.
// 2. leck 잡으세요

// 벡터에는 왜 push_front

using DataType = int;

// public <= 니맘대로 수정해.
//Player NewPlayer;
//NewPlayer.Hp = 0;

class HList
{
private:
	// 외부에 공개할 생각이 전혀 없어요.
	// 이 node를 공개하게 되면
	// 얼마든지 외부에서 이 자료구조에서 구조를 깨버릴수가 있다는 이야기이다.
	// 절대로 외부에 공개할수는 없다.
	// 공개하는 순간. 
	class ListNode
	{
	public:
		DataType Value = 0;
		ListNode* Prev = nullptr;
		ListNode* Next = nullptr;
	};


public:
	// 외부에 공개하기 위한 인터페이스
	// 인터페이스 인터페이스 인터페이스 =>
	// 함수 클래스 변수 
	// 외부에 공개하는 함수 => 인터페이스
	// 거시기 == 인터페이스
	// 그거있잖아 그거 할때 그거 => 인터페이스
	class iterator
	{
		friend HList;

	private:
		ListNode* CurNode = nullptr;

	public:
		iterator()
		{

		}

		iterator(ListNode* _Node)
			: CurNode(_Node)
		{

		}

		bool operator !=(const iterator& _Other)
		{
			return CurNode != _Other.CurNode;
		}

		iterator& operator ++()
		{
			CurNode = CurNode->Next;
			return *this;
		}

		DataType& operator*()
		{
			return CurNode->Value;
		}
	};

	HList()
	{
		StartNode = new ListNode();
		EndNode = new ListNode();

		// 이게 더미 노드 방식
		StartNode->Next = EndNode;
		EndNode->Prev = StartNode;
	}

	// void Push_front를 만들어보세요.
	void push_back(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		ListNode* PrevNode = EndNode->Prev;

		PrevNode->Next = NewNode;
		EndNode->Prev = NewNode;

		NewNode->Next = EndNode;
		NewNode->Prev = PrevNode;
	}

	void push_front(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		ListNode* PrevNode = StartNode->Next;

		PrevNode->Prev = NewNode;
		StartNode->Next = NewNode;

		NewNode->Prev = StartNode;
		NewNode->Next = PrevNode;

	}

	iterator erase(const iterator& _Iter)
	{
		ListNode* Node = _Iter.CurNode;

		// 터져야 한다.
		if (StartNode == Node
			|| EndNode == Node)
		{
			assert(false);
			return iterator(EndNode);
		}

		// 삭제할때 언제나 내가 정리하거나 잃어버려서 곤란한 데이터들이
		// 존재하는지를 언제나 확인하셔야 합니다.
		// 정리할게 있나 없나를 확인해야 한다.

		ListNode* NextNode = Node->Next;
		ListNode* PrevNode = Node->Prev;

		PrevNode->Next = NextNode;
		NextNode->Prev = PrevNode;

		if (nullptr != Node)
		{
			delete Node;
		}

		return iterator(NextNode);
	}

	iterator begin()
	{
		return iterator(StartNode->Next);
	}

	iterator end()
	{
		return iterator(EndNode);
	}

	~HList()
	{
		if (StartNode == nullptr)
			return;

		ListNode* cur = StartNode;
		ListNode* next = StartNode->Next;

		while (next != nullptr)
		{
			delete cur;
			cur = next;
			next = next->Next;
		}
		delete EndNode;
	}

private:
	ListNode* StartNode;
	ListNode* EndNode;
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	{
		std::vector<int> Test;

		// 노드형 시퀀스 자료구조
		std::list<int> NewList;

		for (size_t i = 0; i < 10; i++)
		{
			// 리스트만 가지고 있는 함수인데.
			NewList.push_back(i);
		}

		// NewList.erase()

		std::list<int>::iterator StartIter = NewList.begin();
		std::list<int>::iterator EndIter = NewList.end();

		StartIter = NewList.erase(StartIter);

		for (; StartIter.operator!=(EndIter); ++StartIter)
		{
			// std::cout << (*StartIter) << std::endl;
		}
	}

	{
		// 노드형 시퀀스 자료구조
		HList NewList;
		// 프로그래밍에서는
		// 어떤 클래스가 있을때 그걸 사용하는 모든 방법
		// NewList.push_back

		for (int i = 0; i < 10; i++)
		{
			NewList.push_front(i);
		}

		// 내가 5번째부터 시작한다
		// 불가능

		HList::iterator StartIter = NewList.begin();
		HList::iterator EndIter = NewList.end();

		HList::iterator EraseIter = NewList.begin();

		++EraseIter;
		++EraseIter;
		++EraseIter;
		++EraseIter;
		++EraseIter;

		EraseIter = NewList.erase(EraseIter);


		for (; StartIter != EndIter; ++StartIter)
		{
			// 순회를 하면서 모든 인자를 도는 와중에 삭제를 합니다.
			std::cout << (*StartIter) << std::endl;
			
		}
	}

}
