<?php
//
// main.php
// Volume0_0090
//
// Created by slangsoft on 2015/01/23.
// Copyright (c) 2015 Slang Software. All rights reserved.
//

define( EOSTDIN , "0" );
define( NUM_DIST, 2   );

$strStdin   = "";
$maxN       = 0;        // number of datasets from stdin
$arrDataset = array();
$ans        = 1;
$wkAns      = 1;

// read number of datasets from stdin
while( $strStdin != EOSTDIN ) {
    $strStdin = trim( fgets( STDIN ) );
    list( $x, $y, $dummy ) = explode( ",", $strStdin, 3 );
    $arrDataset[] = array( "x" => floatval( $x ), "y" => floatval( $y ) );
}

// get the number of datasets
$maxN = $arrDataset[0]["x"];

// remove the first element from the array
array_splice( $arrDataset, 0, 1 );

// remove the last element from the array
array_pop( $arrDataset );
reset( $arrDataset );

if( 0 < $maxN ) {
    for($i = 0; $i <= $maxN - 2; $i++ ) {
        $wkAns = 1;
        for( $j = $i + 1; $j <= $maxN - 1; $j++ ) {
            $dist = new dist();
            $dist->setCenterPointA( $arrDataset[$i]["x"], $arrDataset[$i]["y"] );
            $dist->setCenterPointB( $arrDataset[$j]["x"], $arrDataset[$j]["y"] );
            if( NUM_DIST >= $dist->getDist() ) {
                $wkAns++;
            }
        }
        if( $wkAns > $ans ) {
            $ans = $wkAns;
        }
    }
} else {
    $ans = 0;
}

// output answer to stdout
fwrite( STDOUT, "Ans:" . $ans . PHP_EOL );

class dist {
    private $a, $b;
    private $x1, $x2, $y1, $y2;
    private $dist;

    public function getDist() {
        $this->x1 > $this->x2 ? $this->a = $this->x1 - $this->x2 : $this->a = $this->x2 - $this->x1;
        $this->y1 > $this->y2 ? $this->b = $this->y1 - $this->y2 : $this->b = $this->y2 - $this->y1;
        $this->dist = sqrt( pow( $this->a, 2 ) + pow( $this->b, 2 ) );
        return $this->dist;
        
    }
    public function setCenterPointA( $x, $y ) {
        $this->x1 = $x;
        $this->y1 = $y;
    }
    public function setCenterPointB( $x, $y ) {
        $this->x2 = $x;
        $this->y2 = $y;
    }
}
?>