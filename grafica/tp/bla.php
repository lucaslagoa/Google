<?php 
	$query = $_GET['query'];
	$bla = shell_exec("./hw $query");
	echo $bla;
?>