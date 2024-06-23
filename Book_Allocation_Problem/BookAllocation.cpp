#include <iostream>
#define R 5

//maximum number of pages assigned to a student is minimum

/*
Given that there are N books and M students. Also given are the number of pages in each book in ascending order. 
The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum, with the 
condition that every student is assigned to read some consecutive books. Print that minimum number of pages.
*/
bool isPossible(int* arr, int mid, int m) {
	int count_of_student = 1;
	int allocated_page = 0;
	
	for (int i = 0; i < R; i++) {
		if ((allocated_page + arr[i]) <= mid) {
			allocated_page += arr[i];
		}
		else {
			count_of_student++;
			if (count_of_student > m || arr[i] > mid)
				return false;
			allocated_page = arr[i];
		}
	}
	if (count_of_student != m)
		return false;
	return true;
}

int main() {
	int arr[R] = { 2, 8, 8, 4, 5 };
	int st = arr[0], end = 0;
	int ans = -1;
	int m = 0;
	std::cout << "Enter the number of student ";
	std::cin >> m;
	for (int i = 0; i < R; i++)
		end += arr[i];
	int mid = st + (end - st) / 2;
	while (st <= end) {
		if (isPossible(arr, mid, m)) {
			ans = mid;
			end = mid - 1;
		}
		else
			st = mid + 1;

		mid = st + (end - st) / 2;
	}
	std::cout << "Maximum number of pages assigned to a student is minimum = " << ans;
}