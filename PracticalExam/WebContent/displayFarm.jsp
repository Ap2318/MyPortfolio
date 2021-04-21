
<%@page import="entity.FarmEntity"%>
<%@page import="java.util.ArrayList"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Farm List</title>
</head>
<body>

		<%
		ArrayList<FarmEntity> list=new ArrayList<FarmEntity>();
		list=(ArrayList<FarmEntity>) request.getAttribute("myFarmList");

		%>
		
		
		<div>
		<form action="DisplayServlet" method="get">
		<label>Filter By Country:</label></br>
<select name="country" id="country">
    <%
	for(FarmEntity f :list)
	{	
	%>	
	<option value="<%=f.getCountry() %>"><%=f.getCountry() %></option>
	<%} %>
<input type="submit" value="Display">
</form></div>

<div>
<form action="DisplayServlet" method="get">
<label>Filter By Farmer:</label></br>
<select name="farmer" id="farmer">
    <%
	for(FarmEntity f :list)
	{	
	%>	
	<option value="<%=f.getName() %>"><%=f.getName() %></option>
	<%} %>
<input type="submit" value="Display">
</form></div>

<div>
		<form action="DisplayServlet" method="get">
		<label>Display All</label></br>
		<input type="submit" value="Display">
		</form>
		</div>


 		 <h1>List Of Farm</h1>
 		 <table border=1>
		<tr>
		<th>Farm Name</th>
		<th>Country</th>
		<th>Farmer Name</th>
		<th>List Animals</th>
		</tr>
 		 

	<%
	for(FarmEntity f :list)
	{	
	%>	

     <tr>			
	 <td><%=f.getName_farm() %></td>
	 <td><%=f.getCountry() %></td>
	  <td><%=f.getName() %></td>
	  <td><a href="AnimalServlet?farmId=<%= f.getFarm_Id() %>">Display Animals</a>
</td>	
	  </tr>	
	<%} %>
	</table>

			
</body>
</html>