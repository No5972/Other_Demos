<%@taglib uri="http://www.springframework.org/tags/form" prefix="form"%>
<jsp:useBean id="command" class="io.github.no5972.springmvc1.Users" scope="request"></jsp:useBean>
<html>
<head>
    <title>Spring MVC Form Handling</title>
</head>
<body>

<h2>SpringMVC Login</h2><form:form method="POST" action="login.do">
   <table>
    <tr>
        <td><form:label path="username">Username: </form:label></td>
        <td><form:input path="username" /></td>
    </tr>
    <tr>
        <td><form:label path="password">Password: </form:label></td>
        <td><form:password path="password" /></td>
    </tr>
    <tr>
        <td colspan="2">
            <input type="submit" value="Submit"/>
        </td>
    </tr>
</table>  
</form:form>
</body>
</html>