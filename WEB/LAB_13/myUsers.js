angular.module('LAB_13', []).controller('LAB_13_Controller', function ($scope) {

	/*
		HIDE
	*/
    $scope.popupHidden = true;
	$scope.hidePopup = function(){
		$scope.popupHidden = true;
	}
	$scope.showPopup = function(){
		$scope.popupHidden = false;
	}
	
	/*
		USERS
	*/
    $scope.users = (() => {
		let names = "Василь Петро Іван Давид Влад Юра Богдан Олексій Олег Максим Святослав Ярослав Станіслав Денис Данило Віка Юля Христя Наталя Кароліна Іванка Василина Ангеліна Аліса Аліна Катя".split(" ");
		let surnames = "Василишин Пришляк Заник Ващук Манжула Прокопчук Козунь Пацута Покидайло Поригайло Водичка Синиця Лахно".split(" ");
		let users = {};
		
		for(let i=0; i<15; i++){
			let key = "U_" + Math.random().toString(36).substr(2, 6).toUpperCase();
			users[key] = {
				index: i+1,
				firstName: names[~~(names.length*Math.random())],
				lastName: surnames[~~(surnames.length*Math.random())],
				birthDate: new Date(new Date()*Math.random()),
			};
		}
		
		return users;
	})();
	
	
	$scope.temp = null;

    $scope.editUser = function (id) {
        $scope.showPopup();
        if (id == 'new') {
            $scope.edit = true;
            $scope.index = "U-" + Math.random().toString(36).substr(2, 6);
            $scope.temp = {};
        } else {
            $scope.edit = false;
            $scope.index = id;
            $scope.temp = $scope.users[$scope.index];
        }
    };

    $scope.saveUser = function () {
        $scope.hidePopup();
		
        if ($scope.edit == true) {
            $scope.LENGTH = $scope.users.length;
            $scope.users.push({id: $scope.LENGTH + 1, fName: $scope.fName, lName: $scope.lName});
        } else {
            $scope.users[$scope.index].fName = $scope.fName;
            $scope.users[$scope.index].lName = $scope.lName;
        }
    };

    $scope.$watch('passw1', $scope.test);
    $scope.$watch('passw2', $scope.test);
    $scope.$watch('fName', $scope.test);
    $scope.$watch('lName', $scope.test);

    $scope.test = function () {
        if ($scope.passw1 !== $scope.passw2) {
            $scope.error = true;
        } else {
            $scope.error = false;
        }
        $scope.incomplete = false;
        
        if (
			!$scope.fName.length || 
			!$scope.lName.length || 
			!$scope.passw1.length || 
			!$scope.passw2.length) {
            $scope.incomplete = true;
        }
    };

}).filter('dateFormat', function() {
	return function(d) {
		d = d.split(".");
		d[1] = ["січня", "лютого", "березня", "квітня", "травня", "червня", "липня", "серпня", "вересня", "жовтня", "листопада", "грудня"][d[1]-1];
		d = d.join(" ");
		return d;
	};
});


