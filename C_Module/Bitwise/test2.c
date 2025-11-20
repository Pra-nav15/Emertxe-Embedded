void fun(int n);
int main()
{
    int num = 3;
    fun(3);
}
void fun(int n)
{
    if (n <= 1)
    {
        return;
    }
    else
    {
        fun(n - 1);
        fun(--n);
        printf("%d", n);
    }
}