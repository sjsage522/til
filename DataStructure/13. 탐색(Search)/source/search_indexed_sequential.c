#define MAX_SIZE 10
typedef int element;
element list[MAX_SIZE];
#define INDEX_SIZE 256
typedef struct {
    int key;
    int index;
} itable;
itable index_list[INDEX_SIZE];

// INDEX_SIZE�� �ε��� ���̺��� ũ��, n�� ��ü �������� ��
int search_index(int key, int n) {
    int i, low, high;

    // Ű ���� ����Ʈ ���� ���� ���� �ƴϸ� Ž�� ����
    if(key<list[0] || key>list[n-1])
        return -1;

    // �ε��� ���̺��� �����Ͽ� �ش�Ű�� ���� ����
    for(i=0; i<INDEX_SIZE; i++)
        if(index_list[i].key <= key &&
        index_list[i+1].key > key)
        break;
    if(i == INDEX_SIZE) {   // �ε��� ���̺��� ���̸�
        low = index_list[i-1].index;
        high = n;
    }
    else {
        low = index_list[i].index;
        high = index_list[i+1].index;
    }
    // ����Ǵ� ������ ���� Ž��
    return seq_serch(key, low, high);
}