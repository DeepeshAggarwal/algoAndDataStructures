#include<stdio.h>
int main()
{
	int n,i,j,elt,s,f;

	scanf("%d",&n);

	int num[n];

	scanf("%d",&elt);

	num[0]=elt;

	for(i=1;i<n;i++)
	{
		scanf("%d",&elt);

		s=i;
		f=(s-1)/2;
		while(s>0 && num[f] < elt)
		{
			num[s]=num[f];
			s=f;
			f=(s-1)/2;
		}
		num[s]=elt;
	}
	for(i=n-1;i>0;i--)
	{
		elt=num[i];
		num[i]=num[0];
		f=0;
		if(i==1)
			s=-1;
		else
			s=1;

		if(i>2 && num[2]>num[1])
			s=2;

		while(s>0 && elt < num[s])
		{
			num[f]=num[s];
			f=s;
			s=2*f+1;
			if(s+1<=i-1 && num[s]<num[s+1])
				s=s+1;

			if(s>i-1)
				s=-1;
		}
		num[f]=elt;
	}

	printf("\n");

	for(i=0;i<n;i++)
		printf("%d\t",num[i]);

	printf("\n");

	return 0;

}
