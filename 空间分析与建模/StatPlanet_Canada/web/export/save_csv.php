<?php
	header('Content-Encoding: UTF-8');
	header('Content-type: text/csv; charset=UTF-8');
	header('Content-disposition: attachment; filename="StatPlanet_data.csv"');
	$csvData = ($_POST['csvdata']) ? $_POST['csvdata'] : $_GET['csvdata'];
	echo "\xEF\xBB\xBF";
	echo  $csvData;
?>