#include "Renderer.h"
class IntArray {
private:
	std::vector<int> arr;
	Renderer* renderer;
	int length;
public:
	IntArray(Renderer* renderer_, const int length_);
	IntArray();
	int& operator[](int index);
	std::vector<int> GetArray();
};