#include <stdio.h>
#include <stdlib.h>
int search(char*, char*);
int strln(char*);
void del(char*, char*);
void insert(char*, char*, int);
void replace(char*, char*, char*);

int main() {
	char s1[100]="I am not a student! You are not a Prof.";
	char s2[]="not ";
	char s3[]="actually ";
//	del(s1, s2);
//  replace(s1, s2, s3);
	insert(s1, s2, 5);
	printf("%s", s1);
}

int strln(char arr[]) {
	int count=0, i;
	for(i=0; arr[i]!='\0'; i++) {
		count++;
	}
	return count;
}

int search(char s1[], char s2[]) {
	int i, j;
	for(i=0; s1[i]!='\0'; i++) {
		j=0;
		while(s1[i+j]==s2[j] && s2[j]!='\0') {
			j++;
		}
		while(s2[j]=='\0') {
			return i;
		}
	}
	return -1;
}

void del(char s1[], char s2[]) {
	int p=search(s1, s2);
	int l=strln(s2);
	int i=0;

	while((p=search(s1, s2))!=-1) {
		for (i = p; s1[i + l]!='\0'; i++) {
			s1[i] = s1[i + l];
		}
        s1[i] = '\0';
	}
}

void insert(char s1[], char s2[], int p) {
	int s2l=strln(s2);
	int s1l=strln(s1);
	int i;
	for(i=s1l; i>=p; i--) { //leaving space for new word to insert
		s1[i+s2l]=s1[i];
	}
	for(i=0; i<s2l; i++) {
		s1[p+i]=s2[i];
	}
}

void replace(char str[], char old[], char word[]) {
	int p=search(str, old);
	if (p==-1) {
		return;
	}
	int oldl=strln(old);
	int wordl=strln(word);
	int strl=strln(str);
	
	int k;
	if (wordl>oldl) { //new word is longer than old ones
		for(k=strl; k>=p+oldl; k--) {
			str[k+(wordl-oldl)]=str[k];
		}
	}
	else if (wordl<oldl) { //old word is longer than new ones
		for(k=p+oldl; k<=strl; k++) {
			str[k-(oldl-wordl)]=str[k];
		}
	}
	for (k=0; k<wordl; k++) {
		str[p+k]=word[k];
	}
}




















