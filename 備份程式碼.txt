.globl main
.data
	Input: .string "Input a number:\n"
	Output: .string"The damage:\n"
	limit1: .string"The input  number is greater than 99, please try again.\n"
.text	
main:
	la a0, Input
	li a7, 4
	ecall
limit:	
	li a7, 5
	ecall
	add t0, x0, x0
	add t4, x0, a0
	addi t1, x0, 100
	blt t4, t1, start
limit2: 
	la a0, limit1
	li a7, 4
	ecall
	bge x0,x0, limit
start:
	addi t1, x0, 20
	addi t2, x0, 10
	addi t3, x0, 1
	jal x1, function
	beq x0,x0 exit
	
function:	
	addi sp,sp, -8
	sw ra, 0(sp)
	sw t4, 4(sp)
	blt t1, t4, block1
	blt t2, t4, block2
	blt t3, t4, block3
	beq x0, t4, block4
	beq t3, t4, block5
	blt t4,x0, block6
	
block1:	
	slli t5, t4, 1
	add t0, t5, t0
	addi t6, t6, 5
	div t4, t4, t6
	jal x1, function
	beq x0,x0 functionExit

block2:	
	addi t4, t4, -2
	jal x1, function
	lw t4, 4(sp)
	addi t4, t4, -3
	jal x1, function
	beq x0,x0 functionExit
	
block3:	
	addi t4, t4, -1
	jal x1, function
	lw t4, 4(sp)
	addi t4, t4, -2
	jal x1, function
	beq x0,x0 functionExit	
	
block4:	
	addi t0,t0,1
	beq x0,x0 functionExit

block5:
	addi t0,t0,5
	beq x0,x0 functionExit

block6:
	addi t0,t0,-1
	beq x0,x0 functionExit

functionExit:
	lw ra, 0(sp)
	lw t4, 4(sp)
	addi sp, sp, 8
	jalr ra

exit:
	la a0, Output
	li a7, 4 
	ecall
	add a0, x0, t0
	li a7, 1
	ecall
	li a7, 10
	ecall