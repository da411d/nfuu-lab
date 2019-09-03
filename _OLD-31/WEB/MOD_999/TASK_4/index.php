<?php
	$x = +($_POST['x'] ?? 8);
	$y = +($_POST['y'] ?? 15.6);
	$z = +($_POST['z'] ?? 12.6);
	$trigger = $_POST['trigger'] ?? "a";
	
	function f($x, $y, $z, $trigger){
		switch($trigger){
			case "a":
				return 1 + sqrt(abs(cos(($x+$y)**2)**2));
				
			case "b":
				return 1/$z**2 + sin(abs($y)**0.3)**2;
			
			case "c":
				return cos(3*$x/$y);
				
			default:
				return 0;
		}
	}
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Manzhula</title>
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
		<label>Variant</label>
		
		<label>
			<input type="radio" name="trigger" value="a" checked>
			a
		</label>
		<label>
			<input type="radio" name="trigger" value="b">
			b
		</label>
		<label>
			<input type="radio" name="trigger" value="c">
			c
		</label>
		
	</p>
	<p>
		<input type="submit">
	</p>
</form>
<?php
	if(count($_POST)){
		$result = f($x, $y, $z, $trigger);
		file_put_contents("result.txt", $result);
		echo '<a href="result.txt" target="_blank">result.txt</a>';
	}
?>
</body>
</html>
