	   addi	$a0, $zero, 0
	   jal	tree
	   halt
	   halt
	   halt
	   halt
tree : addi	$sp, $sp, -8
	   sw	$ra, 4($sp)
	   sw	$a0, 0($sp)
	   addi	$t0, $0, 6
	   slt	$t1, $t0, $a0
	   beq	$t1, $zero, L1

	   addi	$v0, $zero, 0
	   addi	$sp, $sp, 8
	   jr	ra

L1 :   sll	$s0, $a0, 2
	   lw	$s1, 0($s0)
	   addi	$a0, $a0, 1
	   sll	$a0, $a0, 1
	   jal	tree
	   add	$s1, $s1, $v0
	   addi	$a0, $a0, -1
	   jal	tree
	   add	$v0, $s1, $v0

	   lw	$a0, 0($sp)
	   lw	$ra, 4($sp)
	   addi	$sp, $sp, 8
	   jr 	ra