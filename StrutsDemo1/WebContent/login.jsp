<%@ page language="java" import="java.util.*" pageEncoding="gbk" %>
<%@taglib prefix="s" uri="/struts-tags" %>
<s:form action="login" method="POST" namespace="/">
	<s:textfield name="username" label="Username: " cssstyle="width: 160px; height: 26px;"/>
	<s:password name="password" label="Password: " cssstyle="width: 160px; height: 26px;"/>
	<s:submit value="Login"/>
</s:form>