<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<style>td { border: 1px solid #000; }</style>
<?php
header("Content-type: text/html;charset=utf-8");
$con = mysql_connect("localhost:3306","root","root");
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }

mysql_select_db("audiocms", $con);

mysql_query("set names utf8");
$result = mysql_query("SELECT * FROM news");

echo "<table cellspacing=\"0\"><thead><tr><td>编号</td><td>标题</td></tr></thead>";
while($row = mysql_fetch_array($result))
{
	echo "<tr><td>" . $row['id'] . "</td><td><a href=\"mysql2.php?id=" . $row['id'] . "\">" . $row['title'] . "</a></td>";
	echo "</tr>";
}
echo "</table>";

mysql_close($con);
?>