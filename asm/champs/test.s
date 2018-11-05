.name "livepls"
.comment "p l s"

# testing correct sti {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}
sti r1, 5, %3    	 	 	 		 
sti r2, %5, %3
sti r2, r3, r4

#incorrect sti                                                  STI
			##sti %3, r4, r5
			##sti 3, r4, r5
			##sti %3, r4, r5
			##sti r2, 5, 3
			##sti r2, %5, 3
			##sti 3, 4, 5
			##sti        3, 4, 5

# testing correct st {T_REG, T_IND | T_REG}
st r1, 3
st r2, r4      
st r1, 8

#incorrect st                                                   ST
			##st %1, r3
			##st r2, 4
			##st 2, %4
			##st 2, 4

# testing correct and {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}
and 1, r1, r1
and 1, %0, r1
and %1, %0, r1
and r1, r2, r1
and r1, %0, r1
and 3, 0, r1

#incorrect and                                                  AND
			##and r1, %0, 1
			##and r1, %0, %1
			##and r1, r4, 1
			##and r0, r4, 1

# testing correct live {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}
live %0
live %34
#incorrect live													LIVE
			##live r0
			##live r1
			##live 34

# testing correct or {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}
or 1, r4, r1
or 1, %0, r1
or %1, %0, r1
or r1, r2, r1
or r1, %0, r1
or 3, 0, r1

#incorrect or                                                   OR
			##or r1, %0, 1
			##or r1, %0, %1
			##or r1, r4, 1

# testing correct xor {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}
xor 1, r9, r1
xor 1, %0, r1
xor %1, %0, r1
xor r1, r2, r1
xor r1, %0, r1
xor 3, 0, r1

#incorrect xor                                                  XOR
			##xor r1, %0, 1
			##xor r1, %0, %1
			##xor r1, r4, 1
			##xor r0, r4, 1
			##xor r17, r4, r1

# testing correct sub {T_REG, T_REG, T_REG}
sub r1, r2, r3

#incorrect sub                                                  SUB
			##sub 1, 2, 3
			##sub r1, %2, r4
			##sub %4, r1, r2,
			##sub %1, %2, %3,

# testing correct add {T_REG, T_REG, T_REG}
add r1, r2, r3

incorrect_add:                                                  #ADD
			##add 1, 2, 3
			##add r1, %2, r4
			##add %4, r1, r2,
			##add %1, %2, %3,


# testing correct zjmp {T_DIR}

zjmp %878778
zjmp %0

#incorrect zjmp                                                 ZJMP
			##zjmp 5435
			##zjmp r1
			##zjmp r0

# testing correct aff {T_REG}
aff r2

#incorrect aff   												AFF
			##aff 5435
			##aff %1
			##aff 0

## testing correct fork {T_DIR}
fork %8

#incorrect fork                                                 FORK
			##fork 5435
			##fork r1
			##fork r0

## testing correct lfork {T_DIR}
lfork %8

#incorrect lfork                        						LFORK
			##lfork 5435
			##lfork r1
			##lfork r0

## testing correct ld {T_DIR | T_IND, T_REG}
ld %8, r1
ld 8, r2

#incorrect ld   												LD
			##ld 5, 1
			##ld r2, r1
			##ld r7, %1
			##ld r7, r1

## testing correct ldi {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}
ldi r1, r2, r3
ldi %1, %2, r3
ldi 1, r2, r3

#incorrect ldi   												LDI
			##ldi r1, r2, 3
			##ldi r1, r2, %3
			##ldi r1, 2, r3
			##ldi r0, r2, r3
label:
## testing correct lld {T_DIR | T_IND, T_REG}
lld %8, r1
lld 8, r2

#incorrect lld   												LLD
			##lld 5, 1
			##lld r2, r1
			##lld r7, %1
			##lld r7, r1

## testing correct lldi {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}
lldi r1, r2, r3
lldi %1, %2, r3
lldi -1, r2, r3
lldi %:label, %3, r5

#incorrect lldi   												LLDI
			##lldi r1, r2, 3
			##lldi r1, r2, %3
			##lldi r1, 2, r3
			##lldi r0, r2, r3
