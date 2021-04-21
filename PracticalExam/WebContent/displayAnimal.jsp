<%@page import="entity.AnimalEntity"%>
<%@page import="java.util.ArrayList"%>

<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Animal List</title>
</head>
<body>

<table border=1>
<tr>
	<th>AnimalID</th>
	<th>AnimalName</th>
	<th>AnimalPrice</th>
	<th>AnimalType</th>
	</tr>
	<% ArrayList<AnimalEntity> list = (ArrayList<AnimalEntity>) request.getAttribute("animalList");
 		 if (list != null && list.size() > 0){%>
 		  <%for(AnimalEntity a :list){
		%>	
	<tr>
	 <td><%=a.getAnimal_id()%></td>
	 <td><%=a.getName()%></td>
	 <td><%=a.getPrice()%></td>
	 <td><%=a.getType()%></td>
	 </tr>
	 <% }
	 %>
	</table>
 	 
 	 
 	 
 	
	
		<a  href="DisplayServlet"type="submit" value="">Display Farms</a>
		
 	 
 	 <%  }
 		 else { %>
<h2>No Data found for this request</h2>
<%}%>


</body>
</html>