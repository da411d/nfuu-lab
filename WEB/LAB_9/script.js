var APP = {
	form: document.querySelector("form"),
	target: document.querySelector("div.container"),
	
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
	
	render: (data) => {
		container = APP.target;
		container.innerHTML = "";
		
		var table = APP.el("table", {
			border: 1
		});
		container.appendChild(table);
		
		var tr = APP.el("tr");
		table.appendChild(tr);
		
		tr.appendChild(
			APP.el("th", {
				innerText: "Key"
			})
		);
		tr.appendChild(
			APP.el("th", {
				innerText: "Value"
			})
		);
			
		for(var d of data){
			var tr = APP.el("tr");
			table.appendChild(tr);
			
			tr.appendChild(
				APP.el("td", {
					innerText: d.name,
					width: 500
				})
			);
			tr.appendChild(
				APP.el("td", {
					innerText: d.value,
					width: 500
				})
			);
		}
	},
	
	callback: () => {
		var data = [];
		
		APP.form.querySelectorAll("input, textarea, select").forEach((el) => {
			data.push({
				name: el.name,
				value: el.value + (el.checked ? "✅" : "")
			})
		});
		
		APP.render(data);
	},
	
	init: () => {
		APP.form.querySelectorAll("input, textarea, select").forEach((el) => {
			el.addEventListener("keyup", APP.callback)
			el.addEventListener("mouseup", APP.callback)
			el.addEventListener("change", APP.callback)
		});
	}
}


APP.init();