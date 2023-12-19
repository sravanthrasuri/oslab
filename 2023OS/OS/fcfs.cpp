#include<iostream>
using namespace std;
struct atbt{
	int at,bt;
	string p;
};
void sort(atbt a[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j].at>a[j+1].at){
				atbt t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}
void solve(atbt a[],int n,int c[],int ideal){
	int sum=ideal;
	int i=0;
	while(i<n){
		if(sum>=a[i].at){
			c[i]=a[i].bt+sum;
			sum=c[i];
			i++;
		}
		else
		sum=a[i].at;
	}
}
float avg(int a[],int n){
	float sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	return sum/n;
}
int main(){
	int n;
	cout<<"Enter the number of processors:";
	cin>>n;
	atbt a[n];
	cout<<"Enter the processor numbers, values of at and bt respectively:";
	for(int i=0;i<n;i++){
		cin>>a[i].p>>a[i].at>>a[i].bt;
	}
	sort(a,n);
	int c[n],ideal=0;
	if(a[0].at==0)
	solve(a,n,c,ideal);
	else{
		ideal=ideal+a[0].at;
		solve(a,n,c,ideal);
	}
	int tat[n],wt[n];
	for(int i=0;i<n;i++){
		tat[i]=c[i]-a[i].at;
		wt[i]=tat[i]-a[i].bt;
	}
	cout<<"Completion time ,turn around time and waiting time respectively"<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i].p<<" "<<c[i]<<" "<<tat[i]<<" "<<wt[i]<<endl;
	}
	cout<<"Avg turn around time:"<<avg(tat,n)<<endl;
	cout<<"Avg waiting time:"<<avg(wt,n)<<endl;
}
