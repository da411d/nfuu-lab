let tests = [
	[304, 268, 272, 262, 283],
	[272, 264, 256, 269, 285, 267],
	[223, 184, 109, 183],
];

for (let test of tests){
	console.log("Група", tests.indexOf(test) + 1);
	console.log(test.sort((a, b) => a-b).join(", "));
	console.log("Медіна:", median(test));
	console.log("Сподівання:", expectation(test));
	console.log("Дисперсія:", variance(test));
	
	console.log();
}

function median(arr){
	arr.sort((a, b) => a-b);
	
	if(arr.length % 2 == 1){
		return arr[ (arr.length - 1) / 2];
	}else{
		return (
			arr[arr.length / 2] + arr[arr.length / 2 - 1]
		) / 2;
	}
}

function expectation(arr){
	return arr.reduce((sum, a) => sum + a, 0) / arr.length;
}

function variance(arr){
	let exp = expectation(arr);
	return arr.reduce((sum, a) => sum + (a - exp)**2, 0) / arr.length;
}
