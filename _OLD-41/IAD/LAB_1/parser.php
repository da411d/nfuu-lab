<?php

$source = "https://uk.wikipedia.org/wiki/Міста_України_(за_населенням)";
$pageContent = file_get_contents($source);
$pageContent = str_replace(["\r", "\n"], "", $pageContent);

preg_match_all('/<tr>((?!<\/tr>).)+<\/tr>/im', $pageContent, $rows);
$rows = $rows[0];

$cityPopulationData = [];
foreach($rows as $row){
	preg_match('/<tr><td>\d+<\/td><td><a [^>]+>([^<]++)<\/a><\/td><td><a [^>]+>[^<]+<\/a><\/td><td [^>]+>([\d\s]+)<\/td>/m', $row, $columns);
	$name = $columns[1];
	$population = $columns[2];
	
	if($name || $population){
		$cityPopulationData[$name] = $population;
	}
}

// print_r($cityPopulationData);
foreach($cityPopulationData as $name => $population){
	echo $name, " - ", $population, "\n";
}
