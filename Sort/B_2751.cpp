// 수 정렬하기 2
// mergeSort 이용

#include <cstdio>
using namespace std;

int arr[1000000];
int tmp[1000000];

void merge(int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int idx = start;

    // 임시 배열에 필요한 만큼 복사
    for (int ii = start; ii <= end; ++ii) {
        tmp[ii] = arr[ii];
    }    

    while (i <= mid && j <= end) {
        if (tmp[i] <= tmp[j]) {
            arr[idx] = tmp[i];
            i += 1;
        } else {
            arr[idx] = tmp[j];
            j += 1;
        }
        idx += 1;
    }
    // 위에서 j > end 이면, 남은 것 저장
    while (i <= mid) {
        arr[idx] = tmp[i];
        i += 1;
        idx += 1;
    }
    // 위에서 i > mid 이면, 남은 것 저장
    while (j <= end) {
        arr[idx] = tmp[idx];
        j += 1;
        idx += 1;
    }
}

void mergeSort(int start, int end) {
    if (start == end) {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid + 1, end);
    merge(start, mid, end);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    mergeSort(0, n - 1);
    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
    return 0;
}