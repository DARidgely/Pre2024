# Author: David Ridgely
# Assignment: 2
#
##########################

.data

X:		.word 44, 1, 4, 3, 2, 5, 6, 7, 8, 14
MinMax:	.word 0		#this will get (min + max)/2
MaxMin:	.word 0		#this will get (min - max)/2
Min:	.word 0
Max:	.word 0
output:	.asciiz	"\nThe number is: "
maxMsg:	.asciiz	"\nThe Max value is: "
minMsg:	.asciiz	"\nThe Min value is: "

.extern foobar 4

.globl main
.text

main:

###################################################################
# just checking to make sure array is initialized correctly
# loop:
# 		li		$v0, 4		#outputs "output msg"
# 		la		$a0, output
# 		syscall

# 		li		$v0, 1		#outputs a number to console
# 		lw		$t2, X($t0)		#$t2 contains the contents of X[i]
# 		add		$a0, $0, $t2	# $a0 contains the value of $t2
# 		syscall		#prints the value at X[i]
####################################################################

		li		$t0, 0				# array index; sets $t0 to 0
		lw		$s0, X($t0)			# $s0 will contain the max variable
		move 	$s2, $s0			# $s2 will contain the min variable
		li		$t1, 1				# loop counter
	
loop:	
		beq		$t1, 10, endloop	# checks if at end of loop; if $t1 = 10 branch to endloop
		addi	$t0, $t0, 4			# increments the index
		lw		$s1, X($t0)
		bge		$s0, $s1, nochg		# if $s0 >= $s1 then nochg
		move	$s0, $s1			# $s0 = $s1

nochg:	
		ble		$s2, $s1, nexti		# if $s2 <= $s1 then nexti
		move	$s2, $s1			# $s2 = $s1

nexti:	
		addi	$t1, $t1, 1			# increment loop counter
		j		loop				# jump to loop

endloop:
		li		$v0, 4				# this will print the max message
		la		$a0, maxMsg
		syscall

		li		$v0, 1				# this will print the max value
		add		$a0, $s0, $zero
		syscall
		sw		$s0, Max			# stores the max value in max variable

		li		$v0, 4				# this is for the min message
		la		$a0, minMsg
		syscall

		li		$v0, 1				# this will print the min value
		add		$a0, $s2, $zero
		syscall
		sw		$s2, Min			# stores the min value in min variable

		lw		$t1, Min			# stores the min in $t1
		lw		$t2, Max			# stores the max in $t2
		add		$t0, $t1, $t2		# adds $t1+$t2 (Min + Max)
		div		$s0, $t0, 2			# divides $t0 by 2; (Min+Max)/2
		sw		$s0, MinMax			# stores $s0 in MinMax variable
		
		li		$v0, 4
		la		$a0, output
		syscall

		li		$v0, 1
		lw		$s0, MinMax
		add		$a0, $s0, $zero
		syscall
		
		sub		$t0, $t1, $t2		# $t0 = $t1 - $t2
		div		$s0, $t0, 2
		sw		$s0, MaxMin

		li		$v0, 4
		la		$a0, output
		syscall

		li		$v0, 1
		lw		$s0, MaxMin
		add		$a0, $s0, $zero
		syscall
	
end:	
		ori $v0, $0, 10
		syscall


		lw $t1, foobar

		jr $ra
