#include <memory>



int main()
{
	std::unique_ptr<int> a(new int);
	return 0;
}