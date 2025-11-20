Storage classes

------------------------

\[auto

register

static]-- apply only on local variables only



local varibles-in the main function

auto-  just declare local variable without any storage class it will be auto as default memory allocated in stack

it will be valid only in the given scope(Block)





if a pointer is pointing to an address which is not valid such pointers are called dangling pointers.





\#include<stdio.h>

int\* foo()

{

int i=10;

int \*j=\&i;

return j;

}

int main()

{

int\* i;

i=foo();

printf("j %d\\n",\*i);

return 0;

}





can be done on strings also



\#include<stdio.h>

char\* foo()

{

&nbsp; char ca\[12]="Hello World" // string

char\* cptr=ca; //char ptr

return cptr;

}

int main()

{

&nbsp;  char \*ca; // char ptr-->dangling ptr

ca=foo();

printf("cas is %s\\n",ca);

return 0;

}







\#include<stdio.h>

int main()

{

&nbsp;int i=25;

&nbsp; { //inner block

&nbsp;    int j=10;

&nbsp;    printf("j is %d\\n",j);

&nbsp;    printf("i is %d\\n",i);

&nbsp;}

&nbsp;printf("j is %d\\n",j);

&nbsp;printf("i is %d\\n",i);-----> leads to compilation error j undeclared because j has th scope only in the inner block and not outside

&nbsp;}                             but i has the scope in both inner and outer block

&nbsp;                             -->if two variable names are same it should have different scope then it is valid

&nbsp;                             -->multiple definition in same scope gives compiler error ex: int i; 

&nbsp;                                                                                           int i; (in same scope)

&nbsp;                            



Register

-------------------------------------



It is appilicable only on local variables.

-If we use register we are requesting cpu for allocating memory in cpu registers.

-This allocation is done in run time but we dont know the compiler will allocate in cpu register or stack depending on  the frequency of occurence  irrespective of you saying it will decide and allocate.

-But at compile time the compiler thinks memory is allocated in cpu register

-You cannot request the address of cpu registers



\#include<stdio.h>

int main()

{

&nbsp; //register int i=10;

&nbsp; register int i;

}

\#if 1

&nbsp; printf("Enter the value of i\\n");

&nbsp; scanf("%d".\&i);---->give compilation error you cannot request th adrressof the register variable

&nbsp; return 0;

}



(dereferencing works printing address doesn't work)



\#include<stdio.h>

int main()

{

&nbsp; int i=25;//auto

&nbsp; register int \*j=\&i;

&nbsp; 

&nbsp; printf("j is %d\\n",\*j);// works

//printf("j is %p\\n",\&j); // compiler error

&nbsp; printf("j %p\\n",j); //works

return 0;

}



static

----------------------------------------------

\- memory allocated in the data segment

\#include<stdio.h>

int\* foo()

{

static int i=10; // memory allocated in data segment

int\* j=\&i;



return j;

int main()

{

&nbsp; int\* i;

&nbsp; i=foo();

&nbsp; printf("\*i =%d\\n",\*i);

&nbsp; return 0;

}





\#include<stdio.h>



int book\_ticket()

{

&nbsp;static int ticket\_sold=0; /\* once memory is allocated for ststic variable 

ticket\_sold++;

return ticket\_sold;

}



int main()

{

&nbsp; int count;

&nbsp; count = book\_ticket();

&nbsp;count = book\_ticket();

&nbsp;count = book\_ticket();

&nbsp;count = book\_ticket();

&nbsp;printf("sold %d\\n",count);

}





\#include<stdio.h>

int main()

{

&nbsp;  static int i=5;

&nbsp;  if(--i)

{

&nbsp; return main()// execute only one time return statement immediately // if main() execute 5 times

}

printf("i %d\\n,i);

return 0;

}



Global Variables

------------------------------

these are variable which are declared any where outside the main function.

int y;//global variables

int main()

{

&nbsp; int x;//local variables

}

int z; //global variables



Global variables memory allocated in data segment and default value is zero throughout entire program.



\#include<stdio.h>

int x;



int foo()

{

&nbsp; printf("x in fun %d\\n",x);



&nbsp; return ++x;

}

int main()

{

&nbsp;  foo();

&nbsp;  printf("x in main %d\\n",x);

}

O/p:

x in fun 0

x in main 1

(local variable have more precedence than global variable)



\#include<stdio.h>



int x;-------------------------------------------------------------(1)

int foo()

{

&nbsp; printf("x in fun %d\\n",x);



&nbsp; return ++x;

}

int main()

{

&nbsp;  {

&nbsp;    int x;  //only scope in the inner block local variable--------------(2)

&nbsp;  }

&nbsp;  foo();

&nbsp;  printf("x in main %d\\n",x);--------------------------------------(1) takes global variable x.

}



auto and register is valid only in local and not on global if so it will give compilation error.







\#include<stdio.h>



int x=10; // definition of global variable-- for definition memory will be allocated                         

int x; // tentative definition

int foo()

{

&nbsp; printf("x %d\\n",x);



&nbsp; return +0;

}

int main()

{

&nbsp;  foo();

&nbsp;  return 0;

}





tentative definition looks for definition in the linker stage (4th stage of compilation)

if definition found------------> it links to same variable

if definition not found--------------> then it allocates found in memory BSS(Block Started by Symbols)-->filled with zeros



int x=10;

int x=20;



it give scompilation error because redefinition of x.





multiple tentative definition will merge to single definition ,this rule  is called a one definition rule.





int x;---declaration

int x=10;---definition

int x;---tentative definition  

int x;// it will take on single definition because of multiple tentative definitions





gcc Compilation Stages

-----------------------------



$add.c--------------->$ gcc add.c ----------->a.out---------------->$./a.out---------------->O/p

&nbsp;                          |

&nbsp;                       4 stages here





(1) Preprocessor stage

-------------------------------

1. \#->preprocessor directories will be replaced in source file.
2. Macro will be  Sub.->ex: #define NUM 100
3. Comments will be removed
4. Condition compilation will be done  --->#if 1/0  { //code}

if there is any error in this stage it will give fatal error.

command ---> $gcc -E add.c  -----> this will give output add.i(intermediate file)

This intermediate file is input to Compilation stage.



(2) Compilation stage

-------------------------------------

1. Checks for syntax/Logical error
2. gives compiler error
3. command: $ gcc -S add.i--->gives add.s (Assembly source file)
4. this is input to next stage assembly stage.



(3) Assembly stage

---------------------------------------------

* &nbsp;.s------->.o (it is object file)
* &nbsp;command : $ gcc -c add.s
* &nbsp;it gives output as Machine language format with input assembly source file
* &nbsp;gives object file(add.o)



(4) Linker stage

-----------------------------------------

1. links the global or local or user defined functions (UDT) 
2. links multiple object file.
3. to get output as a.out(binary file)



$./a.out-------------> gives the Output.

