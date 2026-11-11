#include<stdio.h>
#include<stdlib.h>

typedef struct cars {
	char number[50];
	char name[50];
	int price;
	float km;
} cars;

cars *sortbyPrice(cars *p,int count) {
	int i,j;
	cars temp;
	for(i=0; i<count-1; i++) {
		for(j=0; j<count-1-i; j++) {
			if((p+j)->price>(p+j+1)->price) {
				temp=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=temp;
			}
		}
	}
	return p;
}

cars *sortbyKm(cars *p,int count) {
	int i,j;
	cars temp;
	for(i=0; i<count-1-i; i++) {
		for(j=0; j<count-1; j++) {
			if((p+j)->km>(p+j+1)->km) {
				temp=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=temp;
			}
		}
	}
	return p;
}

int main(void) {
	int i=0,count=0;
	cars *p=calloc(500,sizeof(cars));
	FILE *cars_info;
	FILE *sortbyprice;
	FILE *sortbykm;
	if(p==NULL) {
		printf("ERROR1");
		return 1;
	}
	printf("Please end with a zero:");
	cars_info=fopen("cars.txt","w");
	if(cars_info==NULL) {
		printf("ERROR2");
		return 1;
	}
	while(1) {
		printf("Enter the %dth information:",i+1);
		scanf("%s",(p+i)->number);
		if(strcmp((p+i)->number,"0")==0) {
			break;
		}
		scanf("%s %d %f",(p+i)->name,&(p+i)->price,&(p+i)->km);
		printf("Read successfully!\n");
		fprintf(cars_info,"%s/ %s/ %d/ %.3f\n",(p+i)->number,(p+i)->name,(p+i)->price,(p+i)->km);
		i++;
		count++; 
	}
	fclose(cars_info);
	*sortbyPrice(p,count);
	sortbyprice=fopen("price.txt","w");
	if(sortbyprice==NULL) {
		printf("ERROR2");
		return 1;
	}
	for(i=0; i<count; i++) {
		fprintf(sortbyprice,"%s/ %s/ %d/ %.1f\n",(p+i)->number,(p+i)->name,(p+i)->price,(p+i)->km);
	}
	fclose(sortbyprice);
	*sortbyKm(p,count);
	sortbykm=fopen("km.txt","w");
	if(sortbykm==NULL) {
		printf("ERROR2");
		return 1;
	}
	for(i=0; i<count; i++) {
		fprintf(sortbykm,"%s/ %s/ %d/ %.1f",(p+i)->number,(p+i)->name,(p+i)->price,(p+i)->km);
	}
	fclose(sortbykm);
	return 0;
}
