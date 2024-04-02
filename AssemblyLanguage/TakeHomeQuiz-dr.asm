# Author: David Ridgely
# Assignment: Take Home Quiz
# 6/27/2022
#############################

.data
.align 2

# a. Write a main program that constructs a static array arr[10] and initiates the values
# of the array to:  arr[] ={-1, -2, 3, 4, -5, -6, 7, -8, -9, 0}.
arr:        .word    -1, -2, 3, 4, -5, -6, 7, -8, -9, 0
min:        .word    0
max:        .word    0
absValue:   .word    0
newLine:    .asciiz  "\n"
goodbye:    .asciiz  "Goodbye!"
minMsg:     .asciiz  "The Min is: "
maxMsg:     .asciiz  "The Max is: "
absMsg:     .asciiz  "The Absolute Value of the Difference is: "

.text
.globl main

main:

    # b. Place a pointer to arr[] in $s0, Set $s1 to be 10.
    la		$s0, arr
    li		$s1, 10		# $s1 = 10
    
    addiu   $sp, $sp, -16       # Allocate 16 bytes of memory to the stack
    sw      $s0, 0($sp)         # store $s0
    sw      $s1, 4($sp)         # store $s1
    sw      $ra, 8($sp)         # store the return address
    jal		MinMax				# jump to MinMax and save position to $ra
    
    lw      $t0, 0($sp)         # loads the absolute value
    lw      $t1, 4($sp)         # loads the max value
    lw      $t2, 8($sp)         # loads the min value
    addiu   $sp, $sp, 16        # returns stack to normal position


    li      $v0, 4              # print newLine
    la		$a0, newLine
    syscall

    li      $v0, 4              # print minMsg
    la      $a0, minMsg
    syscall

    li      $v0, 1              # print min Value
    move    $a0, $t2
    syscall

    li      $v0, 4
    la		$a0, newLine
    syscall

    li      $v0, 4              # print maxMsg
    la      $a0, maxMsg
    syscall

    li      $v0, 1              # print max Value
    move    $a0, $t1
    syscall

    li      $v0, 4
    la		$a0, newLine
    syscall

    li      $v0, 4              # print absMsg
    la      $a0, absMsg
    syscall

    li      $v0, 1              # print absolute value
    move    $a0, $t0
    syscall



    jal     end

end:
    li      $v0, 4
    la      $a0, newLine
    syscall

    li      $v0, 4
    la      $a0, newLine
    syscall

    li      $v0, 4
    la      $a0, goodbye
    syscall

    li      $v0, 10
    syscall

MinMax:
    lw		$a0, 0($sp)     # loads $s0 into $a0
    lw      $a1, 4($sp)     # loads $s1 into $a1
    lw      $a2, 8($sp)     # $a2 should be the $ra back to main
    addiu   $sp, $sp, 16    # resets the stack
    move    $s5, $a0        # $s5 should now be $ra

    li      $t1, -1         # max
    li      $t2, 999        # min

    for:
        blez    $a1, callAbs        # when a1 reachs less than 0 jump to callAbs
        lw      $t3, 0($a0)         # loads the value in the array
        ble     $t3, $t1, next1     # if check for, if value in $t3 is less than the max, do nothing and jump to next1
        move    $t1, $t3            # moves the greater value into $t1
    next1:
        bge     $t3, $t2, next2     # check, if value in $3 is greater than the min, do nothing and jump to next2
        move    $t2, $t3            # moves the lesser value into $t2
    next2:
        addi    $a1, $a1, -1        # decrement $a1
        addi    $a0, $a0, 4         # increment $a0
        j		for				# jump to for
    

    callAbs:
        sw      $t1, max            # stores the max in max just in case
        sw      $t2, min            # stores min in min just in case
        sub		$t4, $t2, $t1		# $a0 = $t2 - $t1 (Min - Max)

        
        addiu   $sp, $sp, -16
        sw      $t4, 0($sp)         # stores the (Min - Max) on stack
        sw      $t1, 4($sp)         # storing max on stack to move between functions
        sw      $t2, 8($sp)         # storing min on stack
        sw      $ra, 12($sp)        # storing the return address
        jal     absDiff
        lw      $t0, 0($sp)         
        lw      $t1, 4($sp)
        lw      $t2, 8($sp)
        addiu   $sp, $sp, 16


        addiu   $sp, $sp, -16
        sw      $t0, 0($sp)
        sw      $t1, 4($sp)
        sw      $t2, 8($sp)
        move    $ra, $s5
        jr      $ra         #returns to main

absDiff:
    lw      $a0, 0($sp)
    lw      $s1, 4($sp)
    lw      $s2, 8($sp)
    lw      $a1, 12($sp)
    addiu   $sp, $sp, 16
    move    $s6, $a1        # $s6 is holding $ra back to MinMax
    move    $t0, $a0        # $t0 is holding Min - Max

    li      $t1, -1
    mult	$t0, $t1			# $t0 * $t1 = Hi and Lo registers
    mflo	$t0					# copy Lo to $t2
    sw      $t0, absValue

    addiu   $sp, $sp, -16
    sw      $t0, 0($sp)
    sw      $s1, 4($sp)
    sw      $s2, 8($sp)
    move    $ra, $s6
    jr      $ra         #returns to MinMax
