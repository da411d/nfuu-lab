angular.module('myApp', []).controller('userCtrl', function ($scope) {

//    $scope.index = 0;
//    $scope.LENGTH = 0;
//    $scope.fName = '';
//    $scope.lName = '';
    $scope.passw1 = '';
    $scope.passw2 = '';
    $scope.users = [
        {id: 1, fName: 'Hege', lName: "Pege"},
        {id: 2, fName: 'Kim', lName: "Pim"},
        {id: 3, fName: 'Sal', lName: "Smith"},
        {id: 4, fName: 'Jack', lName: "Jones"},
        {id: 5, fName: 'John', lName: "Doe"},
        {id: 6, fName: 'Peter', lName: "Pan"}
    ];
    $scope.hideform = true;

    $scope.editUser = function (id) {
        $scope.hideform = false;
        if (id == 'new') {
            $scope.edit = true;
            $scope.fName = '';
            $scope.lName = '';
        } else {
            $scope.edit = false;
            $scope.index = id - 1;
            $scope.fName = $scope.users[$scope.index].fName;
            $scope.lName = $scope.users[$scope.index].lName;
        }
    };

    $scope.saveUser = function () {
        $scope.hideform = false;
        if ($scope.edit == true) {
            $scope.LENGTH = $scope.users.length;
            $scope.users.push({id: $scope.LENGTH + 1, fName: $scope.fName, lName: $scope.lName});
        } else {
            $scope.users[$scope.index].fName = $scope.fName;
            $scope.users[$scope.index].lName = $scope.lName;
        }
    };

    $scope.$watch('passw1', function () {$scope.test();});
    $scope.$watch('passw2', function () {$scope.test();});
    $scope.$watch('fName', function () {$scope.test();});
    $scope.$watch('lName', function () {$scope.test();});

    $scope.test = function () {
        if ($scope.passw1 !== $scope.passw2) {
            $scope.error = true;
        } else {
            $scope.error = false;
        }
        
        $scope.incomplete = false;
        
        if (!$scope.fName.length || !$scope.lName.length ||
            !$scope.passw1.length || !$scope.passw2.length) {
            $scope.incomplete = true;
        }
    };

});


