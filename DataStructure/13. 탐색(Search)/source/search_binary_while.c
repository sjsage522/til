#define MAX_SIZE 10
typedef int element;
element list[MAX_SIZE];
int search_binary2(int key, int low, int high) {
    int middle;

    while(low <= high) {    // 아직 숫자들이 남아있으면
        middle = (low + high) / 2;
        if(key == list[middle])
            return middle;
        else if(key > list[middle])
            low = middle + 1;
        else
            high = middle - 1;
    }
    return -1;              // 발견되지 않음
}