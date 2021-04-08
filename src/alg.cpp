// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  if (len == 0) return 0;
  int count = 0;
  for (int i = 0; i < len; i++)
  {
    for (int j = i + 1; j < len; j++)
      {
        int first = arr[i];
        int second = arr[j];
        int sum = first + second;
        if (sum == value)
        {
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

long getTime() {
    auto now = std::chrono::system_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);

    auto value = now_ms.time_since_epoch();
    return value.count();
}

int* getRandomArray(int size, int randMax) {
    int* a = new int[size];
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % randMax;
    }
    return a;
}

void sortArray(int* arr, int len) {
    int temp;
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // меняем элементы местами
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int* arr, int len) {
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int size = 100000;
    int value = 5;
    int* arr = getRandomArray(size, 100);
    sortArray(arr, size);
    //printArray(arr, size);

    long start1 = getTime();
    int count1 = countPairs1(arr, size, value);
    long end1 = getTime();
   
    int count2 = countPairs2(arr, size, value);
    long end2 = getTime();

    int count3 = countPairs3(arr, size, value);
    long end3 = getTime();

    cout << "count of pairs by 1 algorithm: " << count1 << " time: " << end1 - start1 << "\n";
    cout << "count of pairs by 2 algorithm: " << count2 << " time: " << end2 - end1 << "\n";
    cout << "count of pairs by 3 algorithm: " << count3 << " time: " << end3 - end2 << "\n";
    return 0;
}
