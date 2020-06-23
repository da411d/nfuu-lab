<?php

class ItemInBox{
	public $id;
	public $quantity;
	public $price;
}


interface Calculator {
    function drawCircle($x, $y, $radius);
}

class DrawingAPI1 implements Calculator {
    public function drawCircle($x, $y, $radius) {
        echo "API1.circle at $x:$y radius $radius.\n";
    }
}

class DrawingAPI2 implements Calculator {
    public function drawCircle($x, $y, $radius) {
        echo "API2.circle at $x:$y radius $radius.\n";
    }
}

abstract class Shape {
    protected $drawingAPI;

    public abstract function draw();
    public abstract function resizeByPercentage($pct);

    protected function __construct(Calculator $drawingAPI) {
        $this->drawingAPI = $drawingAPI;
    }
}

class CircleShape extends Shape {
    private $x;
    private $y;
    private $radius;

    public function __construct($x, $y, $radius, Calculator $drawingAPI) {
        parent::__construct($drawingAPI);
        $this->x = $x;
        $this->y = $y;
        $this->radius = $radius;
    }

    public function draw() {
        $this->drawingAPI->drawCircle($this->x, $this->y, $this->radius);
    }

    public function resizeByPercentage($pct) {
        $this->radius *= $pct;
    }
}

class Tester {
    public static function main()  {
        $shapes = array(
            new CircleShape(1, 3, 7,  new DrawingAPI1()),
            new CircleShape(5, 7, 11, new DrawingAPI2()),
        );

        foreach ($shapes as $shape) {
            $shape->resizeByPercentage(2.5);
            $shape->draw();
        }
    }
}

Tester::main();