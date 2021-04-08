// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  if (len == 0) return 0;
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
        int first = arr[i];
        int second = arr[j];
        int sum = first + second;
        if (sum == value) {
          count++;
        }
      }
    }

    return count;
}

int countPairs2(int *arr, int len, int value) {
  if (len == 0) return 0;

  int count = 0;

  int firstIndex = 0;
  int lastIndex = len - 1;

  while (arr[firstIndex] + arr[lastIndex] > value) {
    lastIndex--;
  }

  while (arr[firstIndex] + arr[lastIndex] < value) {
    firstIndex++;
  }

  for (int i = firstIndex; i <= lastIndex; i++) {
    for (int j = i + 1; j <= lastIndex; j++) {
      int sum = arr[i] + arr[j];
      if (sum == value) {
        count++;
      }
    }
  }

  return count;
}

int countPairs3(int *arr, int len, int value) {
  if (len == 0) return 0;

  int count = 0, start = 0, end = len - 1;
    while (start < end - 1) {
        int mid1 = (start + end) / 2;
        if (arr[mid1] <= value)
            start = mid1;
        else
            end = mid1;
    }
    len = end - 1;

    for (int i = 0; i <len; i++) {
        start = i+1, end = len-1;
        int cNum = 0;

        while (start < end) {
            int mid2 = (start + end) / 2;
            if (arr[mid2] < (value-arr[i]))
                start = mid2 + 1;
            else
                end = mid2;
        }

        while (arr[start] == (value - arr[i])) {
            cNum++;
            start++;
        }
        count += cNum;
    }
    return count;
}
