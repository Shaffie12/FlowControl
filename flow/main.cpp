#include <cstdio>

template<typename T>
void Swap(T* a, T* b)
{
	T c = *a;
	*a = *b;
	*b = c;
}

template <typename T>
void SortNumbersInPlace(T* inArr, int numElements, bool ascOrder = true)
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
void SortNumbersInPlaceLoops(T* inArr, int NumElements, bool ascOrder = true)
{
	int i = 0;
	while (i < NumElements-1)
	{
		if (ascOrder)
		{
			if (inArr[i] > inArr[i + 1])
			{
				Swap(&inArr[i], &inArr[i + 1]);
				i = 0;
				continue;
			}
		}
		else
		{
			if (inArr[i] < inArr[i + 1])
			{
				Swap(&inArr[i], &inArr[i + 1]);
				i = 0;
				continue;
			}
		}
		i++;
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
	SortNumbersInPlaceLoops(&arr[0], 5, false);
	PrintArr(&arr[0], 5);
	return 0;
}