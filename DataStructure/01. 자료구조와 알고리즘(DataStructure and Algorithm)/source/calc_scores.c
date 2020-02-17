#include <stdio.h>
#include <stdlib.h> // rand() 함수 포함 라이브러리
#include <time.h> // time()함수 포함 라이브러리
#define MAX_ELEMENTS 100
int scores[MAX_ELEMENTS];	// 자료구조

int get_max_score(int n) 	// 학생의 숫자는 n
{
	int i, largest;
	largest = scores[0];	// 알고리즘
	for (i = 1; i<n; i++) {
		if (scores[i] > largest) {
			largest = scores[i];
		}
	}
	return largest;
}

int main(){
	int random;
	srand(time(NULL));
	for(int i=0; i<MAX_ELEMENTS; i++){
		random = rand() % 101;
		scores[i] = random;	
	}
	printf("%d\n", get_max_score(100));
}
