<?php
include "CandyShop.class.php";

function printPackage($package){
	$packageName = str_replace("CandyPackageBuilder", "", get_class($package));
	$package = $package->getCandyPackage();
	
	echo "-= Пакунок ", $packageName, " =-", "\n";
	echo "Кількість льодяників: ", $package->Льодяники, "\n";
	echo "Кількість шоколадних цукерок: ", $package->ШоколадіЦукерки, "\n";
	echo "Кількість вафель: ", $package->Вафлі, "\n";
	echo "Кількість драже: ", $package->Драже, "\n";
	echo "Вартість: ", $package->getPrice(), "\n";
	echo "\n";
}

$ласунка = new ЛасункаCandyPackageBuilder();
printPackage($ласунка);

$наминайко = new НаминайкоCandyPackageBuilder();
printPackage($наминайко);

$панКоцький = new ПанКоцькийCandyPackageBuilder();
printPackage($панКоцький);
