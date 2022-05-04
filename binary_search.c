#include<stdio.h>

int BinarySearch(int arr[], int low, int high, int key) {
if(low>high) {return -1;}

int mid = (low+high)/2;
if(arr[mid]==key) {return mid;}

else if(arr[mid]>key) {
high=mid-1;
}
else {
low=mid+1;
}
return BinarySearch(arr, low, high, key);
}

int main() {
int n, key;
scanf("%d %d", &n, &key);
int arr[n];
for(int i=0; i<n; i++) {
scanf("%d", &arr[i]);
}
printf("%d", BinarySearch(arr, 0, n-1, key));
return 0;
}
