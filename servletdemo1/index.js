$.ajaxSetup({
  contentType: "application/x-www-form-urlencoded; charset=utf-8"
});

var add=function() {
	document.getElementById("output").innerHTML="";
	$.post("/servletdemo/servletdemo2"+
		"?add1="+document.getElementById("add1").value+
		"&add2="+document.getElementById("add2").value+
		"&f=0"
		, function(data,status) {
			document.getElementById("output").innerHTML=data;
		},"");
};


document.getElementById("submit").onclick=add;