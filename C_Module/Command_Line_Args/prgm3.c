/*Environmental variables in c are key-value pairs maintained by the os that provide configuration and system
information,which is a c program can access or modify to control its behaviour without changing tnhe source code.These
variables hold information such as directory path,user-specific settings,runtime parameters,and other values
that programs or the OS may require.*/
#include<stdio.h>
int main(int argc, char** argv, char* envp[])
{
    int i = 0;
    while (envp[i] != NULL)
    {
        printf("%s\n", envp[i]);
        i++;
    }
}