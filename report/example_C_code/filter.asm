# I assume a pointer to x is saved in the register $a0 and that the first
# word in that array is the size of the array.

# Initialization
addi $s0, $zero, 0           # i = 0
lw   $s1, 0($a0)             # $s1 equals size of array
addi $s2, $s1, 4             # $s2 points to the first element in the array x

# Space allocation
add  $a0 $zero, $s1          # $a0 contain the size of the array
addi $t0, $zero, 4           # Load 4 to $t0
mul  $a0, $a0, $t0           # $a0 contains the number of bytes, not the size
addi $v0, 9                  # syscall 9, heap allocation
syscall                      # Address to allocated space is in $v0
add  $s3, $v0, $zero         # Pointer to allocated space is saved in $s3

# Init while
addi $s4, $s3, 4             # $s4 point to first element in y

# While loop
WhileCond:
    slt $t0, $s0, $s1        # $t0 is 1 if i < size, 0 otherwise
    bne $t0, $zero, EndWhile # Branch if i >= size

WhileCode:
    lw  $a0, 0($s2)          # The argument to a function is set to M[$s2]
    jal f                    # Call the function f
    beq $v0, $zero, IfFalse  # Branch if return val from f is false

    IfTrue:
        lw   $t0, 0($s2)     # $s2 point to the i'th element
        sw   $t0, 0($s4)     # $t0 is saved to $s4 (next element in y)
        addi $s4, $s4, 4     # $s4 point to next element

    IfFalse:
    addi $s2, $s2, 4         # Increment $s2 to point to next element in x
    addi $s0, $s0, 1         # i is incremented (for the while condition)
    j   WhileCond            # Go back to the while condition

EndWhile:
    # Compute length of array y
    sub  $t0, $s3, $s4       # $t0 is the length in bytes of array y
    addi $t1, $t1, 4         # $t1 is 4
    div  $t0, $t0, $t1       # $t0 is now the length of y
    sw   $t0, 0($s3)         # Write array length of y to first word in y

    # Add return values to return registers
    addi $v0, $s3, 0         # $v0 point to the memoryblock with y
