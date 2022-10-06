#include <iostream>
void sortingByBubble(int nums[],int size) {
    int i = 0, j = 0;
    for(i = 0; i < size; i++) {
        for(j = 0; j < (size - i - 1); j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    for(int k = 0; k < size; k++) {
        printf("%d\t",nums[k]);
    }
}
void sortingByInsertion(int nums[],int size) {
    int i = 0, j = 0;
    for(i = 1; i < size; i++) {
        j = i;
        while(j > 0 && nums[j - 1] > nums[j]) {
            int temp = nums[j];
            nums[j] = nums[j - 1];
            nums[j - 1] = temp;
            j--;
        }
    }
    for(int k = 0; k < size; k++) {
        printf("%d\t",nums[k]);
    }
}
void swapNumber(int nums[], int min, int i) {
    int temp = nums[min];
    nums[min] = nums[i];
    nums[i] = temp;
}
void sortingBySelection(int nums[],int size) {
    int i = 0, j = 0, min = 0;
    for(i = 0; i < size - 1; i++) {
        min = i;
        for(j = i + 1; j < size; j++) {
            if (nums[min] > nums[j]) {
                min = j;
            }
        }
        swapNumber(nums,min,i);
    }
    for(int k = 0; k < size; k++) {
        printf("%d\t",nums[k]);
    }
}

int searchByBinary(int nums[],int size,int key) {
    int low = 0,high = size - 1, mid = 0;
    while(low < high) {
        mid = (low + high) / 2;
        if (key == nums[mid]) {
            return mid;
        }
        else if (key > nums[mid]) {
            low = mid + 1;
        }
        else if ( key < nums[mid]) {
            high = mid - 1;
        }
    }
    return -1;
}
int searchByBinaryRecur(int nums[],int low,int high,int key) {
    int mid = (low + high) / 2;
    while(low > high) {
        if (key == nums[mid]) {
            return mid;
        }
        else if (key > nums[mid]) {
            return searchByBinaryRecur(nums,mid + 1,high,key);
        }
        else if (key < nums[mid]) {
            return searchByBinaryRecur(nums,low,mid - 1,key);
        }
    }
    return -1;
}
int searchByLinear(int nums[],int size,int key) {
    for(int i = 0; i < size; i++) {
        if (key == nums[i]) {
            return i;
        }

    }
    return -1;
}
int main() {
    int nums[] = {60,45,65,1,20,54,23};
    int searchKey = 0;
    int arraySize = sizeof(nums) / sizeof(nums[0]);
    //sortingByBubble(nums,arraySize);
    //sortingByInsertion(nums,arraySize);
    sortingBySelection(nums,arraySize);
    printf("Enter a number to search : ");
    scanf("%d",&searchKey);
    int binarySearch = searchByBinary(nums,arraySize,searchKey);
    printf("Binary - The index for search number %d is %d\n",searchKey,binarySearch);
    int recurSearch = searchByBinary(nums,arraySize,searchKey);
    printf("Recursive - The index for search number %d is %d\n",searchKey,recurSearch);
    int linearSearch = searchByBinary(nums,arraySize,searchKey);
    printf("Linear - The index for search number %d is %d\n",searchKey,linearSearch);
    return 0;
}