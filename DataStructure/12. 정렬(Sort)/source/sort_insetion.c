// ���� ����
void insertion_sort(int list[], int n) {
    int i, j, key;
    for(i=1; i<n; i++) {
        key = list[i];
        for(j=i-1; j>=0 && list[j]>key; j--)
            list[j+1] = list[j];	/* ���ڵ��� ������ �̵� */
        list[j+1] = key;
    }
}