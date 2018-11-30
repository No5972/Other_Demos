<html>
<head>
<script type="text/javascript"
	src="http://www.w3school.com.cn/jquery/jquery.js"></script>
<script type="text/javascript">
	function arrayToTable(newarray) {
		var tbody = "";
		var head = "";
		for (var i = 0; i < newarray.length; i++) {
			if (head == "") {
				for ( var key in newarray[i]) {
					head += "<th>" + key + "</th>";
				}
				head = "<tr>" + head + "</tr>";
			}
			var tds = "";
			for ( var key in newarray[i]) {
				tds += "<td>" + newarray[i][key] + "</td>";
			}
			tbody += "<tr>" + tds + "</tr>"
		}
		return "<table>" + head + tbody + "</table>";
	}
	$(document).ready(function() {
		$("#b01").click(function() {
			$.ajax({
				url : "http://localhost:8080/JSONDemo/getJSON",
				type : 'post',
				dataType : "json",
				success : function(data) {
					console.log(data);
					console.log(data[0].value);
					console.log(data[1].value);
					console.log(data[2].value);
					document.write(arrayToTable(data));
				}
			});
		});
	});
</script>
</head>
<body>

	<div id="myDiv">
		<h2>LOAD AJAX</h2>
	</div>
	<button id="b01" type="button">LOAD</button>

</body>
</html>
