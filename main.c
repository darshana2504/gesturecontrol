#include<stdio.h>
#include<string.h>

struct Company
{
char N1[100];
//N1 is first name

char N2[100];
//N2 is last name

char G[100];
//G is gender

char P[100];
//P is position

int S;
//S is Salary

int A;
//A is age

int Y;
//Y is year of joining company

int U;
//U is unique ID no

int E;
//E is experience in years
};

struct Company W[50];
struct Company temp;

FILE *fp;
int delete(int a,int b);
int add(int c);
void display(int h);
void new(int j);
int sort(int a, int b);
int edit(int a);
int e,s;

int main()

{
int j,i,b,y,k;

printf("Enter number of employees in the company\n");
scanf("%d",&i);


if(i>50)
{
printf("Too many employees\n");
}
else
{
for(b=1;b<=i;b++)
{
new(b);
}
}

q:

printf("What would you like to do now\n");
printf("1-Display the database\n");
printf("2-Add an entry\n");
printf("3-Search for an entry\n");
printf("4-Edit entry\n");
printf("5-Delete an entry\n");
printf("6-Sorting\n");
printf("7-Exit\n");
scanf("%d",&k);
switch(k)
{

case 1:
/*If 1 is entered all entries in the database will be displayed*/

{
for(j=1;j<=i;j++)
{
display(j);
}
break;
}


case 2:
//If 2 entered new entry can be added

i=add(i);
break;


case 3:
//If 3 is entered using unique id from user an entry will be displayed

{
printf("Enter unique id of the employee\n");
scanf("%d",&b);
display(b);
break;
}

case 4:
//If 4 is entered the entry having the unique id from the user will be edited

{
printf("Enter unique id of the employee entry you want to edit");
scanf("%d",&b);
edit(b);
break;
}

case 5:
//If 5 is entered the entry having unique id taken from user will be deleted
{
printf("Enter unique id of the employee entry you want to delete\n");
scanf("%d",&b);
i=delete(i,b);
printf("The entry has been deleted succesfully\n");
break;
}


case 6:
//If 6 is entered options for sorting will be displayed

{
printf("How do you wish to sort?\n");
printf("According to:\n");
printf("1.Salary\n");
printf("2.Year of joining\n");
printf("3.Age\n");
scanf("%d",&b);
sort(i,b);
break;
}


case 7:
//This will exit the program

goto d;
}
goto q;
d:
return 0;
}


void new(int j)
//This function is used for filling up database

{
char x[1000];
int y;
printf("Enter first name of Employee\n");
scanf("%s",x);
strcpy( W[j].N1, x);
printf("Enter last name of Employee\n");
scanf("%s",x);
strcpy(W[j].N2,x);
printf("Enter position of employee\n");
scanf("%s",x);
strcpy( W[j].P, x);
printf("Enter Gender-M/F\n");
scanf("%s",x);
strcpy( W[j].G, x);
W[j].U=j;
printf("Enter experience in years\n");
scanf("%d",&y);
W[j].E=y;
e:
printf("Enter year of joining\n");
scanf("%d",&y);
if(y>=2000 && y<2016)
W[j].Y=y;
else
{
printf("Please check your entry\n");
goto e;
}

printf("Enter the salary of the Employee\n");
scanf("%d",&y);
W[j].S=y;
f:
printf("Enter age of Employee\n");
scanf("%d",&y);
if(y>=22 && y<=65)
W[j].A=y;
else
{
printf("Please check your entry\n");
goto f;
W[j].U=j+1;
}

}

void display(int h)
//This funtion is to display all entries in the database

{
printf("The unique id number is :%d\n",W[h].U);
printf("Name:%s %s\n",W[h].N1,W[h].N2);
printf("%s\n",W[h].P);
printf("%s\n",W[h].G);
printf("Year of Joining: %d\n",W[h].Y);
printf("Salary:%d\n",W[h].S);
printf("Age:%d\n",W[h].A);
printf("Experience:%d\n",W[h].E);
printf("\n");
return;
}



int add(int c)
/*This function is for addition of an entry*/

{
c=c+1;
if(c>50)
printf("More than 50 entries are not possible\n");
else
new(c);
return c;
}


int delete(int i,int b)
//This function is used for deleting an entry

{
int k,j;
for(k=1;k<=i;k++)
{
if(b==W[k].U)
{
for(j=k;j<=i;j++)
{
W[j]=W[j+1];
}
}
}
i=i-1;
for(j=1;j<=i;j++)
{
display
(j);
}
return i;
}


int sort(int a, int b)
//This function is for sorting the elements

{
int i,j,k;
switch(b)
{
case 1:
{
for(k=1;k<=a;k++)
{
for(j=1;j<=a;j++)
{
if(W[j].S>W[j+1].S)
{
temp=W[j];
W[j]=W[j+1];
W[j+1]=temp;
}
}
}
for(i=2;i<=a+1;i++)
{
display(i);
}
break;
}
case 2:
{
for(k=1;k<=a;k++)
{
for(j=1;j<=a;j++)
{
if(W[j].Y>W[j+1].Y)
{
temp=W[j];
W[j]=W[j+1];
W[j+1]=temp;
}
}
}
for(i=2;i<=a+1;i++)
{
display(i);
}

break;
}
case 3:
{
for(k=1;k<=a;k++)
{
for(j=1;j<=a;j++)
{
if(W[j].A>W[j+1].A)
{
temp=W[j];
W[j]=W[j+1];
W[j+1]=temp;
}
}
}
for(i=2;i<=a+1;i++)
{
display(i);
}
break;
}
}
}



int edit(int a)
//This function is for editing an entry

{
int d;
display(a);
printf("What would you like to edit?\n");
printf("1-First Name\n 2-Last Name\n 3-Gender\n 4-Position\n 5-Salary\n 6-Age\n 7-Year of Joining Company\n 8-Experience\n");
scanf("%d",&d);
switch(d)
{
case 1:
{
printf("Enter new  first name\n");
scanf("%s",W[a].N1);
break;
}
case 2:
{
printf("Enter new last name\n");
scanf("%s",W[a].N2);
break;
}
case 3:
{
printf("Enter new  gender\n");
scanf("%s",W[a].G);
break;
}
case 4:
{
printf("Enter new  position\n");
scanf("%s",W[a].P);
break;
}
case 5:
{
printf("Enter new  salary\n");
scanf("%d",&W[a].S);
break;
}
case 6:
{
printf("Enter new age\n");
scanf("%d",&W[a].A);
break;
}
case 7:
{
printf("Enter new  year of joining\n");
scanf("%d",&W[a].Y);
break;
}
case 8:
{
printf("Enter new experience\n");
scanf("%d",&W[a].E);
break;
}
}
}


