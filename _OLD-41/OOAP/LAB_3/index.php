<?php
include "ArraySorter.class.php";

function displayArray($array){
	echo implode(", ", $array), "\n";
}

$array = range(1, 10);
shuffle($array);

echo "Вихідний масив:", "\n";
displayArray($array);
echo "\n";

echo "Посортований масив (бульбашки):", "\n";
displayArray(ArraySorter::instance()->bubble($array));
echo "\n";

echo "Посортований масив (шелл):", "\n";
displayArray(ArraySorter::instance()->shell($array));
echo "\n";

echo "Посортований масив (швидкий):", "\n";
displayArray(ArraySorter::instance()->quick($array));
echo "\n";