void my_exit(void)
{
 printf(“Exiting program\n”);
 if (ptr)
 {
/* Deallocation in my_exit */
 free(ptr);
 }
}
void test(void)
{
puts(“In test”);

exit(0);
}