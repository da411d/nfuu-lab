document.querySelector("#getDiff").addEventListener("click", (e) => {
	document.querySelector("#container").innerText = new Date().getTimezoneOffset() / 60;
});

document.querySelector("#toLower").addEventListener("blur", (e) => {
	e.target.value = e.target.value.toLowerCase();
});