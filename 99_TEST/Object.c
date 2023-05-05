#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct Obj* this;

#define $(obj) ((this = obj), obj)

struct Obj;

struct Obj* _Increase();

struct Funs
{
	struct Obj* (*Increase)();
} _global_func_table = {
	.Increase = _Increase,
};

struct Obj
{
	int x;
	int y;
	struct Funs* funcs;
} Object;

struct Obj* new_obj(int a, int b)
{
	struct Obj* obj = malloc(sizeof(struct Obj));
	obj->x = a;
	obj->y = b;
	obj->funcs = &_global_func_table;
	return obj;
}

int main(int argc, char const* argv[])
{
	/* code */
	struct Obj* obj = new_obj(1, 1);
	// obj->funcs->Increase();
	$(obj)->funcs->Increase();
	// printf("%d",obj->x);
	// printf("%d",({obj;})->x);
	return 0;
}

struct Obj* _Increase()
{
	this->x++;
	this->y++;

	return this;
}
