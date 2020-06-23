const input = document.querySelector("#input");
const output = document.querySelector("#output");

input.addEventListener("input", () => {
	input.value = filter(input.value);
	output.value = _encrypt(input.value);
});

output.addEventListener("input", () => {
	output.value = filter(output.value);
	input.value = _decrypt(output.value);
});


const letters = [
	"Г", "О", "К", "!", "Б", "Ц",
	"Ч", "Ї", "Х", "Д", "Щ", "З",
	"Л", "Е", ",", ":", "Т", " ",
	"Я", "У", "В", "І", "Є", "Ю",
	"С", "Ж", "?", "(", "Ш", "Й",
	";", "Н", "П", "М", ")", ".",
	"Ґ", "Р", "Ь", "Ф", "И", "А",
];

const filter = string => String(string).toString().toUpperCase()
	.split("")
	.filter(letter => letters.includes(letter))
	.join("");

const _crypt = (input, offset) => {
	input = filter(input);
	let result = "";
	for(let letter of input){
		const index = letters.indexOf(letter);
		const newIndex = (letters.length + index + offset) % letters.length;
		result += letters[newIndex];
	}
	return result;
};

const _encrypt = input => _crypt(input, 6);
const _decrypt = input => _crypt(input, -6);
