#define MAX_SIZE 10
typedef int element;
element list[MAX_SIZE];
int seq_search2(int key, int low, int high) {
    int i;
    
    list[high +1] = key;
    for(i=low; list[i] != key; i++);	// Ű���� ã���� ����
    if(i==(high+1)) return -1;			// Ž�� ����
    else return i;						// Ž�� ����
}