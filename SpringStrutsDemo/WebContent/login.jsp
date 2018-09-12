<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ taglib prefix="s" uri="/struts-tags" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>登录</title>
</head>
<body>
<script type="text/javascript">
var onSubmit = function() {
	document.myform.submit();
}
</script>
<center>
<h1>登录</h1><hr/><br/>
<form action="login.action" method="post" name="myform">
用户名：<input type="text" name="username"/><br/>
密　码：<input type="password" name="password"/><br/>
<input type="submit" value="登录"/>
</form>
</center>
</body>
</html>