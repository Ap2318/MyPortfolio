package action;

import java.util.ArrayList;

import entity.FarmEntity;
import manager.FarmManager;


public class FarmAction {

	public static ArrayList<FarmEntity> getListOfAllFarm(){
		return FarmManager.getAll();
	}

	public static ArrayList<FarmEntity> getListByCountry(String countrySearch) {
		// TODO Auto-generated method stub
		return FarmManager.getByCountry(countrySearch);
	}

	public static ArrayList<FarmEntity> getListByFarmer(String farmerSearch) {
		// TODO Auto-generated method stub
		return FarmManager.getByFarmer(farmerSearch);
	}

}
