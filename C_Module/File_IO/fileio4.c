#include<stdio.h>
int main()
{
    FILE *fptr;
    char ch;

    fptr= fopen("file.txt","w");// reading a file in write mode
    ch=fgetc(fptr); // This should fail since reading a file from write mode//
    if(ferror(fptr)) // ferror to check any errors in the file operations
    {
        fprintf(stderr,"Error in reading file : file.txt\n");
    }
    clearerr(fptr); // used to clear the error flag
    
    //This will not execute since stderr is cleared
    if(ferror(fptr))
      fprintf(stderr,"Error in reading file : file.txt\n");
    fputc(ch,stdout);
    fclose(fptr);
}