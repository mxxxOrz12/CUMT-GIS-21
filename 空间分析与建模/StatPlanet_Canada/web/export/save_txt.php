<?php
	header('Content-type: text/plain; charset=utf-8');
	header('Content-disposition: attachment; filename="StatPlanet_data.txt"');
	$csvData = ($_POST['csvdata']) ? $_POST['csvdata'] : $_GET['csvdata'];
	$unicode_str_for_Excel = chr(255).chr(254).mb_convert_encoding( $csvData, 'UTF-16LE', 'UTF-8');
	echo  $unicode_str_for_Excel;
?>

