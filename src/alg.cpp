// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int c = 0;
  for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
          if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
              c++;
          }
      }
  }
  return c;
}
int countPairs2(int *arr, int len, int value) {
 int r = len - 1;
  while (arr[r] > value) {
    r--;
  }
  int c = 0;
  for (int i = 0; i < r; i++) {
    for (int j = r; j > i; j--) {
      if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
        c++;
      } else if (arr[i] + arr[j] < value) {
        break;
      }
    }
  }
  return c;
}
int countPairs3(int *arr, int len, int value) {
  int c = 0;
  int rgh, mid, srdn, lft;
  for (int i = 0; i < len; ++i) {
    rgh = len - 1;
    lft = i + 1;
    srdn = value - arr[i];
    while (lft <= rgh) {
      mid = (lft + rgh) / 2;
      if (arr[mid] == srdn) {
        c++;
        int p = mid - 1;
        while ((p > i) && (arr[p] == arr[mid])) {
          c++;
          p--;
        }
        int p2 = mid + 1;
        while ((i < p2) && (arr[p2] == arr[mid])) {
          c++;
          p2++;
        }
        break;
      } else if (arr[mid] > srdn) {
        rgh = mid - 1;
      } else {
        lft = mid + 1;
      }
    }
  }
  return c;
}
