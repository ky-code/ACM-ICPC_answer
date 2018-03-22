#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main(){
	char ope[100];
	int n,len,ans[200],top[200],a,b,num[200],level[200],t,u,v,stack[100][100],i,j,s,last[200];
	int count=0;

	for(i=0;i<=100;i++){
		ans[i]=0;
	}

	while(1){
		scanf("%d",&n);
		if(n==0){
			break;
		}
		count++;
		for(i=0;i<=50;i++){
			for(j=0;j<=50;j++){
				stack[i][j]=0;
			}
		}
		for(i=0;i<=100;i++){
			top[i]=0;
			num[i]=0;
			level[i]=0;
		}
		for(i=1;i<=n;i++){
			scanf("%s",&ope);
			len=strlen(ope);
			level[i]=len-1;
			last[i]=ope[len-1];
			if(last[i]==43){
				num[i]=50;
			}else if(last[i]==42){
				num[i]=100;
			}else if(last[i]>=48&&last[i]<=57){
				num[i]=last[i]-48;
			}
		}
		for(i=n;i>=1;i--){
			if(num[i]>=0&&num[i]<=9){
				t=level[i];
				top[t]++;
				s=top[t];
				stack[t][s]=num[i];
			}else if(num[i]==50){
				t=level[i]+1;
				s=top[t];
				u=0;
				for(j=1;j<=s;j++){
					u=u+stack[t][j];
					stack[t][j]=0;
				}
				top[t-1]++;
				v=top[t-1];
				stack[t-1][v]=u;
				top[t]=0;
			}else if(num[i]==100){
				t=level[i]+1;
				s=top[t];
				u=1;
				for(j=1;j<=s;j++){
					u=u*stack[t][j];
					stack[t][j]=0;
				}
				top[t-1]++;
				v=top[t-1];
				stack[t-1][v]=u;
				top[t]=0;
			}
		}
		ans[count]=stack[0][1];
	}
	for(i=1;i<=count;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}

