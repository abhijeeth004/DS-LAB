#include<stdio.h>
#include<stdlib.h>

struct time
{
    int hour;
    int min;
    int sec;
};

void read(struct time t[]);
void display(struct time t[],struct time add,struct time diff);
struct time addition(struct time t[]);
struct time difference(struct time t[]);


int main()
{
    struct time t[2],add,diff;
    read(t);
    add=addition(t);
    diff=difference(t);
    display(t,add,diff);
}

void read(struct time t[])
{
    printf("Enter the hours; minutes; and seconds for first time in the respective order:\n ");
    scanf("%d",&t[0].hour);
    scanf("%d",&t[0].min);
    scanf("%d",&t[0].sec);
    printf("Enter the hours; minutes; and seconds for second time in the respective order:\n ");
    scanf("%d",&t[1].hour);
    scanf("%d",&t[1].min);
    scanf("%d",&t[1].sec);
}

void display(struct time t[],struct time add,struct time diff)
{
    printf("The hours; minutes; and seconds for first time in the order:\n ");
    printf("%d:%d:%d\n",t[0].hour,t[0].min,t[0].sec);
    printf("The hours minutes and seconds for second time in the order:\n ");
    printf("%d:%d:%d\n",t[1].hour,t[1].min,t[1].sec);
    printf("The hours minutes and seconds for added time:\n ");
    printf("%d:%d:%d\n",add.hour,add.min,add.sec);
    printf("The hours minutes and seconds for subtracted time:\n ");
    printf("%d:%d:%d\n",diff.hour,diff.min,diff.sec);

}

struct time addition(struct time t[])
{
    struct time add;
    add.hour=t[0].hour+t[1].hour;
    if(add.hour>=24)
        add.hour=add.hour-24;
    add.min=t[0].min+t[1].min;
    if(add.min>=60)
        add.min=add.min-60;
    add.sec=t[0].sec+t[1].sec;
    if(add.sec>=60)
        add.sec=add.sec-60;
        return add;

}

struct time difference(struct time t[])
{
    struct time diff;
    diff.hour=t[0].hour-t[1].hour;
    if(diff.hour<0)
    {
        diff.hour=-diff.hour;
        diff.hour=24-diff.hour;
    }

    diff.min=t[0].min-t[1].min;
    if(diff.min<0)
    {
        diff.min=-diff.min;
        diff.hour-=1;
        diff.min=60-diff.min;
    }
    diff.sec=t[0].sec-t[1].sec;
    if(diff.sec<0)
    {
        diff.sec=-diff.sec;
        diff.min-=1;
        diff.sec=60-diff.sec;
    }
    return diff;

}
