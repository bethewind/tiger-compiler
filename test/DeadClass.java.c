// This is automatically generated by the Tiger compiler.
// Do NOT modify!

// Control-flow Graph

// structures
struct DeadClass
{
	struct DeadClass_vtable *vptr;
	int isObjOrArray;
	unsigned length;
	void * forwarding;
};
// vtables structures
struct DeadClass_vtable
{
	char * DeadClass_gc_map;
};


// vtables defines
struct DeadClass_vtable DeadClass_vtable_ ;

// methods
void * frame_prev;

// vtables
struct DeadClass_vtable DeadClass_vtable_ = 
{
	"",
};


// main method

struct Tiger_main_gc_frame{
	void * frame_prev;
	int * arguments_base_address;
	char * arguments_gc_map;
	char * locals_gc_map;
};

int Tiger_main ()
{
	char * tiger_main_arguments_gc_map = "";
	char * tiger_main_locals_gc_map = "";
	//put the GC stack frame onto the call stack.
	struct Tiger_main_gc_frame frame;
	//push this frame onto the GC stack by setting up "prev".
	frame.frame_prev = frame_prev;
	frame_prev = &frame;
	//setting up memory GC maps and corresponding base addresses
	frame.arguments_gc_map = tiger_main_arguments_gc_map;
	frame.locals_gc_map = tiger_main_locals_gc_map;

L_0:
	System_out_println (10);

	frame_prev = frame.frame_prev;
	return 0;
}




