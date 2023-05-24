# Bubble Sort

	#Python
	
	def bubble_sort(arr):
		n = len(arr)
		for i in range(n):
			for j in range(n-i-1):
				if arr[j] > arr[j+1]:
					arr[j],arr[j+1] = arr[j+1], arr[j]
							
		return arr
		
	# C++
	
	#include <iostream>
	
	using namespace std;
	
	void bubble_sort(int* arr, int length) {
		for ( int i = 0; i < lenth - 1; i++) {
			for ( int j = 0; j < lenght - i - 1; i++) {
				if ( arr[j] > arr[j+1]) {
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
	}
	
	int main() {
		int arr[5] = {1,2,5,4,3};
		int lenght = sizeof(arr) / siezof(arr[0]);
		
		bubble_sort(arr, length);
		
		for (int i = 0; i < length; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		
		return 0;
	}
	
# Quick Sort

	#Python
	
	def quick_sort(arr):
		if len(arr) <= 1:
			return arr
		else:
			pivot = arr[0]
			left = [x for x in arr[1:] if x < pivot]
			right = [x for x in arr[1:] if x >= pivot]
			return quick_sort(left) + [pivot] + quick_sort(right)
			
	# C++
		
