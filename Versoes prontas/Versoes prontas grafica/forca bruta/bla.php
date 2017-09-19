<?php 
	$query = $_GET['query'];
	$bla = shell_exec("./tp3 -i entrada.txt $query 10");

	echo $bla;
?>
