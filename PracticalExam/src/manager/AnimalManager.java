package manager;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import entity.AnimalEntity;
import entity.FarmEntity;
import services.DBConnectionService;

public class AnimalManager {

	
	//Queries on entity
			private static String sqlQueryGetAll = "select * from animal where farm_id=?;";
			//private static String sqlQueryGetByLastName = "select * from student where lastName like \"%\"?\"%\" ";
			
			
			public static ArrayList<AnimalEntity> getAll(String farmId){
				ArrayList<AnimalEntity> listOfAnimals = new ArrayList<AnimalEntity>();
				PreparedStatement ps = DBConnectionService.getPreparedStatement(sqlQueryGetAll);
				int id=Integer.parseInt(farmId);
				try {
					ps.setInt(1, id);
					ResultSet rs = ps.executeQuery();
					
					  while(rs.next()) {
						  AnimalEntity animal = new AnimalEntity(
								  rs.getInt("animal_id"),
								  rs.getString("name"),
								  rs.getBigDecimal("price"),
								  rs.getString("type"));
						  
						  //add result to the list to print
						  listOfAnimals.add(animal);
						  
					  }
				} catch (SQLException e) {
					
					e.printStackTrace();
				}
				
				return listOfAnimals;
			}
	
}
