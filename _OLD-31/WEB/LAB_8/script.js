var APP = {
	a: (x, y, z, b) => {
		var f =  
			Math.pow(Math.abs(x), 0.43) + 
			(
				Math.exp(y-x) + 
				Math.sqrt(Math.pow(Math.abs(y*y + b), 0.22))
			) / (
				1 + 
				x*x * Math.abs(
					y - 
					Math.pow(Math.tan(z), 2)
				)
			);
		return f;
	},
	
	b: (x, y, z) => {
		var f =  
		(
			2*z + 
			Math.cos(
				Math.pow(
					Math.abs(y - 3*x),
					1/3
				)
			)
		) / (
			2.1 + 
			Math.pow(
				Math.sin(
					Math.pow(
						Math.abs(z*z*z - y),
						0
					)
				),
				2
			)
		) * 
		Math.pow(
			Math.log(
				Math.abs(z - x)
			), 
			2
		)
		return f;
	},
	
	root: document.querySelector("body"),
	
	el: (t, p = []) => {
		var el = document.createElement(t);
		for(var k in p){
			if(k == "innerText" || k == "innerHTML"){
				el[k] = p[k];
			}else{
				el.setAttribute(k, p[k]);
			}
		}
		return el;
	},
	
	render: (data, key) => {
		var root = APP.root;
		var container = APP.el("div", {
			class: "container"
		});
		root.appendChild(container);
		
		var table = APP.el("table", {
			border: 1
		});
		container.appendChild(table);
		
		var tr = APP.el("tr");
		table.appendChild(tr);
		
		tr.appendChild(
			APP.el("th", {
				innerText: "X"
			})
		);
		tr.appendChild(
			APP.el("th", {
				innerText: "Y"
			})
		);
		tr.appendChild(
			APP.el("th", {
				innerText: key.toUpperCase()
			})
		);
			
		for(var d of data){
			var tr = APP.el("tr");
			table.appendChild(tr);
			
			tr.appendChild(
				APP.el("td", {
					innerText: d.x.toFixed(1),
					width: 100
				})
			);
			tr.appendChild(
				APP.el("td", {
					innerText: d.y.toFixed(1),
					width: 100
				})
			);
			tr.appendChild(
				APP.el("td", {
					innerText: d[key].toFixed(4),
					width: 100
				})
			);
		}
	},
	
	init: () => {
		var _x = {
			from: -1,
			to: 1,
			delta: 0.2
		};
		var _y = {
			from: -2,
			to: 2,
			delta: 0.2
		};
		var z = 1.32;
		
		var data = [];
		for(var x = _x.from; x<=_x.to; x+=_x.delta){
			for(var y = _y.from; y<=_y.to; y+=_y.delta){
				var b = APP.b(x, y, z);
				var a = APP.a(x, y, z, b);
				
				data.push({
					a, b, x, y, z
				});
			}
		}
		
		APP.render(data, "a");
		APP.render(data, "b");
	}
}


APP.init();