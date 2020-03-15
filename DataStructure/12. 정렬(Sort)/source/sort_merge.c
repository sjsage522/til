#define MAX_SIZE 100
int sorted[MAX_SIZE];

/* i는 정렬된 왼쪽 리스트에 대한 인덱스
   j는 정렬된 오른쪽 리스트에 대한 인덱스
   k는 정렬될 리스트에 대한 인덱스 */
void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left; j = mid+1; k = left;

    /* 분할 정렬된 list의 합병 */
    while(i <= mid && j <= right) {
        if(list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if(i>mid)   /* 남아 있는 레코드의 일괄 복사 */
        for(l = j; j <= right; l++)
            sorted[k++] = list[l];
    else        /* 남아 있는 레코드의 일괄 복사 */
        for(l = i; l <= right; l++)
            sorted[k++] = list[l];      
    for(l = left; l <= right; l++)
        list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right) {
    int mid;
    if(left < right) {
        mid = (left + right) / 2;         /* 리스트의 균등 분할 */
        merge_sort(list, left, mid);      /* 부분 리스트 정렬 */
        merge_sort(list, mid + 1, right); /* 부분 리스트 정렬 */
        merge(list, left, mid, right);    /* 합병 */
    }
}