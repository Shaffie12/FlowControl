#include <cstdio>

template<typename T>
void Swap(T* a, T* b)
{
	T c = *a;
	*a = *b;
	*b = c;
}

template <typename T>
void SortInPlace(T* inArr, int numElements, bool ascOrder = true)
{
	bool sorted = false;

rescan:
	if (sorted)
		return;
	else
	{
		int pos = 1;
		T* elem = inArr;
		T* nextElem = elem + 1;
		next:
		/*if we ever found something out of place, restart */
		if (ascOrder)
		{
			if (*elem > *nextElem)
			{
				Swap(elem, nextElem);
				goto rescan;
			}
		}
		else
		{
			if (*elem < *nextElem)
			{
				Swap(elem, nextElem);
				goto rescan;
			}
		}

		/* otherwise we can keep going */
		pos++;
		if (pos == numElements)
		{
			sorted = true;
			goto rescan;
		}
			
		elem++;
		nextElem++;
		goto next;
	}
}

template<typename T>
void PrintArr(T* inArr, int arrSize)
{
	T* ptr = inArr;
	int i = 0;
	while (i < arrSize)
	{
		//assumes integer
		std::printf("%i , ", *ptr);
		ptr++;
		i++;
	}
	std::printf("\n");
	
}


int main()
{
	int arr[5]{ 4,55,26,70,245 };

	PrintArr(&arr[0], 5);
	SortInPlace(&arr[0], 5, false);
	PrintArr(&arr[0], 5);
	return 0;
}