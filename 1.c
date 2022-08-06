#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fptr;
    int n;
    puts("Enter the no.of student names :");
    scanf("%d",&n);
    char data[100];
    fptr=fopen("C:\\Users\\vadde\\OneDrive\\Desktop\\textq1.txt","w");
    if(fptr == NULL) {
      perror("Error opening file");
      return(-1);
   }
    for(int i=0;i<n;i++){
        scanf("%s",data);
        fprintf(fptr,"%s\n",data);
    }
    fclose(fptr);
    return 0;
}
