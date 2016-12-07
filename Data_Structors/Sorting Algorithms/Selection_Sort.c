
#include <stdio.h>
#include <stdlib.h>


int main(){

int array[100],size,c,d,position,swap;

printf("Enter number of elements\n");

scanf("%d",&size);

printf("Enter %d integers\n",size);
// Inject values into the array
for(c=0; c<size;c++){
	scanf("%d",&array[c]);
	}

for(c=0;c<(size-1);c++){
	position=c;
	
	for(d=c+1; d<size ; d++){
		if(array[position] > array[d]){
			position=d;
			}
		}
		
	if(position != c){
		swap=array[c];
		array[c]=array[position];
		array[position]=swap;
		}
	}

printf("Sorted list in ascending order : \n");

for(c=0; c<size ; c++){
	printf("%d\n",array[c]);
	}

return 0;

}
