//lru

#include<stdio.h>
int findLRU(int times[],int n)
{
	int min=times[0];
	int pos=0;
	for(int i=0;i<n;i++)
	{
		if(times[i]<min)
		{
			min=times[i];
			pos=i;
		}
	}
	return pos;
}

int main()
{
	int n;
	printf("enter the number of pages ");
	scanf("%d",&n);
	int ref_str[n];
	int nf,pf=0;
	printf("\ne enetr the number of frames  ");
	scanf("%d",&nf);
	printf("eneter the referenece string ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ref_str[i]);
	}
	int frames[nf];
	for(int i=0;i<nf;i++)
	frames[i]=-1;
	for(int i=0;i<n;i++)
	{
		int least,times[100];
		int s=0;
		for(int j=0;j<nf;j++)
		{
			if(frames[j]==ref_str[i])
			{
				s++;
				pf--;
			}
		}
		
		pf++;
		if((pf<=nf)&&s==0)
		{
			frames[i]=ref_str[i];
		}
		else if(s==0)
		{
			for(int j=0;j<nf;j++)
			{
				for(int k=0;k<i;k++)
				{
					if(frames[j]==ref_str[k])
					{
						times[j]=k;
					}
				}
			}
			least=findLRU(times,nf);
			frames[least]=ref_str[i];
		}
		printf("\n");
		printf("%d:",ref_str[i]);
		for(int k=0;k<nf;k++)
		{
			if(frames[k]!=-1)
			printf("%d",frames[k]);
			else
			printf("_");
		}
	}
	printf("\npage fault : %d ",pf);
}
