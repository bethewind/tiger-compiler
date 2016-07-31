// This is automatically generated by the Tiger compiler.
// Do NOT modify!

// Control-flow Graph

// structures
struct Factorial
{
	struct Factorial_vtable *vptr;
};
struct Fac
{
	struct Fac_vtable *vptr;
};
// vtables structures
struct Factorial_vtable
{
};

struct Fac_vtable
{
	int (*Fac_ComputeFac)();
};


// vtables defines
struct Factorial_vtable Factorial_vtable_ ;
struct Fac_vtable Fac_vtable_ ;

// methods
int Fac_ComputeFac(struct Fac * this, int num)
{
	int num_aux;
	struct Fac * x_1;
	int x_2;
	int x_3;
	int x_4;
	int x_5;

L_0:
	x_2 = num < 1;
	if (x_2)
	  goto L_1;
	else
	  goto L_2;
L_1:
	num_aux = 1;
	goto L_3;
L_2:
	x_5 = num - 1;
	x_4 = this->vptr->Fac_ComputeFac(this, x_5);
	x_3 = num * x_4;
	num_aux = x_3;
	goto L_3;
L_3:
	return num_aux;
}

// vtables
struct Factorial_vtable Factorial_vtable_ = 
{
};

struct Fac_vtable Fac_vtable_ = 
{
	Fac_ComputeFac,
};


// main method
int Tiger_main ()
{
	struct Fac * x_0;
	int x_6;
	struct Fac * x_7;

L_4:
	x_7 = ((struct Fac*)(Tiger_new (&Fac_vtable_, sizeof(struct Fac))));
	x_6 = x_7->vptr->Fac_ComputeFac(x_7, 10);
	System_out_println (x_6);

	return 0;
}




