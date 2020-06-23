<?php
class ArraySorter {
	private static $instance;
	
	protected function __construct(){
		
	}
	
	static function instance(){
		if(!self::$instance){
			self::$instance = new ArraySorter();
		}
		
		return self::$instance;
	}
	
	public function bubble($array = []){
		do{
			$swapped = false;
			for($i = 0; $i < count($array) - 1; $i++ ){
				if($array[$i] > $array[$i + 1] ){
					list($array[$i + 1], $array[$i]) = [$array[$i], $array[$i + 1]];
					$swapped = true;
				}
			}
		}while($swapped);
		return $array;
	}
	
	public function shell($array = []){
		$x = round(count($array) / 2);
		while($x > 0){
			for($i = $x; $i < count($array); $i++){
				$temp = $array[$i];
				$j = $i;
				while($j >= $x && $array[$j-$x] > $temp){
					$array[$j] = $array[$j - $x];
					$j -= $x;
				}
				$array[$j] = $temp;
			}
			$x = round($x / 2.2);
		}
		return $array;
	}
	
	public function quick($array = []){
		$loe = $gt = [];
		if(count($array) < 2){
			return $array;
		}
		$pivot_key = key($array);
		$pivot = array_shift($array);
		foreach($array as $val){
			if($val <= $pivot){
				$loe[] = $val;
			}elseif ($val > $pivot){
				$gt[] = $val;
			}
		}
		
		return array_merge($this->quick($loe), [$pivot_key => $pivot], $this->quick($gt));
	}
}
