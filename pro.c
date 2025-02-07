#include<stdio.h>
void fabrice(int a,int d){
	int k;
	   k=a;
	   a=d;
	   d=k;

	   	
}

int main(){
	int a=2;
	int d=3;
	
	fabrice(a,d);
	
	   	printf("a:%d\nd:%d\n",a,d);
	   		printf("a:%d\nd:\n",a,d);

}
