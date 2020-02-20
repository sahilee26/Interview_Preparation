int Solution::maxArr(vector<int> &A) {
    int len=A.size();
    int arr1[len], arr2[len];
    for(int i=0; i<A.size(); i++){
        arr1[i]=A[i]+i;
        arr2[i]=A[i]-i;
    }
    int max1=INT_MIN, max2=INT_MIN;
    int min1=INT_MAX, min2=INT_MAX;
    for(int i=0; i<len; i++){
        max1=max(arr1[i], max1);
        max2=max(arr2[i], max2);
        min1=min(arr1[i], min1);
        min2=min(arr2[i], min2);
    }
    int max3=max(max1-min1, max2-min2);
    return max3;
}
