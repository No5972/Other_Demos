<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
    <%@taglib uri="http://www.springframework.org/tags/form" prefix="form"%>
    <jsp:useBean id="command" class="io.github.no5972.springmvc1.Manager" scope="request"></jsp:useBean>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<form:form method="POST" action="updateManager.do">
<form:label path="id">UID: </form:label>
<form:input path="id" value="${ id }" disabled="true" /><br/>
<form:label path="name">Name: </form:label>
<form:input path="name"  value="${ name }" /><br/>
<form:label path="password">Password: </form:label>
<form:password path="password" value="${ password }" /><br/>
<input type="submit" value="Submit"/>
</form:form>
</body>
</html>