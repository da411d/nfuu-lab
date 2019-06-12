<?php
	$x = +($_POST['user_surname'] ?? 7.3);
	$y = +($_POST['user_name'] ?? 22.1);
	$z = +($_POST['user_father'] ?? 3.5);
	
	function f($x, $y, $z){
		return (1 + sqrt(abs(cos(($x + $y)**2)**2))) / 
			(1/$z**2 + sin(abs($y)**0.3)**2) + 
			tan(3*$x / $y);
	}
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>MOD_4_3 Manzhula</title>
	<style>
		label{display: block;}
	</style>
</head>
<body>

<form method="POST">
	<p>
		<label>X</label>
		<input type="text" name="x" value="<?php echo $x; ?>">
	</p>
	<p>
		<label>Y</label>
		<input type="text" name="y" value="<?php echo $y; ?>">
	</p>
	<p>
		<label>Z</label>
		<input type="text" name="z" value="<?php echo $z; ?>">
	</p>
	<p>
		<input type="submit">
	</p>
</form>
<?php
	if(count($_POST)){
		$result = f($x, $y, $z);
		
		$data = "x = {$x};\r\ny = {$y};\r\nz = {$z};\r\nresult = {$result}";
		file_put_contents("MOD_4_Manzhula_5_result.txt", $data);
		
		echo '<a href="MOD_4_Manzhula_5_result.txt" target="_blank">result.txt</a>';
	}
?>
</body>
</html>
