#include <stdio.h>
#include <malloc.h>
#include <string.h>

extern struct st_Vector* new_Vector(int x, int y);

struct st_Vector
{
    int x;
    int y;
    struct cls_Vector* __class__;
};

typedef struct st_Vector* Vector;

struct st_Vector* __add__(struct st_Vector* self, struct st_Vector* other)
{
    return new_Vector(self->x + other->x, self->y + other->y);
}

struct st_Vector* __sub__(struct st_Vector* self, struct st_Vector* other)
{
    return new_Vector(self->x - other->x, self->y - other->y);
}

#define BUF_SIZE 1024
char __buffer[BUF_SIZE];

char* __str__(struct st_Vector* self)
{
    sprintf(__buffer, "Vector(x=%d, y=%d)", self->x, self->y);
    return __buffer;
}

void __del__(Vector self)
{
    free(self);
}

struct cls_Vector
{
    struct st_Vector* (*__add__)(struct st_Vector*, struct st_Vector*);
    struct st_Vector* (*__sub__)(struct st_Vector*, struct st_Vector*);
    char* (*__str__)(struct st_Vector*);
    void (*__del__)(struct st_Vector*);
} __global_class_def_Vector__ = {
    .__add__ = __add__,
    .__sub__ = __sub__,
    .__str__ = __str__,
    .__del__ = __del__,
    };

Vector new_Vector(int x, int y)
{
    Vector n = (Vector)malloc(sizeof(struct st_Vector));
    n->x = x;
    n->y = y;
    n->__class__ = &__global_class_def_Vector__;
    return n;
}


#define add(obj, other)     obj->__class__->__add__(obj, other)
#define sub(obj, other)     obj->__class__->__sub__(obj, other)
#define str(obj)            obj->__class__->__str__(obj)
#define del(obj)            obj->__class__->__del__(obj)

int main(int argc, char const* argv[])
{
    Vector a = new_Vector(1, 2);
    Vector b = new_Vector(3, 4);
    Vector c, d;

    printf("a: %s\n", str(a));
    printf("b: %s\n", str(b));
    c = add(a, b);
    d = sub(a, b);
    printf("c: %s\n", str(c));
    printf("d: %s\n", str(d));

    del(a);
    del(b);
    del(c);
    del(d);
    return 0;
}
