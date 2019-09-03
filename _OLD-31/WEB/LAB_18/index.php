<?php
	$user_surname = $_POST['user_surname'] ?? "";
	$user_name = $_POST['user_name'] ?? "";
	$user_group = $_POST['user_group'] ?? "";
	$user_variant = (int) $_POST['user_variant'] ?? 1;
	$x = 1.23 * $user_variant;
	$y = 4.6 * $user_variant;
	$z = 36.6 / $user_variant;
	$f = f($x, $y, $z);
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
		$content = "
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
					<td>X = N * 1.23</td>
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
				<tr>
					<td>Результат обчислення функції</td>
					<td>{$f}</td>
				<tr>
			</table>
		";
		$title = "LAB_18";
		$headers = [
			"From: (NFUU Lab) noreply@nltu.lviv.ua",
			"MIME-Version: 1.0",
			"Content-Type: text/html; charset=UTF-8",
		];
		$headers = implode("\r\n", $headers);
		mail("da411d@gmail.com", $title, $content, $headers);
		
		echo $content;
	}
?>

</body>
</html>
