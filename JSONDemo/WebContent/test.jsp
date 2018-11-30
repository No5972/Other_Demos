<html>
<head>
<script type="text/javascript" src="http://www.w3school.com.cn/jquery/jquery.js"></script>
<script type="text/javascript">
$(document).ready(function(){
  $("#b01").click(function(){
	  $.ajax({
			url:"http://localhost:8080/JSONDemo/getJSON",
			type : 'post', dataType: "json", 
			success: function (data) {
				console.log(data);
				console.log(data[0].value);
				console.log(data[1].value);
				console.log(data[2].value);
			}
		});
  });
});
</script>
</head>
<body>

<div id="myDiv"><h2>LOAD AJAX</h2></div>
<button id="b01" type="button">LOAD</button>

</body>
</html>
