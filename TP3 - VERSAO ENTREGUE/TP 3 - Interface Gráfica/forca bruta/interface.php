<?php 
	$query = $_GET['query'];
	$interface = shell_exec("./tp3 -i entrada.txt $query 6");

	echo $interface;
?>
