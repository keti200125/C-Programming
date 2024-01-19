// Какво ще бъде изведено на стандартния изход като резултат от изпълнението на дадения по-долу фрагмент от програма на Си
………
#define COM  “ps”
int main()
{
    int i = 2, status;
    if (fork()) // if we are in the parent
    {
        wait(&status);
        --i;
        printf( “ Stoinostta na i = % d;”, i); // i=1;
    }
    else
    {
        i++; // i =3 
        if (execlp(COM, COM, 0) == -1) // provides information about currently running processes. 
        {
            i = i + 2;
            printf( “ Stoinostta na i = % d;”, i);
        }
    }
    printf( “ Stoinostta na i = % d;”, --i);
}
// currently wokring processes (информация за процесите в системата)
// Stoinostta na i e 1
// Stoinostta na i e 0