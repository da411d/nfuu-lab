<?php
set_time_limit(3);
header("Content-type: text/plain");
include "db.php";
define("_TRESHOLD_", 0.65);

echo "База знань: \r\n";
print_r($db);
echo "\r\n";


echo "Вхідні дані: \r\n";
$input = file_get_contents("data.txt");
$input = explode("\n", $input);
foreach($input as $k => $v){
	$input[$k] = str_split($v);
	echo join(" ", $input[$k]) . "\r\n";
}
echo "\r\n";

$registers = [0, 0, 0, 0];

$vector = [
	[0, 0],
	[0, 3],
	[0, 6],
	[3, 0],
	[3, 3],
	[3, 6]
];
foreach($vector as $v){
	$i = $v[0];
	$j = $v[1];
	
	$registers[0] += get4($input, $j, $i, "|", 3);
	$registers[1] += get4($input, $i, $j, "-", 3);
	$registers[2] += get4($input, $i, $j, "\\", 3);
	$registers[3] += get4($input, $i, $j, "/", 3);
}


echo "Результат:\r\n";
print_r($registers);
echo "\r\n";

$guess = [];
foreach($db as $letter => $code){
	$diff = 0;
	
	for($i=0; $i < strlen($code); $i++){
		$diff += abs($code[$i] - $registers[$i]);
	}
	
	$guess[$letter] = $diff;
}
asort($guess);
$max = max($guess);
print_r($guess);
echo "Імовірність, що наша буква: \r\n";
foreach($guess as $letter => $diff){
	echo $letter . " - " . round((1 - $diff/$max)*100, 2) . "%\r\n";
}


/*
	ARR - input array
	dir - |-\/
	COUNT - count
*/
function get4($arr, $x, $y, $dir = "-", $count = 0){
	if($count == 0){
		return true;
	}
	if($arr[$y][$x] != "1"){
		return false;
	}

	
	$a = 0;
	$b = 0;
	if($dir == "/" || $dir == "-" || $dir == "\\"){
		$a = 1;
	}
	if($dir == "\\" || $dir == "|"){
		$b = 1;
	}
	if($dir == "/"){
		$b = -1;
	}
	
	$c = 0;
	
	for($i=0; $i<$count; $i++){
		$c += ($arr[$y + $b*$i][$x + $a*$i] == "1") ? 1 : 0;
	}
	
	return ($c / $count) >= _TRESHOLD_;
}