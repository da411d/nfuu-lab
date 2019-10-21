// FUNCTIONS
const bottom = (x) => Math.sin(x /* * 180/Math.PI */) * (x + 0.5);
const left = (t) => 2 * t + 0.4794;
const right = (t) => t + 0.9975;

function calculate(deltaH = 0.2, deltaTau = 0.2){
	let arrayWidth = (1 / deltaH) + 1;
	let arrayHeight = (1 / deltaTau) + 1;
	console.log(arrayWidth + "x" + arrayHeight);

	let matrix = Array(arrayHeight)
		.fill(null)
		.map(x => Array(arrayWidth).fill(null));

	// 1. Left and right border
	for(let i = 0; i < arrayHeight; i++){
		let t = (arrayHeight - i - 1) * deltaTau;
		matrix[i][0] = left(t);
		matrix[i][arrayWidth-1] = right(t);
	}

	// 2. Bottom border
	for(let i = 0; i < arrayWidth; i++){
		let x = i * deltaH;
		matrix[arrayHeight-1][i] = bottom(x);
	}

	// 3. Calculate
	for(let i = arrayHeight-1-1; i >= 0; i--){
		for(let j = 1; j < arrayWidth - 1; j++){
			let a = matrix[i+1][j-1],
				b = matrix[i+1][j],
				c = matrix[i+1][j+1];
			matrix[i][j] = (a + 4*b + c) / 6;
		}
	}
	
	return matrix;
}


function render(){
	function round(value, n = 4){
		return Math.round(value * 10**n) / 10**n;
	}
	let deltaH = document.querySelector("#deltaH").value*1 || 0;
	let deltaTau = document.querySelector("#deltaTau").value*1 || 0;
	try{
		let matrix = calculate(deltaH, deltaTau);
		const color = function(val){
			let min = Math.min(...matrix.flat());
			let max = Math.max(...matrix.flat());
			let percent = (val - min) / (max - min);
			let r, g, b;
				
			if(percent < 0.5){ // cold
				r = 100;
				g = 100;
				b = 100 + (1 - percent) * 155;
			}else{ // hot
				r = 100 + percent * 155;
				g = 100;
				b = 100;
			}
			return `rgba(${r}, ${g}, ${b}, 1)`;
		}
		document.querySelector("#table").innerHTML = matrix.map((row) => 
			"<tr>" + row.map((cell) => 
				`<td style="disabled-background: ${color(cell)}">` + round(cell) + "</td>"
			).join("") + "</tr>"
		).join("");
		
	}catch(e){
		console.error(e);
		document.querySelector("#table").innerHTML = "ERROR";
		return;
	}
}
document.querySelector("#deltaH").addEventListener("input", render);
document.querySelector("#deltaTau").addEventListener("input", render);
render();