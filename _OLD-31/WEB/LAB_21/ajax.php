<?php
$con = mysqli_connect("localhost", "mysql", "fflfljfi24004", "nltu");
if (!$con) {
	exit("Помилка з'єднання: (".mysqli_connect_errno().")".mysqli_connect_error());
}
mysqli_select_db($con, "nltu");

function f($x, $y, $z){
	return 
		(sin(pow(abs($x*$x - 1), 0.3)) - sqrt(pow(cos(abs($y + 2*$z)), 2))) / 
		(1 + $z + $y*$y/2 + pow(abs(x), 3)/6);
}


if(count($_POST)){
	$user_surname = $_POST['user_surname'] ?? "";
	$user_name = $_POST['user_name'] ?? "";
	$user_group = $_POST['user_group'] ?? "";
	$user_variant = (int) $_POST['user_variant'] ?? 1;
	$x = 1.23 * $user_variant;
	$y = 4.6 * $user_variant;
	$z = 36.6 / $user_variant;
	$f = f($x, $y, $z);
	$query = "INSERT INTO lab21 (x, y, z, result) values ({$x}, {$y}, {$z}, {$f})";
	mysqli_query($con, $query) or die(mysqli_error());
	
}else{
	$query = "SELECT * FROM lab21";
	$result = mysqli_query($con, $query) or die(mysqli_error());
	$array = [];
	for ($i=0; $i<mysqli_num_rows($result); $i++){
		$array[] = mysqli_fetch_array($result);
	}
	echo json_encode($array);
}
?>
