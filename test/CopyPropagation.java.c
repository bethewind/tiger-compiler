// This is automatically generated by the Tiger compiler.
// Do NOT modify!

// Control-flow Graph

// structures
struct ConstFold
{
	struct ConstFold_vtable *vptr;
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
struct ConstFold_vtable
{
	char * ConstFold_gc_map;
};

struct Doit_vtable
{
	char * Doit_gc_map;
	int (*Doit_doit)();
	int (*Doit_get)();
};


// vtables defines
struct ConstFold_vtable ConstFold_vtable_ ;
struct Doit_vtable Doit_vtable_ ;

// methods
void * frame_prev;

struct Doit_doit_gc_frame{
	void * frame_prev;
	int * arguments_base_address;
	char * arguments_gc_map;
	char * locals_gc_map;
	struct Doit * x;
	struct Doit * y;
	struct Doit * z;
	struct Doit * x_1;
	struct Doit * x_2;
};

int Doit_doit(struct Doit * this)
{
	int x_3;

	char * Doit_doit_arguments_gc_map = "1";
	char * Doit_doit_locals_gc_map = "11111";
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
	frame.x_2 = ((struct Doit*)(Tiger_new (&Doit_vtable_, sizeof(struct Doit))));
	frame.y = frame.x_2;
	x_3 = frame.y->vptr->Doit_get(frame.y);
	frame_prev = frame.frame_prev;
	return x_3;
}

struct Doit_get_gc_frame{
	void * frame_prev;
	int * arguments_base_address;
	char * arguments_gc_map;
	char * locals_gc_map;
};

int Doit_get(struct Doit * this)
{

	char * Doit_get_arguments_gc_map = "1";
	char * Doit_get_locals_gc_map = "";
	//put the GC stack frame onto the call stack.
	struct Doit_get_gc_frame frame;
	//push this frame onto the GC stack by setting up "prev".
	frame.frame_prev = frame_prev;
	frame_prev = &frame;
	//setting up memory GC maps and corresponding base addresses
	frame.arguments_gc_map = Doit_get_arguments_gc_map;
	frame.arguments_base_address = (int *)&this;
	frame.locals_gc_map = Doit_get_locals_gc_map;

L_1:
	frame_prev = frame.frame_prev;
	return 1;
}

// vtables
struct ConstFold_vtable ConstFold_vtable_ = 
{
	"",
};

struct Doit_vtable Doit_vtable_ = 
{
	"",
	Doit_doit,
	Doit_get,
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

L_2:
	frame.x_5 = ((struct Doit*)(Tiger_new (&Doit_vtable_, sizeof(struct Doit))));
	x_4 = frame.x_5->vptr->Doit_doit(frame.x_5);
	System_out_println (x_4);

	frame_prev = frame.frame_prev;
	return 0;
}



