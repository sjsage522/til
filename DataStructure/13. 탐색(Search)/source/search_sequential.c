#define MAX_SIZE 10
typedef int element;
element list[MAX_SIZE];
int seq_search(int key, int low, int high) {
    int i;
    
    for(i=low; i<=high; i++)
        if(list[i] == key)
            return i;// 탐색에 성공하면 키 값의 인덱스 반환
    return -1;		 // 탐색에 실패하면 -1 반환
}