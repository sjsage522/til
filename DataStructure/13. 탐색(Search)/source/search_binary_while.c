#define MAX_SIZE 10
typedef int element;
element list[MAX_SIZE];
int search_binary2(int key, int low, int high) {
    int middle;

    while(low <= high) {    // ���� ���ڵ��� ����������
        middle = (low + high) / 2;
        if(key == list[middle])
            return middle;
        else if(key > list[middle])
            low = middle + 1;
        else
            high = middle - 1;
    }
    return -1;              // �߰ߵ��� ����
}