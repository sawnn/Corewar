.name "roller"
.comment "oui"
	
start:
	sti r1, %:live, %1

live:
	live %0

preend:
	xor %1, %1, r16
	zjmp %:start

lol:	
