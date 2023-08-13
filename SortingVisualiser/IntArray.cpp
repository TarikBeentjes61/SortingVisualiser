#include "IntArray.h"
IntArray::IntArray(Renderer* renderer_, const int length_)
	: renderer(renderer_), length(length_)
{
	IntArray::arr = std::vector<int>(length);
	for (int i = 0; i < length; i++)
	{
		arr[i] = 0;
	}
}
IntArray::IntArray() {
	renderer = nullptr;
	length = 0;
}
int& IntArray::operator[](int index) {
	renderer->DrawSnapshot(arr, index);
	return arr[index];
}
std::vector<int> IntArray::GetArray()
{
	return arr;
}
