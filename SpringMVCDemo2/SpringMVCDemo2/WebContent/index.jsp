<%@taglib uri="http://www.springframework.org/tags/form" prefix="form"%>
<jsp:useBean id="command" class="io.github.no5972.springmvc1.Numbers" scope="request"></jsp:useBean>
<html>
<head>
    <title>Spring MVC Form Handling</title>
</head>
<body>

<h2>SpringMVC Adders</h2>
<form:form method="POST" action="add.do">
   <table>
    <tr>
        <td><form:label path="add1">Add1: </form:label></td>
        <td><form:input path="add1" /></td>
    </tr>
    <tr>
        <td><form:label path="add2">Add2: </form:label></td>
        <td><form:input path="add2" /></td>
    </tr>
    <tr>
        <td colspan="2">
            <input type="submit" value="Submit"/>
        </td>
    </tr>
</table>  
</form:form>
<form:form method="POST" action="times.do">
   <table>
    <tr>
        <td><form:label path="add1">Factor1: </form:label></td>
        <td><form:input path="add1" /></td>
    </tr>
    <tr>
        <td><form:label path="add2">Factor2: </form:label></td>
        <td><form:input path="add2" /></td>
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