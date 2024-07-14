#include <stdio.h>
#include "struct.h"

void save_buf(char* file, buf1 b){
FILE* f = fopen(file, "w");
char buf[12]={0}, *p=buf+11;
for (int n=b.h;n;n/=10) *--p =n%10+'0';
fwrite(buf, 1, 12, f);
fputc('\n', f);    p=buf+11;
for (int n=b.w;n;n/=10) *--p =n%10+'0';
fwrite(buf, 1, 12, f);
fputc('\n', f);
fwrite(b.c, 1, b.h*b.w, f);
fputc('\n', f);
fclose(f);}
