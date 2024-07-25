#include "h.h"

char* itos(unsigned int i){
char *buf =calloc(12, 1), *p =buf+11;
for (int n =i; n; n/=10){
	*p = n%10;
	p--;}
return buf;}

unsigned int stoi(char* buf){
unsigned int i = 0;
for (int n =0; n <12; n++){
	i *= 10;
	i += buf[n];}
return i;}
