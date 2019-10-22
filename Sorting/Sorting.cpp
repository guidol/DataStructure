#include<iostream>
using namespace std;

class sorting{

    public:
    void BubbleSort(int a[], int n);
    void InsertionSort(int a[], int n);
    void SelectionSort(int a[], int n);
    void QuickSort(int a[], int l, int h);
    void swap(int *x, int *y);
    void Merge(int a[], int l, int m, int h);
    void ImergeSort(int a[], int n);
    void MergeSort(int a[], int l, int h);
    void CountSort(int a[],int n); // 리소스의 제한이 없을 때 사용, 빠름.
    void ShellSort(int a[], int n);//많은 양의 elements를 sorting하는데 유리함.
    int findMax(int a[], int n);
    int Partition(int a[], int l, int h);
};
void sorting::swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void sorting::BubbleSort(int a[], int n){
   
    
     int i,j,flag=0;

   
         for(i=0; i < n-1 ; i++){
             flag = 0;
             for(j=0; j < n-1-i ; j++){
                 if(a[j] > a[j+1]){
                     swap(&a[j], &a[j+1]);
                     flag = 1;
                 }
             }
             if(flag == 0)
                 break;
         }
}
void sorting::InsertionSort(int a[], int n){
    int i,j,x=0;
    for(i = 1; i < n; i++){
        j = i - 1;
        x = a[i];
        while(j > -1 && a[j] > x){
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}
void sorting::SelectionSort(int a[],int n){
    int i,j,k=0;
    for(i = 0; i < n-1 ; i++){
        for(j=k=i; j < n ; j++){
            if(a[j] < a[k])
                k=j;
        }
        swap(&a[i],&a[k]);
    }
}
int sorting::Partition(int a[], int l, int h){
    int pivot = a[l];
    int i=l, j=h;

    do{
        do{i++;}while(a[i] <= pivot);
        do{j--;}while(a[j] > pivot);
        if(i < j)
            swap(&a[i], &a[j]);
    }while(i < j);
        swap(&a[l], &a[j]);
    return j;
}
void sorting::Merge(int a[], int l, int m, int h){
    int i=l,j=m+1,k=l;
    int b[100];

    while(i <= m && j <=h){
        if(a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    for(; i <= m; i++) // remain elements
        b[k++] = a[i];
    for(; j <= h; j++)
        b[k++] = a[j]; // remain elements
    for(i=l ;i <= h; i++)
        a[i] = b[i];
}
void sorting::ImergeSort(int a[], int n){
    int p,i,l,m,h;
    for(p=2; p <= n ; p=p*2){
        for(i=0; i+p-1<=n; i=i+p){
            l=i;
            h=i+p-1;
            m=(l+h)/2;
            Merge(a,l,m,h);
        }
    }
    if(p/2 < n)
        Merge(a,0,p/2-1,n-1);
 }
 void sorting::MergeSort(int a[], int l, int h){
     int mid;
     mid = (l+h)/2;
     if(l<h){
         MergeSort(a,l,mid);
         MergeSort(a,mid+1,h);
         Merge(a,l,mid,h);
     }
 }
void sorting::QuickSort(int a[], int l, int h){
    int j;
    if(l < h){
        j = Partition(a, l, h);
        QuickSort(a, l, j);
        QuickSort(a, j+1, h);
    }
}
int sorting::findMax(int a[], int n){
    int i;
    int max = INT32_MIN;
    for(i=0; i < n; i++){
        if(a[i] > max)
        max = a[i];
    }
    return max;
}
void sorting::CountSort(int a[], int n){
    int max,i,j;
    int *C;
    max = findMax(a,n);
    C = new int[max+1];
    for(i=0; i < max+1 ; i++){
            C[i] = 0;
    }
    for(i=0; i < n; i++){
        C[a[i]]++;
    }
    i=0, j=0;
    while(i < max+1){
        if(C[i] > 0){
            a[j++] = i;
            C[i]--;
        }
        else
            i++;
    }
}
void sorting::ShellSort(int a[], int n){
    int i,j,temp,gap;
     for(gap = n/2; gap >= 1; gap/=2){  
        for(i=gap; i < n ; i++){
            temp = a[i];
            j = i - gap;
            while(j >= 0 && a[j] > temp){
                a[j + gap] = a[j];
                j = j - gap;
            }
            a[j + gap] = temp;
        }
    }
}

int main(){
    int A[] = {11,13,7,12,16,9,24,5,10,3};
    int n=10;
    sorting srt;
    srt.ShellSort(A,n);
    for(int i=0 ; i < 10 ; i++)
        cout<<" "<<A[i];
    cout<<endl;
    return 0;
}

