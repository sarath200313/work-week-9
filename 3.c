#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fptr;
    char c;
    int words=0,chr=0;
    fptr=fopen("C:\\Users\\vadde\\OneDrive\\Desktop\\textq1.txt","r");
    if(fptr == NULL) {
      perror("Error opening file");
      return(-1);
   }
   c = fgetc(fptr);
    while(c!= EOF ){
        if(c==' ' || c=='\n')
			words++;
		else
			chr++;
		c=fgetc(fptr);	
    }
    printf("there are %d words and %d characters in the file",words,chr);
    fclose(fptr);
    return 0;
}
