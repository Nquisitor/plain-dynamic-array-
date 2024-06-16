#include <iostream>

class Dynamic_array
{
private:
	int arr[100]{};
	int* ptr = &arr[0];
	size_t size = 0;

public:
	Dynamic_array()
	{}

	explicit Dynamic_array(int n) : size(n)
	{}

	void push_back(int& elem)
	{
		*ptr = elem;
		ptr++;
		size++;
	}

	bool empty() const
	{
		return arr[0] == 0;
	}

	void clear()
	{
		while (ptr != &arr[0])
		{
			*ptr = 0;
			ptr--;
		}
		*ptr = 0;
		size = 0;
	}

	size_t volume() const
	{
		return size;
	}

	void exterminate()
	{
		ptr--;
		*ptr = 0;
		size--;
	}
};

int main(int argc, const char* argv[])
{
	int n;
	std::cin >> n;
	Dynamic_array arr;
	while (n--)
	{
		int elem;
		std::cin >> elem;
		if (elem >= 0) arr.push_back(elem);
	}
	int size = arr.volume();
	std::cout << size << '\t';
	arr.exterminate();
	std::cout << arr.volume() << '\t';
	arr.clear();
	std::cout << arr.volume();

	return 0;
}