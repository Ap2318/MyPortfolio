package manager;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;



import entity.FarmEntity;
import services.DBConnectionService;

public class FarmManager {

	//Queries on entity
			private static String sqlQueryGetAll = "select f.farm_id,f.name_farm ,f.country,fm.name from farm  f join farmer fm where f.farmer_id=fm.farmer_id;";
			private static String sqlQueryGetByCountry = "select f.farm_id,f.name_farm ,f.country,fm.name from farm  f join farmer fm where f.farmer_id=fm.farmer_id and f.country like \"%\"?\"%\" ";
			private static String sqlQueryGetByFarmer = "select f.farm_id, f.name_farm ,f.country,fm.name from farm  f join farmer fm where f.farmer_id=fm.farmer_id and fm.name like \"%\"?\"%\" ";
			
			public static ArrayList<FarmEntity> getAll(){
				ArrayList<FarmEntity> listOfFarms = new ArrayList<FarmEntity>();
				try {
					Statement stmt = DBConnectionService.getStatementObject();
					//ResultSet rs = stmt.executeQuery(sqlQueryGetAll);
					PreparedStatement ps=DBConnectionService.getPreparedStatement(sqlQueryGetAll);
					ResultSet rs = ps.executeQuery(sqlQueryGetAll);
					
					  while(rs.next()) {
						  FarmEntity farm=new FarmEntity( 
								  rs.getInt("farm_id"),
									 rs.getString("name_farm"),
									  rs.getString("country"),
									  rs.getString("name"));
						  
						  //add result to the list to print
						  listOfFarms.add(farm);
						  
					  }
				} catch (SQLException e) {
					
					e.printStackTrace();
				}
				
				return listOfFarms;
			}
			public static ArrayList<FarmEntity> getByCountry(String country){
				ArrayList<FarmEntity> listOfFarms = new ArrayList<FarmEntity>();
				
				PreparedStatement ps = DBConnectionService.getPreparedStatement(sqlQueryGetByCountry);
				try {
					ps.setString(1, country);
					ResultSet rs = ps.executeQuery();
					
					 while(rs.next()) {
						 FarmEntity farm=new FarmEntity( 
								  rs.getInt("farm_id"),
									 rs.getString("name_farm"),
									  rs.getString("country"),
									  rs.getString("name"));
						  
						 listOfFarms.add(farm);
						  
					  }
				} catch (SQLException e) {
					
					e.printStackTrace();
				}
				
				return listOfFarms;
			}
			
			public static ArrayList<FarmEntity> getByFarmer(String farmer){
				ArrayList<FarmEntity> listOfFarms = new ArrayList<FarmEntity>();
				
				PreparedStatement ps = DBConnectionService.getPreparedStatement(sqlQueryGetByFarmer);
				try {
					ps.setString(1, farmer);
					ResultSet rs = ps.executeQuery();
					
					 while(rs.next()) {
						 FarmEntity farm=new FarmEntity( 
								  rs.getInt("farm_id"),
									 rs.getString("name_farm"),
									  rs.getString("country"),
									  rs.getString("name"));
						 listOfFarms.add(farm);
						  
					  }
				} catch (SQLException e) {
					
					e.printStackTrace();
				}
				
				return listOfFarms;
			}
		
		
	
	
}
