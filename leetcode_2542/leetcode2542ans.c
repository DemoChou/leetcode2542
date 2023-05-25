#include <stdio.h>
#include <stdlib.h>
long long maxScore(int* nums1, int nums1Size, int* nums2, int nums2Size, int k);
void sort_arr(int* arr, int start, int end,int* nums1,int* nums2,int nums1Size);
void cal(int* flag,int* nums1,int* nums2,int nums1Size);
void swap(int* a, int* b);
long long max_score=0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int nums1[4] = {1,3,3,2}, nums2[4] = {2,1,3,4}, k = 3,nums1Size=4,nums2Size=4;
	printf("%lld",maxScore(nums1,  nums1Size,  nums2,  nums2Size,  k));
	return 0;
}
long long maxScore(int* nums1, int nums1Size, int* nums2, int nums2Size, int k)
{
    int *flag=malloc(nums1Size*sizeof(int)),i=0;
    long long sum=0,min=100001;
    max_score=0;
    while(i<nums1Size)
    {
        if(i<k)
            *(flag+i)=1;
        else
            *(flag+i)=0;
        i++;
    }
    sort_arr(flag, 0, nums1Size-1,nums1,nums2,nums1Size);
    return max_score;
}
void cal(int* flag,int* nums1,int* nums2,int nums1Size)
{
    long long sum=0,min=100001;
    int j=0;
    while(j<nums1Size)
    {
        sum+=*(flag+j)*(*(nums1+j));
        if(*(flag+j)==1&&*(nums2+j)<min)
            min=*(nums2+j);
        j++;
    }
    if(max_score<(sum*min))
        max_score=(sum*min);
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort_arr(int* arr, int start, int end,int* nums1,int* nums2,int nums1Size) {
    long long max=0;
    int i=0;
    if (start == end) {
        cal(arr,nums1,nums2,nums1Size);
        return ;
    }
    for (i = start; i <= end; i++) {
        if (i != start && *(arr+i) == *(arr+start)) {
            continue;  // Skip duplicate elements
        }
        swap((arr+i), (arr+start));
        sort_arr(arr, start + 1, end,nums1,nums2,nums1Size);
        swap((arr+i), (arr+start));  // Backtrack
    }
}
