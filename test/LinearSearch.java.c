// This is automatically generated by the Tiger compiler.
// Do NOT modify!

// Control-flow Graph

// structures
struct LinearSearch
{
	struct LinearSearch_vtable *vptr;
	int isObjOrArray;
	unsigned length;
	void * forwarding;
};
struct LS
{
	struct LS_vtable *vptr;
	int isObjOrArray;
	unsigned length;
	void * forwarding;
	int * number;
	int size;
};
// vtables structures
struct LinearSearch_vtable
{
	char * LinearSearch_gc_map;
};

struct LS_vtable
{
	char * LS_gc_map;
	int (*LS_Start)();
	int (*LS_Print)();
	int (*LS_Search)();
	int (*LS_Init)();
};


// vtables defines
struct LinearSearch_vtable LinearSearch_vtable_ ;
struct LS_vtable LS_vtable_ ;

// methods
void * frame_prev;

struct LS_Start_gc_frame{
	void * frame_prev;
	int * arguments_base_address;
	char * arguments_gc_map;
	char * locals_gc_map;
	struct LS * x_1;
	struct LS * x_2;
	struct LS * x_3;
	struct LS * x_4;
	struct LS * x_5;
	struct LS * x_6;
};

int LS_Start(struct LS * this, int sz)
{
	int aux01;
	int aux02;
	int x_7;
	int x_8;
	int x_9;
	int x_10;
	int x_11;
	int x_12;

	char * LS_Start_arguments_gc_map = "10";
	char * LS_Start_locals_gc_map = "111111";
	//put the GC stack frame onto the call stack.
	struct LS_Start_gc_frame frame;
	//push this frame onto the GC stack by setting up "prev".
	frame.frame_prev = frame_prev;
	frame_prev = &frame;
	//setting up memory GC maps and corresponding base addresses
	frame.arguments_gc_map = LS_Start_arguments_gc_map;
	frame.arguments_base_address = (int *)&this;
	frame.locals_gc_map = LS_Start_locals_gc_map;

L_0:


	x_7 = this->vptr->LS_Init(this, sz);
	x_8 = this->vptr->LS_Print(this);
	System_out_println (9999);

	x_9 = this->vptr->LS_Search(this, 8);
	System_out_println (x_9);

	x_10 = this->vptr->LS_Search(this, 12);
	System_out_println (x_10);

	x_11 = this->vptr->LS_Search(this, 17);
	System_out_println (x_11);

	x_12 = this->vptr->LS_Search(this, 50);
	System_out_println (x_12);

	frame_prev = frame.frame_prev;
	return 55;
}

struct LS_Print_gc_frame{
	void * frame_prev;
	int * arguments_base_address;
	char * arguments_gc_map;
	char * locals_gc_map;
};

int LS_Print(struct LS * this)
{
	int j;
	int x_13;
	int x_14;

	char * LS_Print_arguments_gc_map = "1";
	char * LS_Print_locals_gc_map = "";
	//put the GC stack frame onto the call stack.
	struct LS_Print_gc_frame frame;
	//push this frame onto the GC stack by setting up "prev".
	frame.frame_prev = frame_prev;
	frame_prev = &frame;
	//setting up memory GC maps and corresponding base addresses
	frame.arguments_gc_map = LS_Print_arguments_gc_map;
	frame.arguments_base_address = (int *)&this;
	frame.locals_gc_map = LS_Print_locals_gc_map;

L_1:
	j = 1;
	goto L_4;
L_4:
	x_13 = j < this->size;
	if (x_13)
	  goto L_2;
	else
	  goto L_3;
L_2:
	System_out_println ((this->number + 4)[j]);

	x_14 = j + 1;
	j = x_14;
	goto L_4;
L_3:
	frame_prev = frame.frame_prev;
	return 0;
}

struct LS_Search_gc_frame{
	void * frame_prev;
	int * arguments_base_address;
	char * arguments_gc_map;
	char * locals_gc_map;
};

int LS_Search(struct LS * this, int num)
{
	int j;
	int ls01;
	int ifound;
	int aux01;
	int aux02;
	int nt;
	int x_15;
	int x_16;
	int x_17;
	int x_18;
	int x_19;

	char * LS_Search_arguments_gc_map = "10";
	char * LS_Search_locals_gc_map = "";
	//put the GC stack frame onto the call stack.
	struct LS_Search_gc_frame frame;
	//push this frame onto the GC stack by setting up "prev".
	frame.frame_prev = frame_prev;
	frame_prev = &frame;
	//setting up memory GC maps and corresponding base addresses
	frame.arguments_gc_map = LS_Search_arguments_gc_map;
	frame.arguments_base_address = (int *)&this;
	frame.locals_gc_map = LS_Search_locals_gc_map;

L_5:

	j = 1;
	ifound = 0;
	goto L_8;
L_8:
	x_15 = j < this->size;
	if (x_15)
	  goto L_6;
	else
	  goto L_7;
L_6:
	aux01 = (this->number + 4)[j];
	x_16 = num + 1;
	aux02 = x_16;
	x_17 = aux01 < num;
	if (x_17)
	  goto L_9;
	else
	  goto L_10;
L_9:
	goto L_11;
L_10:
	x_18 = aux01 < aux02;
	if (!x_18)
	  goto L_12;
	else
	  goto L_13;
L_12:
	goto L_14;
L_13:
	ifound = 1;
	j = this->size;
	goto L_14;
L_14:
	goto L_11;
L_11:
	x_19 = j + 1;
	j = x_19;
	goto L_8;
L_7:
	frame_prev = frame.frame_prev;
	return ifound;
}

struct LS_Init_gc_frame{
	void * frame_prev;
	int * arguments_base_address;
	char * arguments_gc_map;
	char * locals_gc_map;
	int * x_20;
};

int LS_Init(struct LS * this, int sz)
{
	int j;
	int k;
	int aux01;
	int aux02;
	int * x_20;
	int x_21;
	int x_22;
	int x_23;
	int x_24;
	int x_25;
	int x_26;
	int x_27;

	char * LS_Init_arguments_gc_map = "10";
	char * LS_Init_locals_gc_map = "1";
	//put the GC stack frame onto the call stack.
	struct LS_Init_gc_frame frame;
	//push this frame onto the GC stack by setting up "prev".
	frame.frame_prev = frame_prev;
	frame_prev = &frame;
	//setting up memory GC maps and corresponding base addresses
	frame.arguments_gc_map = LS_Init_arguments_gc_map;
	frame.arguments_base_address = (int *)&this;
	frame.locals_gc_map = LS_Init_locals_gc_map;

L_15:

	this->size = sz;
	x_20 = (int *)Tiger_new_array(sizeof(int) * sz);
	this->number = x_20;
	j = 1;
	x_21 = this->size + 1;
	k = x_21;
	goto L_18;
L_18:
	x_22 = j < this->size;
	if (x_22)
	  goto L_16;
	else
	  goto L_17;
L_16:
	x_23 = j + j;
	aux01 = x_23;
	x_24 = k - 3;
	aux02 = x_24;
	x_25 = aux01 + aux02;
	(this->number + 4)[j] = x_25;
	x_26 = j + 1;
	j = x_26;
	x_27 = k - 1;
	k = x_27;
	goto L_18;
L_17:
	frame_prev = frame.frame_prev;
	return 0;
}

// vtables
struct LinearSearch_vtable LinearSearch_vtable_ = 
{
	"",
};

struct LS_vtable LS_vtable_ = 
{
	"10",
	LS_Start,
	LS_Print,
	LS_Search,
	LS_Init,
};


// main method

struct Tiger_main_gc_frame{
	void * frame_prev;
	int * arguments_base_address;
	char * arguments_gc_map;
	char * locals_gc_map;
	struct LS * x_0;
	struct LS * x_29;
};

int Tiger_main ()
{
	int x_28;
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

L_19:
	frame.x_29 = ((struct LS*)(Tiger_new (&LS_vtable_, sizeof(struct LS))));
	x_28 = frame.x_29->vptr->LS_Start(frame.x_29, 10);
	System_out_println (x_28);

	frame_prev = frame.frame_prev;
	return 0;
}




