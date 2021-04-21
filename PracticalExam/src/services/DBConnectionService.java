package services;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;



public class DBConnectionService {

	private final static String databaseName = "farm_bd";
	private static String urlConnection = "jdbc:mysql://localhost:3306/"+databaseName;
	private final static String login = "root";
	private final static String pswd = "root";
	private static Connection dbConnection = null;
	
	
	public static Connection getDbConnection() throws ClassNotFoundException, SQLException {
		if(dbConnection == null) {
			Class.forName("com.mysql.cj.jdbc.Driver");
			dbConnection = DriverManager.getConnection(urlConnection, login, pswd);
		}
		return dbConnection;
	}
	
	public static Statement getStatementObject() {
		boolean  statusError = false;
		Statement stmt = null;
		try {
			 stmt = getDbConnection().createStatement();
		} catch (ClassNotFoundException | SQLException e) {
			e.printStackTrace();
			statusError = true;
		}finally {
			if(dbConnection != null && statusError)
				DBConnectionService.close();
		}
		return stmt;
	}
	
	public static PreparedStatement getPreparedStatement(String sqlQuery) {
		boolean  statusError = false;
		PreparedStatement ps = null;
		
		try {
			 ps = getDbConnection().prepareStatement(sqlQuery);
		} catch (ClassNotFoundException | SQLException e) {
			
			e.printStackTrace();
			statusError = true;
		} finally {
			if(dbConnection != null && statusError)
				DBConnectionService.close();
		}
		
		return ps;
	}
	
	
	public static void close() {
		try {
			getDbConnection().close();
		} catch (ClassNotFoundException | SQLException e) {
			e.printStackTrace();
		}
	}
}
