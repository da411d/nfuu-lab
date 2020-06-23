<?php
class CandyPackage {
	function getPrice(){
		return (
			$this->Льодяники * $this->ЛьодяникиPrice +
			$this->ШоколадіЦукерки * $this->ШоколадіЦукеркиPrice +
			$this->Вафлі * $this->ВафліPrice +
			$this->Драже * $this->ДражеPrice
		);
	}
	
	public $Льодяники = 0;
	public $ШоколадіЦукерки = 0;
	public $Вафлі = 0;
	public $Драже = 0;
	
	public $ЛьодяникиPrice = 3;
	public $ШоколадіЦукеркиPrice = 8;
	public $ВафліPrice = 9;
	public $ДражеPrice = 5;
}

abstract class CandyPackageBuilder{
	public $package;
	
	function __construct(){
		$this->package = new CandyPackage();
	}
	
	function getCandyPackage(){
		$this->setЛьодяники();
		$this->setШоколадіЦукерки();
		$this->setВафлі();
		$this->setДраже();
		return $this->package;
	}
	
	abstract function setЛьодяники();
	
	abstract function setШоколадіЦукерки();
	
	abstract function setВафлі();
	
	abstract function setДраже();
}

class ЛасункаCandyPackageBuilder extends CandyPackageBuilder{
	function setЛьодяники(){
		$this->package->Льодяники = 5;
	}
	
	function setШоколадіЦукерки(){
		$this->package->ШоколадіЦукерки = 3;
	}
	
	function setВафлі(){
		$this->package->Вафлі = 3;
	}
	
	function setДраже(){
		$this->package->Драже = 5;
	}
}

class НаминайкоCandyPackageBuilder extends CandyPackageBuilder{
	function setЛьодяники(){
		$this->package->Льодяники = 5;
	}
	
	function setШоколадіЦукерки(){
		$this->package->ШоколадіЦукерки = 7;
	}
	
	function setВафлі(){
		$this->package->Вафлі = 5;
	}
	
	function setДраже(){
		$this->package->Драже = 7;
	}
}

class ПанКоцькийCandyPackageBuilder extends CandyPackageBuilder{
	function setЛьодяники(){
		$this->package->Льодяники = 7;
	}
	
	function setШоколадіЦукерки(){
		$this->package->ШоколадіЦукерки = 10;
	}
	
	function setВафлі(){
		$this->package->Вафлі = 10;
	}
	
	function setДраже(){
		$this->package->Драже = 10;
	}
}
