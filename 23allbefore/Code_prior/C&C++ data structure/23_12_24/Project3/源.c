#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>


struct stu {
    char* name;
    int num;
    int age;
    char group;
    float score;
}stus[] = {
        {"Zhou ping", 5, 18, 'C', 145.0},
        {"Zhang ping", 4, 19, 'A', 130.5},
        {"Liu fang", 1, 18, 'A', 148.5},
        {"Cheng ling", 2, 17, 'F', 139.0},
        {"Wang ming", 3, 17, 'B', 144.5}
}, * ps;
int main()
{
    int len = sizeof(stus) / sizeof(struct stu);
    printf("Name\t\tNum\tAge\tGroup\tScore\t\n");
    for (ps = stus; ps < ps + len; ps++)
    {
        printf("%s\t%d\t%d\t%c\t%.1f\n", ps->name, ps->num, ps->age, ps->group, ps->score);
    }
}