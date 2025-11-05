#Explain segment tree. write various operation on segment tree and write C code to perform range sum Query using segment tree.

#include <stdio.h>

int tree[100];
int arr[100];

void build(int idx,int start,int end){
    if(start==end){
        tree[idx] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    build(idx*2,start,mid);
    build(idx*2+1,mid+1,end);
    tree[idx] = tree[idx*2] + tree[idx*2+1];
}

int query(int idx,int start,int end,int l,int r){
    if(r < start || l > end) return 0;
    if(l <= start && end <= r) return tree[idx];
    int mid = (start+end)/2;
    return query(idx*2,start,mid,l,r) + query(idx*2+1,mid+1,end,l,r);
}

void update(int idx,int start,int end,int pos,int val){
    if(start==end){
        arr[pos] = val;
        tree[idx] = val;
        return;
    }
    int mid=(start+end)/2;
    if(pos<=mid) update(idx*2,start,mid,pos,val);
    else update(idx*2+1,mid+1,end,pos,val);

    tree[idx] = tree[idx*2] + tree[idx*2+1];
}

int main(){
    int n = 5;
    arr[0]=2; arr[1]=1; arr[2]=3; arr[3]=4; arr[4]=5;

    build(1,0,n-1);

    printf("Sum 1 to 3 = %d\n",query(1,0,n-1,1,3));

    update(1,0,n-1,2,10); // update arr[2] = 10

    printf("After update Sum 1 to 3 = %d\n",query(1,0,n-1,1,3));

    return 0;
}
