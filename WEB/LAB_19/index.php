<?php
	$user_surname = $_POST['user_surname'] ?? "";
	$user_name = $_POST['user_name'] ?? "";
	$user_group = $_POST['user_group'] ?? "";
	$user_variant = (int) $_POST['user_variant'] ?? 1;

	function f($x, $y, $z){
		return 
			(sin(pow(abs($x*$x - 1), 0.3)) - sqrt(pow(cos(abs($y + 2*$z)), 2))) / 
			(1 + $z + $y*$y/2 + pow(abs(x), 3)/6);
	}
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>LAB_18</title>
	<style>
		label{display: block;}
	</style>
</head>
<body>

<form method="POST">
	<p>
		<label>Прізвище</label>
		<input type="text" name="user_surname" value="<?php echo $user_surname; ?>">
	</p>
	<p>
		<label>Ім'я</label>
		<input type="text" name="user_name" value="<?php echo $user_name; ?>">
	</p>
	<p>
		<label>Група</label>
		<input type="text" name="user_group" value="<?php echo $user_group; ?>">
	</p>
	<p>
		<label>Номер варіанту</label>
		<input type="number" name="user_variant" value="<?php echo $user_variant; ?>">
	</p>
	<p>
		<input type="submit">
	</p>
</form>

<?php
	if(count($_POST)){
		$x_from = 1.23 * $user_variant;
		$x_to = $x_from + 10;
		$x = [];
		$y = 4.6 * $user_variant;
		$z = 36.6 / $user_variant;
		for($i = $x_from; $i<$x_to; $i++){
			$x[] = f($i, $y, $z);
		}
		$x = implode("<br>\r\n", $x);
		
		$content = "
			<meta charset='UTF=8'>
			<table>
				<tr>
					<td>Прізвище</td>
					<td>{$user_surname}</td>
				<tr>
				<tr>
					<td>Ім'я</td>
					<td>{$user_name}</td>
				<tr>
				<tr>
					<td>Група</td>
					<td>{$user_group}</td>
				<tr>
				<tr>
					<td>Варіант</td>
					<td>{$user_variant}</td>
				<tr>
				<tr>
					<td>X</td>
					<td>{$x}</td>
				<tr>
				<tr>
					<td>Y = N * 4.6</td>
					<td>{$y}</td>
				<tr>
				<tr>
					<td>Z = N * 36.6</td>
					<td>{$z}</td>
				<tr>
			</table>
		";
		$content = iconv("UTF-8", "windows-1251", $content);
		
		$file_name = $user_surname . "_" . time() . ".html";
		file_put_contents(iconv("UTF-8", "windows-1251", $file_name), $content);
		
		echo "<a href='./{$file_name}' target='_blank'>Go to file</a>";
	}
?>

</body>
</html>
