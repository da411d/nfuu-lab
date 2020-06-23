HTMLDocument.prototype.on = HTMLDocument.prototype.addEventListener;
HTMLDocument.prototype.qq = HTMLDocument.prototype.querySelector;
HTMLDocument.prototype.qqq = HTMLDocument.prototype.querySelectorAll;
HTMLElement.prototype.on = HTMLElement.prototype.addEventListener;
HTMLElement.prototype.qq = HTMLElement.prototype.querySelector;
HTMLElement.prototype.qqq = HTMLElement.prototype.querySelectorAll;
function qq(t){return document.qq(t);}
function qqq(t){return document.qqq(t);}





/*
	HERE
*/
const f1 = x => 3 + 12*x + 0.4 * (x**3);
f1.valueOf = () => 50;
const f2 = x => Math.sin(x**3) + 7 * (x**2);
f2.valueOf = () => 10;

const range = {
	from: 0,
	to: 4,
	step: 0.01,
};

let calculations = [];
for(let x = range.from; x <= range.to; x += range.step){
	let key = Math.round(x / range.step);
	
	let temp_f1 = f1(x);
	let temp_f2 = f2(x);
	
	let f1_div = temp_f1 / f1;
	let f2_div = temp_f2 / f2;
	
	let max = Math.max(f1_div, f2_div);
	let min = Math.min(f1_div, f2_div);
	
	calculations[key] = {
		f1: temp_f1.toFixed(4)*1,
		f2: temp_f2.toFixed(4)*1,
		
		x: x.toFixed(4)*1, 
		f1_div: f1_div.toFixed(4)*1, 
		f2_div: f2_div.toFixed(4)*1, 
		max: max.toFixed(4)*1, 
		min: min.toFixed(4)*1,
	};
}

let in_range = calculations.filter(row => row.f1 <= f1 && row.f2 >= f2);

let minmax = in_range.reduce((current, row) => current.max < row.max ? current : row);
let maxmin = in_range.reduce((current, row) => current.max > row.max ? current : row);



/*
	VISUAL
*/
qq(".table").innerHTML = `<tr>
	<th>X</th>
	<th>F1</th>
	<th>F2</th>
	<th>f1/f1*</th>
	<th>f2/f2*</th>
	<th>max</th>
	<th>min</th>
</tr>` + in_range.map((row) => `
<tr>
	<td>${row.x.toFixed(4)}</td>
	<td>${row.f1.toFixed(4)}</td>
	<td>${row.f2.toFixed(4)}</td>
	<td>${row.f1_div.toFixed(4)}</td>
	<td>${row.f2_div.toFixed(4)}</td>
	<td>${row.max.toFixed(4)}</td>
	<td>${row.min.toFixed(4)}</td>
</tr>
`).join("\n");


qq(".js-result").innerHTML = `
<p>
	<b>MinMax:</b> ${minmax.max} <br>
	X = ${minmax.x} <br>
	F1 = ${minmax.f1} <br>
	F2 = ${minmax.f2}
</p>
<p>
	<b>MaxMin:</b> ${maxmin.min} <br>
	X = ${maxmin.x} <br>
	F1 = ${maxmin.f1} <br>
	F2 = ${maxmin.f2}
</p>
`;

new Chart(qq("canvas"), {
	type: "scatter",
	xAxisID: "x",
	yAxisID: "y",
	data: {
		labels: calculations.map(row => row.x),
		datasets: [
			{
				label: "F1",
				data: calculations.map(row => ({
					x: row.x,
					y: row.f1,
				})),
				fill: false,
				borderColor: "rgb(3, 169, 244)",
				lineTension: 0.4,
				pointRadius: 0,
			},
			{
				label: "F2",
				data: calculations.map(row => ({
					x: row.x, 
					y: row.f2,
				})),
				fill: false,
				borderColor: "rgb(103, 58, 183)",
				lineTension: 0.4,
				pointRadius: 0,
			},
			{
				label: "IN RANGE",
				data: in_range.map(row => ({
					x: row.x, 
					y: Math.max(row.f1, row.f2)
				})),
				fill: true,
				backgroundColor: "rgba(76, 175, 80, 0.3)",
				lineTension: 0.4,
				pointRadius: 0,
			},
			{
				label: "SOLUTION",
				data: [
					{
						x: minmax.x,
						y: (
							minmax.f1_div >= minmax.f2_div ? 
								minmax.f1 : minmax.f2
						),
					},
					{
						x: minmax.x,
						y: (
							minmax.f1_div <= minmax.f2_div ? 
								minmax.f1 : minmax.f2
						),
					},
				],
				fill: false,
				borderColor: "rgb(233, 30, 99)",
				lineTension: 0.4,
				pointRadius: 5,
			},
		],
	},
	options: {
		tooltips: {
			mode: "index",
		},
		elements: {
			point:{
				radius: 0,
				hitRadius: 10,
			}
		}
	},
});