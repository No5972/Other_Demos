<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@taglib uri="http://www.springframework.org/tags/form" prefix="form"%>
    <%@ taglib prefix="c" 
           uri="http://java.sun.com/jsp/jstl/core" %>
<jsp:useBean id="command" class="io.github.no5972.springmvc1.Manager" scope="request"></jsp:useBean>
    
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<form:form method="POST" action="insertManager.do">
<form:label path="account">Account: </form:label>
<form:input path="account" /><br/>
<form:label path="name">Name: </form:label>
<form:input path="name" /><br/>
<form:label path="password">Password: </form:label>
<form:password path="password" /><br/>
<input type="submit" value="Add"/>
</form:form>
<table>
<thead>
	<tr><td>UID</td><td>Account</td><td>Name</td><td>Numbers</td><td>Operations</td></tr>
</thead>
<c:forEach items="${list}" var="item" >
    <tr>
	    <td>${ item.id }</td>
	    <td>${ item.account }</td>
	    <td>${ item.name }</td>
	    <td>${ item.number }</td>
	    <td>
	    	<a href="removeManager.do?id=${ item.id }">Delete</a>
	    	<a href="updatingManager.do?id=${ item.id }">Modify</a>
	    </td>
    </tr>
</c:forEach>
</table>
</body>
</html>