#include <stdio.h>

struct person
{
	char *name;
	int age;
	char score;
	int id;
};
//__attribute__((packed));

int push_test(const char *format, ...)
{
	
	struct person per;

	char *p = (char *)&format;
	printf("arg1: %s\n", format);

	p = p + sizeof(char *);
	printf("arg2: %d\n", *((int *)p));

	p = p + sizeof(int);
	per = *((struct person *)p);
	printf("arg3: person->name: %s, person->age: %d, person->score: %c, person->id: %d\n", per.name, per.age, per.score, per.id);

	/*
	printf("&per->name:  %p\n", &per.name);
	printf("&per->age:   %p\n", &per.age);
	printf("&per->score: %p\n", &per.score);
	printf("&per->id:    %p\n", &per.id);
	*/

	return 0;
}

int main()
{
	char *p = "Hello Zhu!";
	int num = 456;

	struct person per = {"Zhangsan", 18, 'A', 123};
	printf("sizeof(per): %d\n", sizeof(struct person));

	push_test(p, num, per);

	return 0;
}
