#include<stdio.h>
main(){
	int player,max,min,p[1000],gapmax,gap,ans[10000],i,pass,j;
	int count=0;
	for(i=0;i<=8000;i++){
		ans[i]=0;
	}
	while(1){
		scanf("%d %d %d",&player,&min,&max);
		if(player==0){
			break;
		}else{
			count++;
			gapmax=-1;
			pass=0;
			for(j=0;j<=500;j++){
				p[j]=0;
			}
			for(j=1;j<=player;j++){
				scanf("%d",&p[j]);
			}
			for(j=min;j<=max;j++){
				gap=p[j]-p[j+1];
				if(gap>=gapmax){
					pass=j;
					gapmax=gap;
				}
			}
			ans[count]=pass;
		}
	}
	for(i=1;i<=count;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
