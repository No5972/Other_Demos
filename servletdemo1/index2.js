$.ajaxSetup({
  contentType: "application/x-www-form-urlencoded; charset=utf-8"
});

var add=function() {
	document.getElementById("output").innerHTML="";
	$.ajax({
		type:"POST",
		url:"/servletdemo/servletdemo21",
		data:
		{
			add1 : document.getElementById("add1").value ,
			add2 : document.getElementById("add2").value
		}, 
		success:function(data,status) {
			document.getElementById("output").innerHTML=data;
		}
	});
};


document.getElementById("submit").onclick=add;