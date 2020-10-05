
.text

.global _start              	# make _start label visible to linker

.data	                        # data section
	
	sw:	.quad  600 # window area width
	sh:	.quad  600 # window area height
	x_coordinate : .quad 0
	y_coordinate : .quad 0

	temp: .quad 0
	

_start:				# main label
	
	mov	sw, %rdi	# arg 1: width
	mov	sh, %rsi	# arg 2: height
	call 	g_init  # call graphics init routine

draw:

    mov  $1 , %rdi # delay a little bit before drawing next square
    call  SDL_Delay

	call clear_screen

	mov	x_coordinate, %rdi	# arg 1: x coordinate
	mov	y_coordinate, %rsi	# arg 2: y coordinate
	call 	g_draw_boxes

	mov x_coordinate , %eax
	mov y_coordinate , %edx

	sub $25 , %edx

	mov %eax , temp
	mov temp , %rdi

	mov %edx , temp
	mov temp , %rsi
	call 	g_draw_boxes

	call update_screen


	mov x_coordinate , %eax
	mov y_coordinate , %edx

	cmp sh , %edx
	jl  increment
	jg  reload

increment:

	inc %edx

	mov %eax , x_coordinate
	mov %edx , y_coordinate
	
	jmp draw

reload:

	# put the the square back to inititial position

	add $20 , %eax # move to the right
	mov $0  , %edx 

	mov %eax , x_coordinate
	mov %edx , y_coordinate

	cmp sw , %eax # make the animation twice
	je exit 
	jmp draw

exit:				
	call 	SDL_Quit
	mov    	$0,%rbx         # first argument: exit code
	mov    	$1,%rax         # system call number (sys_exit)
	int     $0x80           # call kernel

