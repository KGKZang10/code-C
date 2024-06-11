// Viết chương trình đọc hai chuỗi S và T.
// Đếm số lần ký tự xuất hiện trong chuỗi.
// in ra các ký tự riêng biết xuất hiện trong chuỗi S và T theo bảng mã ASCII
#include <stdio.h>
#include <string.h>

int main() {
	char S[100], T[100];
	int count[256] = {0};
	char obj[256];
	int A= 0;
	
	fgets(S, sizeof(S), stdin);
	S[strcspn(S, "\n")] = '\0'; //loại bỏ ký tự newline và các ký tự đứng sau nó khỏi chuỗi 
	
	fgets(T, sizeof(T), stdin);
	T[strcspn(T, "\n")] = '\0';
	
	for(int i = 0; S[i]; i++) {
		if(count[(int)S[i]] == 0) { // ktra ptu S[i] đã tồn tai hay chưa
			obj[A++] = S[i]; // đánh giấu S[i] bằng obj
		}
		count[(int)S[i]]++; // tang bien dem
	}
	
	for (int i = 0; T[i]; i++) {
		if(count[(int)T[i]] == 0) {
			obj[A++] = T[i];
		}
		count[(int)T[i]]++;
	}
	
	//sắp xếp các phần tử theo bảng mã ASCII
	for (int i = 0; i < A - 1; i++) {
		for (int j = i + 1; j < A; j++) {
			if(obj[i] > obj[j]) {
				char temp = obj[i];
				obj[i] = obj[j];
				obj[j] = temp;
			}
		}
	}
	// in cac phần tử theo bảng mã ASCII
	for(int i = 0; i < A; i++) {
		printf("%c  ", obj[i]);
	}
	printf("\n");
	
	// in tuân suất của phần tử đó
	for(int i = 0; i < A; i++) {
		printf("%d  ",count[(int)obj[i]]);
	}
	return 0;
}