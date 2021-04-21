package action;

import java.util.ArrayList;

import entity.AnimalEntity;
import entity.FarmEntity;
import manager.AnimalManager;


public class AnimalAction {

	public static ArrayList<AnimalEntity> getListOfAllAnimal(String id){
		return AnimalManager.getAll(id);
	}
	
}
