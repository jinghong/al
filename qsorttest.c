#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//integer sort
int intCompare(const void * a, const void * b)
{
    return (*(int *)a - *(int *)b);
}
int integerSort()
{
    int intValues[100];
    srand(time(NULL));
    int i;
    for (i = 0; i < 100; i++)
        intValues[i]=rand()%1000;

    printf("-------------integer unsorted-------------\n");
    for (i = 0; i < 100; i++)
        printf("%d ",intValues[i]);
    putchar('\n');

    printf("-------------integer sorted-------------\n");
    qsort(intValues, sizeof(intValues) / sizeof(intValues[0]), sizeof(intValues[0]), intCompare);
    for (i = 0; i < 100; i++)
        printf("%d ",intValues[i]);

    putchar('\n');
    return 0;
}
//double sort
int doubleCompare(const void * a, const void * b)
{
    return *(double *)a > *(double *)b ? 1 : -1;
}
int doubleSort()
{
    double doubleValues[100];
    srand(time(NULL));
    int i;
    for (i = 0; i < 100; i++)
        doubleValues[i]=rand() /(double)(RAND_MAX/1000);

    printf("-------------double unsorted-------------\n");
    for (i = 0; i < 100; i++)
        printf("%10.4f ",doubleValues[i]);
    putchar('\n');

    printf("-------------double sorted-------------\n");
    qsort(doubleValues, sizeof(doubleValues) / sizeof(doubleValues[0]), sizeof(doubleValues[0]), doubleCompare);
    for (i = 0; i < 100; i++)
        printf("%10.4f ",doubleValues[i]);

    putchar('\n');
    return 0;
}

//string sort

int stringCmp(const void * a,const void *b)
{
    return strcmp((char *)a,(char *)b) ;
    //return strcmp((char *)b,(char *)a) ;
}

char* genRandomString(int length)
{
    int flag, i;
    char* string;
    srand(time(NULL));
    if ((string = (char*) malloc(length)) == NULL )
    {
        printf("alloc failed!flag:14\n");
        return NULL ;
    }

    for (i = 0; i < length - 1; i++)
    {
        flag = rand() % 3;
        switch (flag)
        {
            case 0:
                string[i] = 'A' + rand() % 26;
                break;
            case 1:
                string[i] = 'a' + rand() % 26;
                break;
            case 2:
                string[i] = '0' + rand() % 10;
                break;
            default:
                string[i] = 'x';
                break;
        }
    }
    string[length - 1] = '\0';
    return string;
}
char *random_uuid( char buf[37] )
{
    const char *c = "89ab";
    char *p = buf;
    int n;
    for( n = 0; n < 16; ++n )
    {
        int b = rand()%255;
        switch( n )
        {
            case 6:
                sprintf(
                    p,
                    "4%x",
                    b%15 );
                break;
            case 8:
                sprintf(
                    p,
                    "%c%x",
                    c[rand()%strlen( c )],
                    b%15 );
                break;
            default:
                sprintf(
                    p,
                    "%02x",
                    b );
                break;
        }
        p += 2;
        switch( n )
        {
            case 3:
            case 5:
            case 7:
            case 9:
                *p++ = '-';
                break;
        }
    }
    *p = 0;
    return buf;
}

int stringSort()
{
#define SIZE 20
    char s[SIZE][37];
    int i;
    for(i=0;i<SIZE;i++){
        random_uuid(s[i]);
    }
    printf("-------------string unsorted-------------\n");
    for(i=0;i<SIZE;i++)
    {
        printf("%s\n",s[i]);
    }
    printf("-------------string sorted-------------\n");
    qsort(s,SIZE,sizeof(s[0]),stringCmp);
    for(i =0;i<SIZE;i++)
    {
        printf("%s\n",s[i]);
    }
    return 0;
}

//struct sort
typedef struct
{
    int data;
    int value;
}X_S;

/* a->z */
int cmpfunA2Z(const void * a, const void * b)
{
    X_S * p1 = (X_S *)a;
    X_S * p2 = (X_S *)b;

    return p1->value > p2->value;
}
/* z -> a */
int cmpfunZ2A(const void * a, const void * b)
{
    X_S * p1 = (X_S *)a;
    X_S * p2 = (X_S *)b;

    return p1->value < p2->value;
}
/* value first data second */
int cmpfunVA(const void * a, const void * b)
{
    X_S * p1 = (X_S *)a;
    X_S * p2 = (X_S *)b;
    if(p1->value == p2->value)
        return p1->data-p2->data;
    else
        return p1->value < p2->value;
}

int structSort()
{
    X_S Xlist[100];
    int i = 0;
    for(i = 0; i < 100; i++)
    {
        Xlist[i].data = i+1;
        Xlist[i].value = rand()%120;
    }

    printf("-------------unsorted-------------\n");
    for(i = 0; i < 100; i++)
    {
        printf("num : %3d, value : %4d\n", Xlist[i].data, Xlist[i].value);
    }

    qsort(Xlist, 100, sizeof(X_S), cmpfunVA);

    printf("-------------sorted-------------\n");
    for(i = 0; i < 100; i++)
    {
        printf("num : %3d, value : %4d\n", Xlist[i].data, Xlist[i].value);
    }

    return 0;
}


int main()
{
    //integer sort
    integerSort();
    putchar('\n');

    //double sort
    doubleSort();
    putchar('\n');

    //string sort
    stringSort();
    putchar('\n');

    //struct sort
    structSort();
    return 0;
}
