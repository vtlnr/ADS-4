// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int cnt = 0;
  for (int i=0; i<len-1; ++i){
    for (int j=i+1; j<len; ++j){
      if (arr[i]+arr[j]==value){
        cnt++;
      }
    }
  }
  return cnt;
}
int countPairs2(int *arr, int len, int value) {
  int cnt = 0;
  int l = 0;
  int r = len - 1;
  while (l < r){
    int summa = arr[l] + arr [r];
    if (summa == value){
      cnt++;
      l++;
      r--;
    } else if (summa < value){
      l++;
    } else {
      r--;
    }
  }
  return  cnt;
}
int countPairs3(int *arr, int len, int value) {
  int cnt = 0;
  for (int i = 0; i < len; ++i){
    int low = i+1, high = len - 1;
    while (low <= high){
      int mid = low + (high - low)/2;
      if (arr[i] + arr[mid] < value){
        cnt++;
        break;
      } else if (arr[i] + arr[mid] < value){
        low = mid + 1;
      } else{
        high = mid - 1;
      }
    }
  }
  return cnt;
}
