// This is automatically generated by the Tiger compiler.
// Do NOT modify!

// Control-flow Graph

// structures
struct Sum
{
	struct Sum_vtable *vptr;
	int isObjOrArray;
	unsigned length;
	void * forwarding;
};
struct Doit
{
	struct Doit_vtable *vptr;
	int isObjOrArray;
	unsigned length;
	void * forwarding;
};
// vtables structures
struct Sum_vtable
{
	char * Sum_gc_map;
};

struct Doit_vtable
{
	char * Doit_gc_map;
	int (*Doit_doit)();
};


// vtables defines
struct Sum_vtable Sum_vtable_ ;
struct Doit_vtable Doit_vtable_ ;

// methods
void * frame_prev;

struct Doit_doit_gc_frame{
	void * frame_prev;
	int * arguments_base_address;
	char * arguments_gc_map;
	char * locals_gc_map;
};

int Doit_doit(struct Doit * this, int n)
{
	int sum;
	int i;
	int x_1;
	int x_2;
	int x_3;

	char * Doit_doit_arguments_gc_map = "10";
	char * Doit_doit_locals_gc_map = "";
	//put the GC stack frame onto the call stack.
	struct Doit_doit_gc_frame frame;
	//push this frame onto the GC stack by setting up "prev".
	frame.frame_prev = frame_prev;
	frame_prev = &frame;
	//setting up memory GC maps and corresponding base addresses
	frame.arguments_gc_map = Doit_doit_arguments_gc_map;
	frame.arguments_base_address = (int *)&this;
	frame.locals_gc_map = Doit_doit_locals_gc_map;

L_0:

	i = 0;
	sum = 0;
	goto L_3;
L_3:
	x_1 = i < n;
	if (x_1)
	  goto L_1;
	else
	  goto L_2;
L_1:
	x_2 = sum + i;
	sum = x_2;
	x_3 = i + 1;
	i = x_3;
	goto L_3;
L_2:
	frame_prev = frame.frame_prev;
	return sum;
}

// vtables
struct Sum_vtable Sum_vtable_ = 
{
	"",
};

struct Doit_vtable Doit_vtable_ = 
{
	"",
	Doit_doit,
};


// main method

struct Tiger_main_gc_frame{
	void * frame_prev;
	int * arguments_base_address;
	char * arguments_gc_map;
	char * locals_gc_map;
	struct Doit * x_0;
	struct Doit * x_5;
};

int Tiger_main ()
{
	int x_4;
	char * tiger_main_arguments_gc_map = "";
	char * tiger_main_locals_gc_map = "11";
	//put the GC stack frame onto the call stack.
	struct Tiger_main_gc_frame frame;
	//push this frame onto the GC stack by setting up "prev".
	frame.frame_prev = frame_prev;
	frame_prev = &frame;
	//setting up memory GC maps and corresponding base addresses
	frame.arguments_gc_map = tiger_main_arguments_gc_map;
	frame.locals_gc_map = tiger_main_locals_gc_map;

L_4:
	frame.x_5 = ((struct Doit*)(Tiger_new (&Doit_vtable_, sizeof(struct Doit))));
	x_4 = frame.x_5->vptr->Doit_doit(frame.x_5, 101);
	System_out_println (x_4);

	frame_prev = frame.frame_prev;
	return 0;
}




