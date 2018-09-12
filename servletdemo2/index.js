$.ajaxSetup({
  contentType: "application/x-www-form-urlencoded; charset=utf-8"
});

var add=function() {
	document.getElementById("result1").value="";
	document.getElementById("result2").value="";
	document.getElementById("result3").value="";
	$.ajax({
		type:"POST",
		url:"/servletdemo2/servletdemo2",
		data:
		{
			add1 : document.getElementById("add1").value ,
			add2 : document.getElementById("add2").value
		}, 
		success:function(data,status) {
			var results=JSON.parse(data);
			document.getElementById("result1").value=results.result1;
			document.getElementById("result2").value=results.result2;
			document.getElementById("result3").value=results.result3;
		}
	});
};


document.getElementById("submit").onclick=add;