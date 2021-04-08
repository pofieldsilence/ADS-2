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
  int count = 0;

  for (int i = 0; i < len; i++) {
    int left = i;
    int right = len - 1;
    int midIndex = 0;
    while (left <= right) {
      midIndex = (left + right) / 2;
      int sum = arr[midIndex] + arr[i];
      if (sum == value) {
        break;
      }
      if (value < sum) {
        right = midIndex - 1;
      } else {
        left = midIndex + 1;
      }
    }
    while (arr[i] + arr[midIndex] == value) {
      midIndex--;
    }
    midIndex++;
    while (arr[i] + arr[midIndex] == value) {
      count++;
      midIndex++;
    }
  }

  return count;
}