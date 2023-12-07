#include<stdio.h>
#include<string.h>
void prefix(int pi[],char p[]){
	int n=strlen(p);
	int k=0,q,i;
	pi[1]=0;
	for(q=2;q<=n;q++){
		while(k>0 && pi[k]!=p[q-1])
		{
			k=pi[k];
		}
		if(pi[k]==p[q-1]){
			k=k+1;
		}
		pi[q]=k;
	}
	for(i=0;i<n;i++){
		printf("%d",pi[i]);
	}
	
}
void kmp(char t[],char p[]){
	int n=strlen(t);
	int m=strlen(p);
	int pi[m+1];
	prefix(pi,p);
	int q=0,i;
	for(i=0;i<=n;i++){
		while(q>0 && p[q]!=t[i]){
			q=pi[q];
		}
		if(p[q]==t[i]){
			q=q+1;
		}
		if(q==m){
			printf("pattern occurs at %d\n",i-m+1);
			q=pi[q];
		}
	}
}
int main()
{
	char t[20],p[20];
	printf("enter text");
	scanf("%s",t);
	printf("enter pattern");
	scanf("%s",p);
	kmp(t,p);
	return 0;
}
