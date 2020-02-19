#include <stdio.h>
#include <math.h>
#define MAX(a,b) ( a > b ? a : b )
#define MAX_DEGREE 101

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

polynomial poly_add1(polynomial A, polynomial B){
    polynomial C;
    int Apos = 0, Bpos = 0, Cpos = 0;
    int A_degree = A.degree, B_dgree = B.degree;
    C.degree = MAX(A.degree, B.degree);

    while(Apos <= A_degree && Bpos <= B_dgree){
        if(A.degree > B.degree){
            C.coef[Cpos++] = A.coef[Apos++];
            A.degree--;
        }

        else if(A.degree == B.degree){
            if(A.coef[Apos] + B.coef[Bpos] == 0 && C.degree == A.degree){
                Apos++; Bpos++;
                C.degree--; A.degree--; B.degree--;
            }
            else{
                C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
                A.degree--; B.degree--;
            }
        }

        else{
            C.coef[Cpos++] = B.coef[Bpos++];
            B.degree--;
        }
    }
    return C;
}

void print_poly(polynomial P){
    for(int i=P.degree; i>0; i--){
        printf("%3.1fx^%d + ", P.coef[P.degree - i], i);
    }
    printf("%3.1f\n", P.coef[P.degree]);
}

float poly_eval(int x, polynomial P){
    float result = 0;
    for(int i=P.degree; i>=0; i--){
        result += ( P.coef[P.degree - i] * pow(x, i) ); 
    }
    return result;
}

int main(){
    polynomial A = {4, {-1, 4, 10, -3, 5}};
    polynomial B = {4, {1, 2, -2, 3, 4}};
    polynomial C;

    print_poly(A);
    print_poly(B);
    printf("-------------------------------------------------\n");

    C = poly_add1(A, B);
    print_poly(C);

    printf("eval : %3.1f\n", poly_eval(2, C));
}