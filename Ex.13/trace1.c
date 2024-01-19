
// Напишете какво ще бъде изведено на стандартния изход като резултат от изпълнението на дадения по-долу фрагмент от програма на С

……… int pid, var = 1, status;

if ((pid = fork()) == 0) //if we are in the child
{
    var += 2; // var=3
    printf(“\n Var = % d “, var); // Var =3
}
else
{
    wait(&status);
    var++; // var =2;
    printf(“\n Var = % d “, var); // Var = 2
    exit(0);
}
--var;  
printf(“\n Var = % d “, var); // Var=2
