$.ajaxSetup({
  contentType: "application/x-www-form-urlencoded; charset=utf-8"
});

var add=function() {
	document.getElementById("output").innerHTML="";
	$.ajax({
		type:"POST",
		url:"/servletdemo3/servletdemo3",
		data: "add1="+encodeURI(encodeURI(document.getElementById("add1").value))+"&add2="+encodeURI(encodeURI(document.getElementById("add2").value)), 
		success:function(data,status) {
			document.getElementById("output").innerHTML=data;
		}
	});
};


document.getElementById("submit").onclick=add;