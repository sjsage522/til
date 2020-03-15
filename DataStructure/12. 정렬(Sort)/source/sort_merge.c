#define MAX_SIZE 100
int sorted[MAX_SIZE];

/* i�� ���ĵ� ���� ����Ʈ�� ���� �ε���
   j�� ���ĵ� ������ ����Ʈ�� ���� �ε���
   k�� ���ĵ� ����Ʈ�� ���� �ε��� */
void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left; j = mid+1; k = left;

    /* ���� ���ĵ� list�� �պ� */
    while(i <= mid && j <= right) {
        if(list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if(i>mid)   /* ���� �ִ� ���ڵ��� �ϰ� ���� */
        for(l = j; j <= right; l++)
            sorted[k++] = list[l];
    else        /* ���� �ִ� ���ڵ��� �ϰ� ���� */
        for(l = i; l <= right; l++)
            sorted[k++] = list[l];      
    for(l = left; l <= right; l++)
        list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right) {
    int mid;
    if(left < right) {
        mid = (left + right) / 2;         /* ����Ʈ�� �յ� ���� */
        merge_sort(list, left, mid);      /* �κ� ����Ʈ ���� */
        merge_sort(list, mid + 1, right); /* �κ� ����Ʈ ���� */
        merge(list, left, mid, right);    /* �պ� */
    }
}