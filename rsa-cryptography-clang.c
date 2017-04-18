/*
Tuğrul Bayrak
2016
Discrete Mathematics RSA Homework
*/
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <math.h>
#include <conio.h>

//Function Definitions
long random_prime_number();
long test_for_prime(long);
long gcd(long,long);
long compute_e(long,long);
long compute_d(long,long,long);
long crypt(long,long,long);

int main() {
		int i;
		long n,e,d,your_message,m,p,q;
		system("color 8A");
		srand(time(NULL));
		your_message = 2 * rand() % 90;
		p = random_prime_number();

		for(i=0;i<5;i++) {
			Sleep(500);
			printf(" \t *");
		}
		printf("\n");

		q = random_prime_number();

		while(p==q) q=random_prime_number();

		e = compute_e(p,q);
		d = compute_d(e,p,q);
		n = p*q;
		m = crypt(your_message,e,n);

		printf("----------------------------------------- \n");
		printf("Your message : %d \n  p value: %d \n  q value: %d \n ",your_message,p,q);
		printf("Public key : (%d,%d) \n  Private key: (%d,%d) \n ",e,n,d,n);
		printf("Encrypted Message: %d\n Original Message : %d \n ");
		getchar();
		return 0;

	}


long random_prime_number() {
	int i,number=0,sign=0;
	while(sign ==0){
		number=100+rand() %50;
		sign =test_for_prime(number);
	}
}

long test_for_prime(long a) {
	int i;
	for(i =2;i<=a / 2;i++) {
		if(a%i ==0){
			return 0;
		}
	}
	return 1;
}

long compute_e(long a,long b) {
	long e=0,y=0,N;
	N = (a-1) * (b-1);
	while(y!=1) {
		e =rand() %N;
		y =gcd(e,N);
	}
}

long compute_d(long e,long b,long c) {
	long d=0,x=0,i=(b-1) * (c-1);
	while(d!=1){
		i--;
		d = (i*e) % ((b-1) * (c-1));
	}
	return i;
}

long gcd (long a,long b) {   //great common divisor
	int i,gcd,bg,sl;
	if(a >b) {
		bg=a; 
		sl=b;
	}
	else {
		bg=b;sl=a;
	}

	for(i=sl;i>0;i--) {
		if(sl%i==0 && bg%i == 0) {
			gcd=i;
			break;
		}
	}
	return gcd;
}

long crypt(long m,long e,long n) {
	int result=1;
	while(e>0){
		if(e %2 == 1) {
			result = (result*m) %n;
		}
		e = e/2;
		m = (m*m) %n;
	}
	return result;
}













