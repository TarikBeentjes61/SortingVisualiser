#include "ArrayManager.h"

ArrayManager::ArrayManager(IntArray arr_, int length_, Renderer* renderer_)
	: arr(arr_), length(length_), renderer(renderer_)
{}
IntArray ArrayManager::GetIntArray() {
	return arr;
}
void ArrayManager::SwapValues(int* valueA, int* valueB)
{
	int savedValue = *valueA;
	*valueA = *valueB;
	*valueB = savedValue;
}
int ArrayManager::MaxValue() {
	int maxValue = arr[0];
	for (int i = 1; i < length; i++)
	{
		if (arr[i] > maxValue) {
			maxValue = arr[i];
		}
	}
	return maxValue;
}
int ArrayManager::MinValue() {
	int minValue = arr[0];
	for (int i = 1; i < length; i++)
	{
		if (arr[i] < minValue) {
			minValue = arr[i];
		}
	}
	return minValue;
}
int ArrayManager::Partition(int start, int end)
{
	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	int pivotIndex = start + count;
	SwapValues(&arr[pivotIndex], &arr[start]);

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			SwapValues(&arr[i++], &arr[j--]);
		}
	}
	return pivotIndex;
}
void ArrayManager::Merge(int low, int mid, int high) {
	const int leftLength = mid - low + 1;
	const int rightLength = high - mid;
	std::vector<int>subArrayLeft(leftLength);
	std::vector<int>subArrayRight(rightLength);

	for (int l = 0; l < leftLength; l++)
	{
		subArrayLeft[l] = arr[low + l];
	}
	for (int r = 0; r < rightLength; r++)
	{
		subArrayRight[r] = arr[mid + r + 1];
	}

	int indexArrayLeft = 0;
	int indexArrayRight = 0;
	int indexMergedArray = low;

	while (indexArrayLeft < leftLength && indexArrayRight < rightLength)
	{
		if (subArrayLeft[indexArrayLeft] <= subArrayRight[indexArrayRight])
		{
			arr[indexMergedArray] = subArrayLeft[indexArrayLeft];
			indexArrayLeft++;
		}
		else
		{
			arr[indexMergedArray] = subArrayRight[indexArrayRight];
			indexArrayRight++;
		}
		indexMergedArray++;
	}

	while (indexArrayLeft < leftLength) {
		arr[indexMergedArray] = subArrayLeft[indexArrayLeft];
		indexArrayLeft++;
		indexMergedArray++;
	}
	while (indexArrayRight < rightLength) {
		arr[indexMergedArray] = subArrayRight[indexArrayRight];
		indexArrayRight++;
		indexMergedArray++;
	}
}
void ArrayManager::Shuffle()
{
	std::vector<int> temp(length);
	for (int i = 0; i < length; i++)
	{
		int indexA = rand() % length;
		int indexB = rand() % length;
		SwapValues(&arr[indexA], &arr[indexB]);
	}
}
void ArrayManager::Fill(int maxValue)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		int randomNum = rand() % maxValue;
		arr[i] = randomNum;
	}
}
bool ArrayManager::IsSorted()
{
	for (int i = 1; i < length; i++)
	{
		if (arr[i - 1] > arr[i]) {
			return false;
		}
	}
	return true;
}
//--Sorts--
void ArrayManager::QuickSort(int low, int high)
{
	if (low < high) {
		const int newPivot = Partition(low, high);
		QuickSort(low, newPivot - 1);
		QuickSort(newPivot + 1, high);
	}
}
void ArrayManager::BubbleSort()
{
	bool swapped;
	for (int i = 0; i < length - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < length - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				SwapValues(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false) {
			break;
		}
	}
}
void ArrayManager::SelectionSort()
{
	int highestIndex;
	for (int i = 0; i < length - 1; i++)
	{
		highestIndex = i;
		for (int j = i + 1; j < length; j++)
		{
			if (arr[j] < arr[highestIndex]) {
				highestIndex = j;
			}
		}
		SwapValues(&arr[i], &arr[highestIndex]);
	}
}
void ArrayManager::InsertionSort()
{
	int key;
	int j;
	for (int i = 1; i < length; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
void ArrayManager::CocktailSort()
{
	bool swapped = true;
	int start = 0;
	int end = length - 1;
	while (swapped)
	{
		swapped = false;
		for (int i = start; i < end; i++)
		{
			if (arr[i] > arr[i + 1]) {
				SwapValues(&arr[i], &arr[i + 1]);
				swapped = true;
			}
		}
		if (swapped == false) {
			break;
		}
		end--;
		for (int j = end; j >= start; j--)
		{
			if (arr[j] > arr[j + 1]) {
				SwapValues(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		start++;
	}
}
void ArrayManager::PigeonholeSort()
{
	int min = arr[0];
	int max = arr[0];
	for (int i = 1; i < length; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	int range = max - min + 1;
	std::vector<int> temp(range);

	for (int j = 0; j < length; j++)
	{
		temp[arr[j] - min]++;
	}

	int j = 0;
	for (int k = 0; k < range; k++)
	{
		while (temp[k] > 0) {
			arr[j] = k + min;
			temp[k]--;
			j++;
		}
	}
}
void ArrayManager::BogoSort() {
	while (!IsSorted()) {
		Shuffle();
	}
}

void ArrayManager::MergeSort(int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(low, (mid));
		MergeSort(mid + 1, high);
		Merge(low, mid, high);
	}
}
void ArrayManager::CountingSort() {
	int maxValue = MaxValue();
	std::vector<int> counts(maxValue + 1);
	std::vector<int> output(maxValue + 1);
	for (int i = 0; i < length; i++)
	{
		counts[arr[i]]++;
	}
	for (int j = 1; j <= maxValue; j++)
	{
		counts[j] += counts[j - 1];
	}
	for (int k = length - 1; k >= 0; k--)
	{
		output[counts[arr[k]] - 1] = arr[k];
		counts[arr[k]]--;
	}
	for (int x = 0; x < length; x++)
	{
		arr[x] = output[x];
	}
}
void ArrayManager::GnomeSort() {
	int index = 1;
	while (index < length) {
		if (index == 0) {
			index++;
		}
		if (arr[index] < arr[index - 1]) {
			SwapValues(&arr[index], &arr[index - 1]);
			index--;
		}
		else {
			index++;
		}
	}
}
