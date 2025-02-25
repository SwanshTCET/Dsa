#include<stdio.h>
void display(int data[], int next[], int start);
void find(int data[],int next[], int start, int x);
void insert(int data[],int next[], int start, int x, int len);
void insertafter(int data[],int next[], int start, int x, int len,int inspos);
void delete(int data[],int next[],int start,int y);
void main(){
	int data[6] = {5,13,10,20,8,0};
	int next[6] = {3,4,0,1,-1,-1};
	int start = 2;
	display(data,next,start);
	find(data,next,start,20);

}

void display(int data[], int next[], int start){
	for(int pos=start;pos!=-1;pos=next[pos]){
		printf("%d->",data[pos]);
	}
	printf("NULL\n");
}
void find(int data[],int next[], int start, int x){
	int pos=start;
	for(;(pos!=-1)&&(data[pos]!=x);pos=next[pos]){

	}
	if(pos<0){
		printf("Data Item %d is not found in the linked list\n",x);
    }
	else{
		printf("Data Item %d is found at position %d \n",x,pos);
	}
}
void insert(int data[],int next[], int start, int x, int len){
	int count = 0,lastPos=0;
	int available = 0;
	for(int pos=start;pos!=-1;pos=next[pos]){count++;lastPos = pos;}
	for(;available<len;available++){
		if((next[available]==-1)&&(available!=lastPos)){
			break;
		}			
	}
	if(available==len){
		printf("Array hosting our linked list is full\n"); 
	}else{
		next[lastPos]=available;
		data[available]=x;
	}
}
void insertafter(int data[],int next[], int start, int x, int len,int inspos){
    int lastPos=0;
	int available = 0;
	for(;available<len;available++){
		if((next[available]==-1)&&(available!=lastPos)){
			break;
		}			
	}
	if(available==len){
		printf("Array hosting our linked list is full\n"); 
	}
    else{
        next[available]=next[inspos];
		next[inspos]=available;
		data[available]=x;
	}

}

void delete(int data[],int next[],int start,int x){
    int i=start,prev;
    for(i;(i!=-1)&&(data[i]!=x);i=next[i]){
        prev=i;
        printf("%d\n",prev);
    }
    next[prev]=next[next[prev]];
}
