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
		<input type="submit" id="submit">
	</p>
</form>

<table border="1">
	<tr>
		<th>#</th>
		<th>x</th>
		<th>y</th>
		<th>z</th>
		<th>result</th>
	</tr>
	<tbody id="list"></tbody>
</table>

<script>
document.querySelector("#submit").addEventListener("click", (e) => {
	e.preventDefault();
	
	const formData = new FormData();
	document.querySelectorAll("input[name]").forEach((input) => {
		formData.append(input.name, input.value);
	});
	const form = e.target.form;
	fetch("./ajax.php", {
		method: 'POST',
		body: formData
	}).then(printAll);
});

async function printAll(){
	const data = await fetch("./ajax.php").then(req=>req.json());
	console.log(data);
	document.querySelector("#list").innerHTML = data.map((d) => `
	<tr>
		<td>${d.id}</td>
		<td>${d.x}</td>
		<td>${d.y}</td>
		<td>${d.z}</td>
		<td>${d.result}</td>
	</tr>`).join("");
}
printAll();
</script>

</body>
</html>
