#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct sensor {
	float value;
	char sensorname[20];
} sensor;

sensor *maxi(sensor *p,int count) {
	int i;
	sensor *max;
	max=&p[0];
	for(i=0; i<count; i++) {                      /*1*/
		if(max->value<p[i].value) {
			max=&p[i];
		}
	}
	return max;
}


int main(void) {
	sensor *p=malloc(100*sizeof(sensor));
	sensor *q=NULL;
	int count=0;
	if(p==NULL)	{
		printf("wufashenqingzhizhen");
		return 1;
	} else {
		while(1) {
			scanf("%s",p[count].sensorname);   
			if(strcmp(p[count].sensorname,"END")==0) {
				break;
			}
			count++;
			scanf("%f",&p[count].value);
		}
		q=maxi(p,count);
	}
	printf("%s %.1f",q->sensorname ,q->value );
}
