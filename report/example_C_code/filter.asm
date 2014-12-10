# Assuming the pointer to the start array is saved in $t1

lw  $t2, 0($t1)              # Load size of array to $t2

li  $s1, 0                   # Load 0 to $s1
add $s1, $s1, $hp            # Save the heap pointer to $s1
li  $t3, 4                   # Load 4 to $t3
mul $t3, $t3, $t2            # The size of the array in bytes
add $hp, $hp, $t3            # The heap pointer is incremented appropriately

li  $t3, 1                   # $t3 points out the next element in the array
While:
    beq $t2, $zero, EndWhile # When $t2 is zero we jump out of the while loop

    $

EndWhile:
