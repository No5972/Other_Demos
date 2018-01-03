﻿<%@page import="java.sql.Connection"%><%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.sql.*"%><% 
	Connection conn;
	Statement stmt;
	int success=-1;
	//get driver
	try {
		Class.forName("com.mysql.jdbc.Driver");
		System.out.println("driver success");
	} catch (ClassNotFoundException e) {
		System.out.println("driver fail");
		e.printStackTrace();
	}
	//connect
	conn=DriverManager.getConnection("jdbc:mysql://localhost:3306/DBSP", "root", "*********");
	try {
		
		stmt=conn.createStatement();
		System.out.println("connection success");
	} catch (SQLException e) {
		System.out.println("driver fail");
		e.printStackTrace();
	}
	//insert
	try {
		String command="insert into sc values(?,?,?)";
		PreparedStatement ps=conn.prepareStatement(command);
		ps.setString(1, request.getParameter("a_sno"));
		ps.setString(2, request.getParameter("a_cno"));
		ps.setFloat(3, Float.parseFloat(request.getParameter("a_grade")));
		success=ps.executeUpdate();
	} catch (Exception e) {
		System.out.println("add grade fail");
		e.printStackTrace();
	} finally {
		try {
			conn.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	if (success==1) out.print("添加成功"); else out.print("添加失败");
%>