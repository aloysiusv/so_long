#! /bin/bash

VALGRIND="valgrind --leak-check=full --show-leak-kinds=all"
SEP="===================================================="

execMandatory() {

	echo $VALGRIND ./so_long maps/$1
	$VALGRIND ./so_long maps/$1
	echo $SEP
}

execBonus() {

	echo $VALGRIND ./so_long_bonus bonus/maps_bonus/$1
	$VALGRIND ./so_long_bonus bonus/maps_bonus/$1
	echo $SEP	
}

make

execMandatory frodo_solo.ber
execBonus gollum_solo.ber
execBonus frodo_vs_orc.ber
execBonus diagon_alley.ber
execBonus heroes.ber