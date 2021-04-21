package entity;

public class FarmEntity {

	private int farm_Id;
	private String name_farm;
	private String country;
	private String farmerName;
	
	public FarmEntity() {
		
	}
	
public FarmEntity(int farm_id,String name_farm,String country,String farmerName) {
	super();
	this.farm_Id=farm_id;
	this.name_farm=name_farm;
	this.country=country;
	this.farmerName=farmerName;
	}

public int getFarm_Id() {
	return farm_Id;
}

public void setFarm_Id(int farm_Id) {
	this.farm_Id = farm_Id;
}

public String getName_farm() {
	return name_farm;
}

public void setName_farm(String name_farm) {
	this.name_farm = name_farm;
}

public String getCountry() {
	return country;
}

public void setCountry(String country) {
	this.country = country;
}

public String getName() {
	return farmerName;
}

public void setName(String name_farm) {
	this.farmerName = farmerName;
}

}
