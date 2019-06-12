<?php
	$user_surname = $_POST['user_surname'] ?? "";
	$user_name = $_POST['user_name'] ?? "";
	$user_father = $_POST['user_father'] ?? "";
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
		<label>Прізвище</label>
		<input type="text" name="user_surname" value="<?php echo $user_surname; ?>">
	</p>
	<p>
		<label>Ім'я</label>
		<input type="text" name="user_name" value="<?php echo $user_name; ?>">
	</p>
	<p>
		<label>По-батькові</label>
		<input type="text" name="user_father" value="<?php echo $user_father; ?>">
	</p>
	<p>
		<input type="submit">
	</p>
</form>
<?php
	if(count($_POST)){
		$data = implode("\r\n", [
			$user_surname, $user_name, $user_father
		]);
		file_put_contents("MOD_4_Manzhula_3.txt", $data);
		
		echo '<a href="MOD_4_Manzhula_3.txt" target="_blank">result.txt</a>';
	}
?>

</body>
</html>
