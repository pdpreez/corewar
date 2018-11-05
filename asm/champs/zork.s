.name "zork"
.comment "lololol"
sti r1,%:live,%2 
and r1, %0, r1

live:	live %2
		zjmp %:live
live0:
live_1: live %:live_2
live_2:	live %2
