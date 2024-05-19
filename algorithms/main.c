
void algorithhm_bubble_sort(int*, int);

int main(void) {
    return 0;
}

void algorithhm_bubble_sort(int* arr, int length) {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length - 1; ++j) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}