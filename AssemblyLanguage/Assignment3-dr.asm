# Author: David Ridgely
# Assignment: 3
#########################

.data
.align 2

	MMax:		.word 0		#this will get (min + max)/2
	MMin:		.word 0		#this will get (max - min)/2
	Min:		.word 0
	Max:		.word 0
	newLine:	.asciiz	"\n"
	maxMsg:		.asciiz	"The Max value is: "
	minMsg:		.asciiz	"The Min value is: "
	minMaxMsg:	.asciiz	"(min + max)/2 = "
	maxMinMsg:	.asciiz	"(max - min)/2 = "
	prompt:		.asciiz	"Enter a number: "
	goodbye:	.asciiz	"Goodbye!"

.text
.globl main

main:

	li		$v0, 9		# allocate memory to the heap
	li		$a0, 40		# allocate 40 bytes
	syscall
	move		$s0, $v0	# store the address in $s0

	li		$s1, 10
	li		$t0, 0

	inputLoop:
		bge		$t0, 40, next
		
		li		$v0, 4
		la		$a0, newLine
		syscall

		li		$v0, 4
		la		$a0, prompt
		syscall

		li		$v0, 5
		syscall
		move		$t1, $v0		# store input into $t1

		addu		$t2, $s0, $t0
		sw		$t1, ($t2)

		addi		$t0, $t0, 4

		j		inputLoop

	next:
		li		$v0, 4
		la		$a0, newLine
		syscall

		addi		$sp, $sp, -8
		sw		$s0, 0($sp)
		sw		$s1, 4($sp)

		jal		MinMax

		lw		$t4, 0($sp)
		lw		$t5, 4($sp)
		addi		$sp, $sp, 8
		sw		$t4, Min
		sw		$t5, Max

		add		$t6, $t4, $t5
		srl		$t7, $t6, 1
		sw		$t7, MMin

		sub		$t8, $t5, $t4
		srl		$t9, $t8, 1
		sw		$t9, MMax

		li		$v0, 4
		la		$a0, minMsg
		syscall

		li		$v0, 1
		lw		$a0, Min
		syscall

		li		$v0, 4
		la		$a0, newLine
		syscall

		li		$v0, 4
		la		$a0, maxMsg
		syscall

		li		$v0, 1
		lw		$a0, Max
		syscall

		li		$v0, 4
		la		$a0, newLine
		syscall

		li		$v0, 4
		la		$a0, minMaxMsg
		syscall

		li		$v0, 1
		lw		$a0, MMin
		syscall

		li		$v0, 4
		la		$a0, newLine
		syscall

		li		$v0, 4
		la		$a0, maxMinMsg
		syscall

		li		$v0, 1
		lw		$a0, MMax
		syscall

	end:
		li		$v0, 4
		la		$a0, newLine
		syscall

		li		$v0, 4
		la		$a0, goodbye
		syscall

		#end of program
		li		$v0, 10
		syscall


MinMax:
	lw	$a0, 0($sp)
	lw	$a1, 4($sp)

	addi	$sp, $sp, 8
	li	$t1, -1
	li	$t2, 999

	for:
		blez	$a1, return
		lw	$t3, 0($a0)
		ble	$t3, $t1, next1	# if $t3 <= $t1 then next1
		move	$t1, $t3
	next1:
		bge	$t3, $t2, next2
		move	$t2, $t3
	next2:
		addi	$a1, $a1, -1
		addi	$a0, $a0, 4
		j	for				# jump to for
	
	return:
		addi	$sp, $sp, -8
		sw	$t2, 0($sp)
		sw	$t1, 4($sp)
		jr	$ra					# jump to $ra

