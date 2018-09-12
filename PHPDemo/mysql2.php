<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<?php
header("Content-type: text/html;charset=utf-8");
$con = mysql_connect("localhost:3306","root","root");
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }

mysql_select_db("audiocms", $con);

mysql_query("set names utf8");
echo "SELECT title,content FROM news WHERE id=" . $_GET["id"] . "<br>";
$result = mysql_query("SELECT title,content FROM news WHERE id=" . $_GET["id"]);

while($row = mysql_fetch_array($result))
{
	echo "标题：" . $row['title'] . "<br/>内容：" . $row['content'];
}

mysql_close($con);
?>