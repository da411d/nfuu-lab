<?php
function myErrorHandler($errno, $errstr, $errfile, $errline){
    if($errno == E_USER_ERROR){
        echo "Сталося неперехоплюване виключення";
        exit(1);
    }
	return false;
}

set_error_handler("myErrorHandler");

trigger_error("Fatal error", E_USER_ERROR);
?>