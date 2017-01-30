main:

	addi $t1 , $t1 , 1
	addi $t3 , $t3 , 1
	addi $t4 , $t4 , 26
START:	beq $t3 , $t4 , END 
	addi $t3 , $t3 , 1
	add $t2 , $t1 , $t0
	add $t0 , $zero , $t1
	add $t1 , $zero , $t2
	j START


END:	jr $ra