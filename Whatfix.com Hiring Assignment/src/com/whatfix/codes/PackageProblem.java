
package com.whatfix.codes;
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

/**
 * @author Vinay
 * //Solution to Problem1: https://www.codeeval.com/public_sc/114/
 */
public class PackageProblem{
	double weightLimit;
	ArrayList<Item> items;
	ArrayList<ArrayList<Item>> combinations;

	public PackageProblem(double l, ArrayList<Item> i){
		weightLimit = l;
		items = i;
		combinations = new ArrayList<ArrayList<Item>>();
	}
	
	//Remove the items with the weight over the weightLimit
	public void filterItems(){
		Iterator<Item> iter = items.iterator();
		while(iter.hasNext()){
			Item i = iter.next();
			if(i.weight > weightLimit)
				iter.remove();
		}
	}
	
	public ArrayList<ArrayList<Item>> createCombinations(){

		for(int x = 0; x < items.size(); x++){
			Item currentItem = items.get(x);
			int combinationSize = combinations.size();
			for(int y = 0; y < combinationSize; y++){
				ArrayList<Item> combination = combinations.get(y);
				ArrayList<Item> newCombination = new ArrayList<Item>(combination);
				newCombination.add(currentItem);
				combinations.add(newCombination);
			}
			ArrayList<Item> current = new ArrayList<Item>();
			current.add(currentItem);
			combinations.add(current);
		}
		return combinations;
	}
	
	public double getWeight(ArrayList<Item> items){
		double total = 0;
		for(Item i : items){
			total += i.weight;
		}
		return total;
	}
	
	public double getPrice(ArrayList<Item> items){
		double total = 0;
		for(Item i : items){
			total += i.price;
		}
		return total;
	}
	
	public ArrayList<Item> getBestPackage(){
		ArrayList<Item> bestCombination = new ArrayList<Item>();
		double bestCost = 0;
		double bestWeight = 100; //Max permissible weight is 100
		for(ArrayList<Item> combination : combinations){
			double combinationWeight = getWeight(combination);
			if(combinationWeight > weightLimit){
				continue;
			}else{
				double combinationPrice = getPrice(combination);
				if(combinationPrice > bestCost){
					bestCost = combinationPrice;
					bestCombination = combination;
					bestWeight = combinationWeight;
				}else if(combinationPrice == bestCost){	
						// use the package with least weight
					if(combinationWeight < bestWeight){
						bestCost = combinationPrice;
						bestCombination = combination;
						bestWeight = combinationWeight;
					}
				}
			}
		}
		return bestCombination;
	}
	
	public void findPackage(){
		filterItems();
		combinations = createCombinations();
		if(combinations.size() == 0){
			System.out.println("-");
		}else{
			ArrayList<Item> bestCombination = getBestPackage();
			Collections.sort(bestCombination);
			printOutput(bestCombination);
		}
	}
	
	public void printOutput(ArrayList<Item> items){
		StringBuilder sb = new StringBuilder();
		boolean isFirst = true;
		for (Item i : items) {
			if(isFirst){
				sb.append(i.id);
				isFirst = false;
			}else{
				sb.append("," + i.id);
			}
		}
		System.out.println(sb);
	}
	
	public static void main(String[] args){
		File file = null;
		if (0 < args.length) {
			   file = new File(args[0]);
			}
		else {
			   System.err.println("Invalid arguments count");
			   System.exit(1);
		}
		try{
			BufferedReader br = new BufferedReader(new FileReader(file));
			String line;
			while((line = br.readLine()) != null){
				if(line.length() == 0)
					continue;
				String[] lineArray = line.split(":");
				double weightweightLimit = Integer.parseInt(lineArray[0].trim());				
				String[] stringItems = lineArray[1].trim().split(" ");
				ArrayList<Item> inputs = new ArrayList<Item>();
				
				for(String stringItem : stringItems){
					String[] itemDetails = stringItem.split(",");
					int id = Integer.parseInt(itemDetails[0].substring(1));
					double weight = Double.parseDouble(itemDetails[1]);
					double price = Double.parseDouble(itemDetails[2].substring(1, itemDetails[2].length()-1));
					Item item = new Item(id, weight, price);
					inputs.add(item);
				}
				
				PackageProblem p = new PackageProblem(weightweightLimit, inputs);
				p.findPackage();
			}
		}catch(IOException e){
			System.out.println(e);
		}
	}
	
	public static class Item implements Comparable<Item>{
		int id;
		double weight, price;
		public Item(int id, double weight, double price){
			this.id = id;
			this.weight = weight;
			this.price = price;
		}
		
		public String toString(){
			return "(" + id + "," + weight + "," + price + ")";
		}
		
		public int compareTo(Item i){
			return this.id - i.id;
		}
	}
}