#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fptr;
    char data[100];
    fptr=fopen("C:\\Users\\vadde\\OneDrive\\Desktop\\textq1.txt","r");
    if(fptr == NULL) {
      perror("Error opening file");
      return(-1);
   }
    for(int i=0;i<3;i++){
        fscanf(fptr,"%s",data);
        printf("%s\n",data);
    }
    fclose(fptr);
    return 0;
}
