#! /bin/bash

VALGRIND="valgrind --leak-check=full --show-leak-kinds=all"
SEP="===================================================="

execMandatory() {

	echo $VALGRIND ./so_long maps/tests/$1
	$VALGRIND ./so_long maps/tests/$1
	echo $SEP
}

execMandatoryNewlines() {

	echo $VALGRIND ./so_long maps/tests/with_newlines/$1
	$VALGRIND ./so_long maps/tests/with_newlines/$1
	echo $SEP
	echo $SEP
}

execBonus() {

	echo $VALGRIND ./so_long_bonus bonus/maps_bonus/tests/$1
	$VALGRIND ./so_long_bonus bonus/maps_bonus/tests/$1
	echo $SEP
	echo $SEP	
}

execBonusNewlines() {

	echo $VALGRIND ./so_long_bonus bonus/maps_bonus/tests/with_newlines/$1
	$VALGRIND ./so_long_bonus bonus/maps_bonus/tests/with_newlines/$1
	echo $SEP	
}

make

execMandatory map.bre
execMandatory no_C.ber
execMandatory no_E.ber
execMandatory no_P.ber
execMandatory no_walls.ber
execMandatory not_rect_end.ber
execMandatory not_rect_start.ber
execMandatory space_first.ber
execMandatory smallest.ber
execMandatory wrong_char.ber
execMandatoryNewlines newline_first.ber
execMandatoryNewlines newline_space.ber
execMandatoryNewlines newline.ber
execMandatoryNewlines newline_middle.ber
execMandatoryNewlines no_C.ber
execMandatoryNewlines no_E.ber
execMandatoryNewlines no_P.ber
execMandatoryNewlines no_walls.ber
execMandatoryNewlines not_rect_end.ber
execMandatoryNewlines not_rect_start.ber
execMandatoryNewlines only_newlines.ber
execMandatoryNewlines smallest.ber
execMandatoryNewlines wrong_char.ber
execBonus map.bre
execBonus no_C.ber
execBonus no_E.ber
execBonus no_P.ber
execBonus no_walls.ber
execBonus not_rect_end.ber
execBonus not_rect_start.ber
execBonus space_first.ber
execBonus smallest.ber
execBonus wrong_char.ber
execBonusNewlines newline_first.ber
execBonusNewlines newline_space.ber
execBonusNewlines newline.ber
execMandatoryNewlines newline_middle.ber
execBonusNewlines no_C.ber
execBonusNewlines no_E.ber
execBonusNewlines no_P.ber
execBonusNewlines no_walls.ber
execBonusNewlines not_rect_end.ber
execBonusNewlines not_rect_start.ber
execBonusNewlines only_newlines.ber
execBonusNewlines smallest.ber
execBonusNewlines wrong_char.ber
