#include <iostream>
#include <vector>

// stl은 템플릿만 사용했다면 다 stl
// 자료구조템플릿 != stl 
// stl중 자료구조 stl이라고 합니다.
// C++을 만든

// stl에 포함된 자료구조형 템플릿 클래스들을 배우는 겁니다.

// std 자료구조가 할수 있다면
// 나도 똑같은 짓을 하고 똑같은 결과를 내는 클래스를 만들어 보는게.

// 숙제0 => HVector의 leak을 없애와라
//         대입연산자를 사용하면 터지는걸 정상으로 돌려놔라.
//         이미 보여준 코드 이미 array에서 해결은 한거에요.

// 숙제1 => 템플릿으로 바꾸세요.

template <typename DataType>
class HVector
{
public:
	DataType& operator[](size_t _Index)
	{
		return ArrPtr[_Index];
	}

	HVector& operator=(const HVector& _other)
	{
		if (ArrPtr != nullptr)
		{
			delete[] ArrPtr;
		}
		sizeValue = _other.sizeValue;
		capacityValue = _other.capacityValue;

		reserve(capacityValue);

		for (int i = 0; i < _other.sizeValue; ++i)
		{
			ArrPtr[i] = _other.ArrPtr[i];
		}
		return *this;
	}

	size_t size()
	{
		return sizeValue;
	}

	size_t capacity()
	{
		return capacityValue;
	}

	void push_back(const DataType& _Data)
	{
		// 확장해야 할때가 있습니다.
		if (sizeValue + 1 > capacityValue)
		{
			reserve((int)((capacityValue * 1.5) + 1));
		}

		ArrPtr[sizeValue] = _Data;
		sizeValue += 1;
	}

	void reserve(size_t _capacity)
	{
		DataType* PrevPtr = ArrPtr;

		// 1회의 new가 일어났다면 1회의 delete가 어딘가에 존재해야 한다.
		ArrPtr = new DataType[_capacity];

		// 최초에 한번은 내가 nullptr 이었을것이다.
		if (nullptr != PrevPtr)
		{
			for (size_t i = 0; i < sizeValue; i++)
			{
				ArrPtr[i] = PrevPtr[i];
			}
		}

		capacityValue = _capacity;
		delete[] PrevPtr;
	}

	~HVector()
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

private:
	int sizeValue = 0;
	int capacityValue = 0;
	DataType* ArrPtr = nullptr;
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//{
	//	//int Arr[10];

	//	//Arr[-1] = 20;
	//}

	//{
	//	// 대입도 안되
	//	// 개수가 몇개인지도 알수 없어.
	//	// int Arr[10];

	//	// 배열이 가장 좋은 메모리 구조입니다.
	//	// 가장 빠른 자료구조 입니다.
	//	// 무조건 가장 빠르다.
	//	// 거의 모든 대부분의 상황에서 
	//	// 배열을 대체하는 자료구조형 클래스입니다.
	//	// vector => 

	//	std::vector<int> Arr = std::vector<int>(10);
	//	for (int i = 0; i < Arr.size(); i++)
	//	{
	//		Arr[i] = i;
	//	}

	//	//for (int i = 0; i < Arr.size(); i++)
	//	//{
	//	//    std::cout << Arr[i] << std::endl;
	//	//}

	//	// Arr.resize(20);

	//	// Arr.reserve();
	//	// Arr.resize();
	//	// Arr.size();
	//}

	//{
	//	// 배열처럼 쓰는게 아니라.
	//	// 일반적인 확장형 자료구조처럼 사용하는버
	//	std::vector<int> Arr;

	//	// 미리 배열을 그만큼 할당해 놓는것을 의미합니다.
	//	// 리저브를 사용하지 않을거면 벡터를 왜쓰지?
	//	// Arr.reserve(10);

	//	// 벡터는
	//	for (size_t i = 0; i < 10; i++)
	//	{
	//		Arr.push_back(i);
	//		std::cout << "size : " << Arr.size() << std::endl; // 원소의수
	//		std::cout << "capacity : " << Arr.capacity() << std::endl; // 메모리의 크기
	//	}

	//	// Arr[-1];
	//	// Arr.operator[](-1);

	//	for (size_t i = 0; i < Arr.size(); i++)
	//	{
	//		std::cout << Arr[i] << std::endl;
	//	}
	//}


	// 여기를 건들지 마세요.
	{
		HVector<int> Arr;
		// 내부에 123
		// Arr.reserve(10);
		for (size_t i = 0; i < 10; i++)
		{
			Arr.push_back(i);
			//std::cout << "size : " << Arr.size() << std::endl; // 원소의수
			//std::cout << "capacity : " << Arr.capacity() << std::endl; // 메모리의 크기
		}

		for (size_t i = 0; i < Arr.size(); i++)
		{
			std::cout << Arr[i] << std::endl;
		}


		HVector<int> Arr0;

		// 릭을 해결하는 순간 터질겁니다.
		// 정상적인 복사가 이루어지게 하세요.
		Arr0 = Arr;

		for (size_t i = 0; i < Arr0.size(); i++)
		{
			std::cout << Arr0[i] << std::endl;
		}

	}



}
