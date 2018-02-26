.name "On m'apelle 42"
.comment "Je suis assez fort comme championc c'est vrai"

fdp:	sti r2, 43, %434
	live %42


toot:
	sti r15, 23, %:fdp
	fork %:fdp
	zjmp %:toot
	add r1, r2, r4
