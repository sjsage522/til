#define MAX_SIZE 10
typedef int element;
element list[MAX_SIZE];
int seq_search(int key, int low, int high) {
    int i;
    
    for(i=low; i<=high; i++)
        if(list[i] == key)
            return i;// Ž���� �����ϸ� Ű ���� �ε��� ��ȯ
    return -1;		 // Ž���� �����ϸ� -1 ��ȯ
}