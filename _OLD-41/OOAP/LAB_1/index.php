<?php
include "BooksList.class.php";

function printList($list){
	if(!count($list)){
		echo "The list is empty", "\n";
	}
	foreach($list as $item){
		echo str_pad($item->id, 24, " "), " | ";
		echo str_pad($item->author, 16, " "), " | ";
		echo str_pad($item->name, 24, " "), "\n";
	}
	echo "\n";
}

$list = new BooksListProxy();



echo "EMPTY LIST", "\n";
printList($list->list());

echo "ADD 3 ITEMS", "\n";
$list->add((object)[
	"author" => "John",
	"name" => "My small lie",
]);
$list->add((object)[
	"author" => "Peter",
	"name" => "Hello, childhood",
]);
$list->add((object)[
	"id" => "BOOK.1569923345.871636",
	"author" => "John",
	"name" => "Oh, bomb",
]);

printList($list->list());


echo "SEARCH BY JOHN", "\n";
printList($list->search("John"));

echo "DELETE BY ID BOOK.1569923345.871636", "\n";
$list->delete("BOOK.1569923345.871636");
printList($list->list());