/**
 * 
 */
package entity;

import java.math.BigDecimal;

/**
 * @author apatel4
 *
 */
public class AnimalEntity {

	private int animal_id;
	private String name;
	private BigDecimal price; 
	private String type;
	
	public AnimalEntity() {
		
	}
	
	public AnimalEntity(int animalId,String animalName, BigDecimal animalPrice,String animalType) {
		this.animal_id=animalId;
		this.name=animalName;
		this.price=animalPrice;
		this.type=animalType;
	}
	
	public int getAnimal_id() {
		return animal_id;
	}
	
	public void setAnimal_id(int animal_id) {
		this.animal_id = animal_id;
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public BigDecimal getPrice() {
		return price;
	}
	
	public void setPrice(BigDecimal price) {
		this.price = price;
	}
	
	public String getType() {
		return type;
	}
	
	public void setType(String type) {
		this.type = type;
	}
}
