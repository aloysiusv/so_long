#! /bin/bash

VALGRIND="valgrind --leak-check=full --show-leak-kinds=all"
SEP="===================================================="

execMandatory() {

	echo $VALGRIND ./so_long maps/tests/$1
	$VALGRIND ./so_long maps/tests/$1
	echo $SEP
}

execBonus() {

	echo $VALGRIND ./so_long_bonus bonus/maps_bonus/tests/$1
	$VALGRIND ./so_long_bonus bonus/maps_bonus/tests/$1
	echo $SEP	
}

make

execMandatory map.bre
execMandatory newline.ber
execMandatory no_C.ber
execMandatory no_E.ber
execMandatory no_newline.ber
execMandatory no_P.ber
execMandatory not_rect.ber
execMandatory walls_no.ber
execMandatory wrong_char.ber
execMandatory only_newlines.ber
execMandatory space_first.ber
execBonus map.bre
execBonus newline.ber
execBonus no_C.ber
execBonus no_E.ber
execBonus no_newline.ber
execBonus no_P.ber
execBonus not_rect.ber
execBonus walls_no.ber
execBonus wrong_char.ber
execBonus only_newlines.ber
execBonus space_first.ber
