function rand(mi = 0, ma = Number.MAX_SAFE_INTEGER){return Math.floor(Math.random() * (ma - mi + 1) + mi);}

let M1 = angular.module('MOD_1', []).controller('MOD_1_TASK_3', function ($scope) {
    $scope.users = (() => {
		let names = "Василь Петро Іван Давид Влад Юра Богдан Олексій Олег Максим Святослав Ярослав Станіслав Денис Данило Віка Юля Христя Наталя Кароліна Іванка Василина Ангеліна Аліса Аліна Катя".split(" ");
		let surnames = "Василишин Пришляк Заник Ващук Манжула Прокопчук Козунь Пацута Покидайло Поригайло Водичка Синиця Лахно".split(" ");
		let codes = [99, 95, 98, 97, 96, 95, 73, 68, 67, 66, 63];
		
		let users = [];
		
		for(let i=0; i<15; i++){
			users.push({
				firstName: names[rand(0, names.length-1)],
				lastName: surnames[rand(0, surnames.length-1)],
				phone: "+380" + codes[rand(0, codes.length-1)] + rand(111, 999) + rand(1111, 9999),
			});
		}
		
		return users;
	})();

}).filter('upperCase', function() {
	return (d) => d.toUpperCase();
});
