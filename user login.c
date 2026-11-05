#include<stdio.h>
#include<stdlib.h>
typedef struct user_info {
	char name[20];
	char username[20];
	char gmail[30];
	int times;
} user_info;

int main(void) {
	FILE *f;
	user_info *temp=malloc(100*sizeof(user_info));
	int *p=malloc(100*sizeof(int));
	user_info *max=NULL;
	int i=0,count=0;
	printf("please enter the uses'name,username,gmail and login times(end with a zero):");
	f=fopen("users.txt","w");
	if(f==NULL) {
		return 1;
	}
	while(1) {
		scanf("%s",(temp+i)->name);
		getchar();
		if(*(temp+i)->name=='0') {
			break;
		}
		scanf(" %s %s %d",(temp+i)->username,(temp+i)->gmail,&(temp+i)->times);
		fprintf(f,"%s %s %s %d\n",(temp+i)->name,(temp+i)->username,(temp+i)->gmail,(temp+i)->times);
		count++;
		i++;

	}
	fclose(f);
	f=fopen("users.txt","r");
	for(i=0; i<count; i++) {
		fscanf(f,"%s %s %s %d\n",(temp+i)->name,(temp+i)->username,(temp+i)->gmail,&(temp+i)->times);
	}
	max=temp;
	for(i=0; i<count; i++) {
		if(max->times<(temp+i)->times) {
			max=(temp+i);
		}

	}
	printf("name:%s\nusername:%s\ngmail:%s\ntimes:%d\n",max->name,max->username,max->gmail,max->times);
	fclose(f);
	free(p);
	free(temp);
	return 0;

}
