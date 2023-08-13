#include "IntArray.h"
class ArrayManager {
private:
	int length;
	IntArray arr;
	Renderer* renderer;

	void SwapValues(int* valueA, int* valueB);
	int MaxValue();
	int MinValue();
	int Partition(int start, int end);
	void Merge(int low, int mid, int high);
	void Shuffle();

public:
	ArrayManager(IntArray arr_, int length_, Renderer* renderer_);
	IntArray GetIntArray();
	void Fill(int maxValue);
	bool IsSorted();
	void QuickSort(int low, int high);
	void BubbleSort();
	void SelectionSort();
	void InsertionSort();
	void CocktailSort();
	void PigeonholeSort();
	void BogoSort();
	void MergeSort(int low, int high);
	void CountingSort();
	void GnomeSort();
};