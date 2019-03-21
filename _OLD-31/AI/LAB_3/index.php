<?php
set_time_limit(3);

if(isset($_POST["o"])){
	$category = ($_POST["o"] == 1) ? 1 : 2;
	echo "<script>alert('Категорія = {$category}')</script>";
}
?>
Скільки кружочків?
<form method="POST">
	<input type="submit" name="o" value="0">
	<input type="submit" name="o" value="1">
</form>