<?php

function moda($array){
	$map = [];
	foreach($array as $item){
		if(!isset($map[$item])){
			$map[$item] = 0;
		}
		$map[$item]++;
	}
	
	$moda = array_search(max($map), $map);
	return array_filter($array, function($item) use ($moda){
		return $item == $moda;
	});
}
